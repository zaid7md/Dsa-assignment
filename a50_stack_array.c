#include<stdio.h>
void push(int s[] , int *top , int d , int size) // top = &top
{
    if(*top == size-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        (*top)++;
        s[*top] = d ; //s[++(*top)] = d
    }
    
}
int pop(int s[] , int *top , int size )
{
    int d ; 
    if(*top == -1)
    {
        printf("Underflow");
    }
    else
    {
        d = s[*top] ; 
        (*top)-- ;    //or return s[(*top)--]
        return d ; 
    }
    
}
void display(int s[] , int top)
{
    int i  = top ; 
    while(i>=0)
    {
        printf("st[%d] : %d\t",i,s[i]);
        i--;
    }
}
int peek(int s[] , int top)
{
    int i = top ; 
    if(top == -1)
    {
        printf("Underflow\n");

    }
    else
    {
        return(s[i]);
    }
    
}
int main()
{
int size , data; 
printf("Enter size of stack array : ");
scanf("%d",&size);


int st[size] ; 
int top = -1 ; 
//stack created 
int ch ; 
while(ch!=0)
{
    printf("\n0 : Exit\n1 : Push\n2 : Pop\n3 : Display\n4 : Peek\nEnter choice : ");
    scanf("%d",&ch); 
    switch(ch)
    {
        case 0 : 
        {
           break ; 
        }
        case 1 : 
        {
            printf("Enter element you want to insert in stack : ");
            scanf("%d",&data);
            push(st , &top , data , size);
            display(st , top);
            break ;   
        }
        case 2 : 
        {
            if(top!= -1 )
            {
            data = pop(st , &top , size);
            printf("Popped element %d\n",data);
            display(st , top);
            }
            else
            {
                data = pop(st,&top , size);
            }
            
            break ; 
        }
        case 3 : 
        {
            display(st,top);
            break ;
        }
        case 4 :
        {
            if(top != -1)
            {
                data = peek(st,top);
                printf("Topmost element is %d\n",data);
            }
            break ; 
        }
    }
}

return 0;
}