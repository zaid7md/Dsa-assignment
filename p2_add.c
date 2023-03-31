#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int coef  ;  
    int max_order ; 
    struct node *next ; 
};
struct node *create (struct node *poly,int order)
{
    struct node *temp , *new ; 
    while(order>=0)
    {
        new = (struct node*)malloc(sizeof(struct node));
        new->max_order = order ; 
        printf("Enter coef of %d order : ",order);
        scanf("%d",&new->coef);
        new->next = NULL ; 
        if(poly == 0)
        {
            poly = temp = new ; 
        }
        else
        {
            temp->next = new ; 
            temp = new ; 
        }
        order-- ; 
    }
    return(poly);
}
void display(struct node* poly)
{
    struct node*temp = poly ; 
    while(temp!=NULL)
    {
        if(temp->next ==NULL)
        {
            printf("%d = 0",temp->coef);
        }
        else
        {
            printf("%dx^%d + ",temp->coef,temp->max_order);
        }
        temp = temp->next ; 
    }
    printf("\n");
}
struct node *add(struct node *poly1 , struct node *poly2)
{
    struct node *t1 = poly1 , *t2 = poly2 , *t3 , *poly3 = NULL ; 
    struct node *new ; 
    while(t1 != NULL && t2 != NULL)
    {
        new = (struct node*)malloc(sizeof(struct node));
        new->next = NULL ;
        if(t1->max_order > t2->max_order)
        {
            new->coef = t1->coef ; 
            new->max_order = t1->max_order ; 
             
            if(poly3 == 0)
            {
                poly3 = t3 = new ; 
            }
            else
            {
                t3->next = new ; 
                t3 = new ; 
            }
            t1 = t1->next ; 
        }
        else if (t2->max_order > t1->max_order)
        {
            new->coef = t2->coef ; 
            new->max_order = t2->max_order ; 

            if(poly3 == NULL)
            {
                poly3 = t3 = new ; 
            }
            else
            {
                t3->next = new ; 
                t3 = new; 
            }
            t2 = t2->next ; 
        }
        else
        {
            new->coef = t1->coef + t2->coef ; 
            new->max_order = t1->max_order ; 
            if(poly3 == NULL)
            {
                poly3 = t3 = new ; 
            }
            else
            {
                t3->next = new ; 
                t3 = new ; 
            }
            t1 = t1->next ; 
            t2 = t2->next ; 
               
        }
        
    }
    return(poly3);
}
int main()
{
struct node *poly1 = 0 , *poly2 = 0 ; 
int order1 , order2 ; 

printf("Enter the order of poly1 : ");
scanf("%d",&order1);
poly1 = create(poly1,order1);
display(poly1);

printf("Enter the order of poly2 : ");
scanf("%d",&order2);
poly2 = create(poly2,order2);
display(poly2);

struct node *poly3 ; 
poly3 = add(poly1,poly2);
printf("Sum\n");
display(poly3);

return 0;
}