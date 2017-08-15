#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *link;
}*head=NULL;
void insert_at_beg();
void insert_at_end();
void del_at_beg();
void print();
int main()
{
    int select,x=1;
    while(x!=0){
    printf("choose one of the options\n1.insert at beg\n2.insert at end\n3.delete at beg\n4.exit\n:");
    scanf("%d",&select);
    switch (select)
    {
    case 1:
        insert_at_beg();
        print();
        break;
    case 2:
        insert_at_end();
        print();
        break;
    case 3:
        del_at_beg();
        print();
        break;
    case 4:
        x=0;
        break;
    default:
        printf("\aselect a valid option\n");
        break;
    }}
}
void insert_at_beg()
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    int scan_no;
    printf("enter a value to be inserted:");
    scanf("%d",&scan_no);
    new_node->value=scan_no;
    new_node->link=NULL;
    if(head==NULL)
    {
        new_node->link=NULL;
        head=new_node;
    }
    else
    {
        new_node->link=head;
        head=new_node;
    }
}
void insert_at_end()
{
    struct node *new_node,*p;
    new_node=(struct node*)malloc(sizeof(struct node));
    int scan_no;
    printf("enter a value to be inserted:");
    scanf("%d",&scan_no);
    new_node->value=scan_no;
    if(head==NULL)
    {
        head=new_node;
        new_node->link=NULL;
    }
    else
    {
        while(p->link!=NULL)
        {
            p=p->link;
        }
        new_node->link=NULL;
        p->link=new_node;
    }
}
void del_at_beg()
{
    if(head != NULL)
    {
       // store the old value of head pointer    
       struct node *temp = head;
        
       // Change head pointer to point to next node 
       head = head->link; 
 
       // delete memory allocated for the previous head node
       free(temp);
    }
}
void print()
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("---->%d",ptr->value);
        ptr=ptr->link;
    }
    printf("\n");
}