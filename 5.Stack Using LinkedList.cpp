#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t=new Node();
    if(t==NULL) printf("Stack is Full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *t=new Node();
    int x=-1;
    if(top==NULL) printf("Stack is Empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p;
    p=top;

    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


int main()
{
    push(10);
    push(20);
    push(30);

    display();
    printf("%d ",pop() );
}
