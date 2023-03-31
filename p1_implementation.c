#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int coef ; 
    int order ; 
    struct node *next ; 
};
struct node *create(struct node *poly,int max_order)
{
    struct node *temp , *newnode ; 
    while(max_order>=0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter coef of order %d : ",max_order);
        scanf("%d",&newnode->coef); 
        newnode->order = max_order ;
        newnode->next = NULL;
        if (poly == NULL)
        {
            poly = temp = newnode ; 
        } 
        else
        {
            temp->next = newnode ; 
            temp = newnode ; 
        }
        max_order-- ; 
    }
    return(poly);
}
void display(struct node *poly)
{
    struct node *temp = poly ; 
    while(temp!=NULL)
    {
    if(temp->next == 0)
    {
        printf("%d = 0",poly->coef);
    }
    else
    {
        printf("%dx^%d + ",temp->coef,temp->order);
    }
    temp = temp->next ; 
    }
}
int main()
{
struct node *poly = NULL ; 
int max_order ; 
printf("Enter order of poly : ");
scanf("%d",&max_order);
poly = create(poly,max_order);
display(poly);
return 0;
}