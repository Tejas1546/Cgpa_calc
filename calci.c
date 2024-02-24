#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
{
    int mark,grade,off10,credit;
    char sub[30];
    struct node *next;
};
struct node *head=NULL;

void gd()
{
    struct node *temp,*ptr;
    ptr=(struct node*)malloc(sizeof(struct node*));
    printf("Enter the Subject name: ");
    scanf("%s",ptr->sub);
    printf("Enter the marks scored: ");
    scanf("%d",&ptr->mark);
    ptr->off10=((ptr->mark)/3);
    printf("Enter the credit of %s: ",ptr->sub);
    scanf("%d",&ptr->credit);
    ptr->grade=ptr->off10*ptr->credit;
    if(head == NULL)
    {
        ptr -> next = NULL;  
        head = ptr;
    }
    else
    {
        temp=head; 
        while(temp->next!=NULL)
        temp = temp -> next;
        temp->next = ptr;
        ptr->next = NULL;
    }
}

float compute()
{
    struct node *ptr=head;
    int s=0,t=0;
    if(ptr==NULL)
    printf("No subs found");
    else
    {
        while(ptr!=NULL)
        {
            s+=ptr->grade;
            t+=ptr->credit;
            ptr=ptr->next;
        }
        return (s/t);
    }
}

void display()
{
    struct node *ptr=head;
    int i=0;
    while(ptr!=NULL)
    {
        printf("Subject %d\n",i);
        printf("Subject name = %s\n",ptr->sub);
        printf("Marks = %d\n",ptr->mark);
        printf("Grade out of 10 = %d\n",ptr->off10);
        ptr=ptr->next;
        i++;
    }
    printf("CGPA = %f",compute());
}


//main fun()
void main(){
    int n;
    printf("Enter the number of subs: ");
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {gd();}
    display();
}
