//Link List in c++
//Rahul_1703066
#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   struct Node *next;

}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*) malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int Is_sorted(struct Node *p)
{
    int t=-32768;

    while(p!=NULL){

        if(p->data>t) {t=p->data; p=p->next;}

        else return 0;
    }
    return 1;


}

void Remove_Duplicate(struct Node *p)
{
    struct Node *q=p->next;

    while(q){
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else{

            p->next=q->next;
            free(q);
            q=q->next;
        }
    }
}

void Reverse_list(struct Node *p)
{
    struct Node *q,*r;
    q=NULL;
    r=NULL;

    while(p!=NULL)
    {

        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

int main()
{
    struct Node *temp;
    int A[]={3,5,5,10,12,18,20,22};
    create(A,8);
    Display(first);

    if(Is_sorted(first)) cout<<"Sorted\n";
    else cout<<"Not sorted\n";

    Remove_Duplicate(first);
    Display(first);
    Reverse_list(first);
    Display(first);
    Reverse_list(first);

}

