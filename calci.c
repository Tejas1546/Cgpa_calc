#include<stdio.h>
#include<cmath>
#include<iomanip>
struct node
{
    int mark,grade,off10;
    char sub[30];
    struct node *next;
};
struct node *head;

void gd()
{
    struct node *temp,*ptr;
    ptr=(struct node*)malloc(sizeof(struct node*));
    int credit;
    temp=getnode();
    printf("Enter the Subject name: ");
    scanf("%s",ptr->sub);
    printf("Enter the marks scored: ");
    scanf("%d",&ptr->mark);
    ptr->off10=(ptr->mark/3);
    printf("Enter the credit of %s: ",ptr->sub);
    scanf("%d",&credit);
    ptr->grade=ptr->off10*credit;
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






//main fun()
void main(){
     
}
