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
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}

void push()
{
    NODE temp;
    int credit;
    temp=getnode();
    printf("Enter the Subject name: ");
    scanf("%s",temp->sub);
    printf("Enter the marks scored: ");
    scanf("%d",&temp->mark);
    temp->off10=(temp->mark/3);
    printf("Enter the credit of %s: ",temp->sub);
    scanf("%d",&credit);
    temp->grade=temp->off10*credit;
    if(head==NULL)
    {
        temp->next=NULL;
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }

}



//main fun()
void main(){
     
}
