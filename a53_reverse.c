#include<stdio.h>
#include<stdlib.h>
void push(char s[] , int *top , char d , int size) // top = &top
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
char pop(char s[] , int *top , int size )
{
    char d ; 
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
void display(char s[] , int top)
{
    int i  = top ; 
    while(i>=0)
    {
        printf("st[%d] : %c\t",i,s[i]);
        i--;
    }
}
char peek(char s[] , int top)
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
void reverse(char st[],int top,int n,char st2[],int top2)
{
    for(int i=top ; i>=0 ;i--){
        push(st2 ,&top2 ,st[i] ,n);
    }
    display(st2,top2);
}
int main()
{
int size ;
char data; 
printf("Enter size of stack array : ");
scanf("%d",&size);

char st2[size];
int top2 = -1 ; 

char st[size] ; 
int top = -1 ; 
//stack created 
int ch ; 
while(1)
{
    printf("\n0 : Exit\n1 : Push\n2 : Pop\n3 : Display\n4 : Peek\n5 : copy\nEnter choice : ");
    scanf("%d",&ch);  
    switch(ch)
    {
        case 0 : 
        {
            exit(0);    
        }
        case 1 : 
        {
            printf("Enter element you want to insert in stack : ");
            scanf(" %c",&data);
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
                printf("Topmost element is %c\n",data);
            }
            break ; 
        }
        case 5 :
        {
            reverse(st,top,size,st2,top2);
            break ; 
        }
    }
}

return 0;
}