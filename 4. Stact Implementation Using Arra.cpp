#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    int sz;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter Size of Stack: ");
    scanf("%d",&st->sz);
    st->top=-1;
    st->S=new int[st->sz];


}

void display(struct Stack st)
{
    int i;

    for(i=st.top;i>=0;i--)
        printf("%d ",st.S[i]);

    printf("\n");
}

void push(struct Stack *st,int x)
{
    if(st->top==st->sz-1)
        printf("Overflow\n");
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
        printf("Empty\n");
    else
    {
        x=st->S[st->top];
        st->top--;

    }
    return x;
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);

    display(st);

    return 0;
}
