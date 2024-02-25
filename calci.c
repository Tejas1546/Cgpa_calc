#include<stdio.h>
#include<stdlib.h>

struct node {
    int mark, grade_points, credit;
    char sub[30];
    struct node *next;
};

struct node *head = NULL;

void gd() {
    struct node *temp, *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Subject name: ");
    scanf("%s", ptr->sub);
    printf("Enter the marks scored: ");
    scanf("%d", &ptr->mark);
    printf("Enter the credit of %s: ", ptr->sub);
    scanf("%d", &ptr->credit);
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

int calculate_grade_points(int marks) {
    if (marks >= 90)
        return 10;
    else if (marks >= 80)
        return 9;
    else if (marks >= 70)
        return 8;
    else if (marks >= 60)
        return 7;
    else if (marks >= 50)
        return 6;
    else
        return 0; // failing grade
}

float compute() {
    struct node *ptr = head;
    int total_grade_points = 0, total_credits = 0;
    float cgpa;
    if (ptr == NULL)
        printf("No subjects found");
    else {
        while (ptr != NULL) {
            // Calculate Grade Points for each subject based on marks
            ptr->grade_points = calculate_grade_points(ptr->mark) * ptr->credit;

            // Update Total Grade Points and Total Credits
            total_grade_points += ptr->grade_points;
            total_credits += ptr->credit;

            ptr = ptr->next;
        }
        // Calculate CGPA
        cgpa = (float)total_grade_points / total_credits;
        return cgpa;
    }
}

void display() {
    struct node *ptr = head;
    int i = 1;
    while (ptr != NULL) {
        printf("Subject %d\n", i);
        printf("Subject name = %s\n", ptr->sub);
        printf("Marks = %d\n", ptr->mark);
        printf("Credit = %d\n\n", ptr->credit);
        ptr = ptr->next;
        i++;
    }
}

int main() {
    int n;
    printf("Enter the number of subjects: ");
    scanf("%d", &n);
    printf("Enter details for %d subjects:\n", n);
    for (int j = 0; j < n; j++) {
        gd();
    }
    printf("\nDetails of all subjects:\n");
    display();
    printf("\nCGPA = %.2f", compute());
    return 0;
}
