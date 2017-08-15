#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *right_link;
    struct node *left_link;
};
struct node* create_node()
{
    struct node *new_node;
    int x;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("enter the value");
    scanf("%d",&x);
    new_node->value=x;
    new_node->left_link=NULL;
    new_node->right_link=NULL;
}
struct node* bst()
{
    struct node *node1=create_node();
    
}