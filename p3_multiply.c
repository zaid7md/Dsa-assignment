#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int coef ; 
    int order ; 
    struct node *next ; 
};
void display(struct node *poly)
{
    struct node *temp = poly ; 
    while(temp != 0)
    {
        if(temp->next == 0 )
        {
            printf("%d = 0",temp->coef);
        }
        else
        {
            printf("%dx^%d + ",temp->coef,temp->order);
        }
        temp = temp->next ; 
    }
    printf("\n");
}
struct node * ins_end(struct node *poly , int a , int b)
{
        struct node *new = malloc (sizeof(struct node));
        new->coef = a; 
        new->order = b ; 
        new->next = NULL; 
        struct node* temp = poly ;  
        if(poly == NULL || b > poly->order)
        {
            new->next = poly ; 
            poly = new ;  
        }
        else
        {
            while(temp->next != NULL && temp->next->order >= b)
            {
                temp = temp->next ; 
            }
            new->next = temp->next ; 
            temp->next = new ; 
        }
        return(poly);
}
struct node *create(struct node *poly,int o)
{
    struct node *temp , *newnode ; 
    while(o>=0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter coef of order %d : ",o);
        scanf("%d",&newnode->coef); 
        newnode->order = o ;
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
        o-- ; 
    }
    return(poly);
}
struct node * multiply(struct node *poly1 , struct node *poly2)
{
    int res1 , res2 ; 
    struct node *t1 = poly1 ; 
    struct node *t2 = poly2 ; 
    struct node *poly3 = NULL ; 
    while(t1 != NULL)
    {
        t2 = poly2 ; 
        while(t2 != NULL)
        {
            res1 = t1->coef * t2->coef ; 
            res2 = t1->order + t2->order ; 
            poly3 = ins_end(poly3 , res1 , res2);
            t2 = t2->next; 
        }
        t1 = t1->next ; 
    }
    return(poly3);

}
int main()
{
struct node *poly1 = 0 ; 
int order1 ; 
printf("Enter order 1 : ");
scanf("%d",&order1);
poly1 = create(poly1,order1);
display(poly1);

struct node *poly2 = 0 ; 
int order2 ; 
printf("Enter order 2 : ");
scanf("%d",&order2);
poly2 = create(poly2,order2);
display(poly2);

struct node *poly3 = 0 ; 
poly3 = multiply(poly1,poly2);
display(poly3);

return 0;
}