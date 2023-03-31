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

int st2[size];
int top2 = -1 ;



int ch ; 
int sc ; 
while(ch)
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
            printf("In which stack ?\t 1 : st1\t\t2 : st2\n");
            scanf("%d",&sc);
            if(sc == 1)
            {
            push(st , &top , data , size);
            display(st , top);
            }
            else
            {
                push(st2 , &top2 , data , size);
                display(st2 , top2);
            }
            
            break ;   
        }
        case 2 : 
        {
            printf("In which stack ?\t 1 : st1\t2 : st2 : ");
            scanf("%d",&sc);
            if(sc==1)
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
            }
            else
            {
                
            if(top2!= -1 )
            {
            data = pop(st2, &top2 , size);
            printf("Popped element %d\n",data);
            display(st2 , top2);
            }
            else
            {
                data = pop(st2,&top2 , size);
            }
            }
            
            break ; 
        }
        case 3 : 
        {
            
            display(st,top);
            printf("\n");
            display(st2,top2);
                        break ;
        }
        case 4 :
        {
            printf("Which stack ?\t 1 : st1\t2 : st2 : ");
            scanf("%d",&sc);
            if(sc==1)
            {
            
            if(top != -1)
            {
                data = peek(st,top);
                printf("Topmost element is %d\n",data);
            }
            }
            else
            {
                data = peek(st2,top2);
                printf("Topmost element is %d\n",data);
            }
        }

    }
}

return 0;
}