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

//Count length of a link list
int count(struct Node *p)
{

int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;

}

//Return Sum of element

int Sum(struct Node *p)
{
    int sum=0;
    while(p){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}


int Rsum(struct Node *p)
{
    if(p==NULL) return 0;

    else
        return Rsum(p->next)+p->data;
}

int Maxl(struct Node *p)
{
    int max=-32688;

    while(p)
    {
        if(p->data>max)
           max=p->data;

       p=p->next;

    }
    return max;
}

//Improve Linear Search Using Move to Front
struct Node *LSearch(struct Node *p,int k)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(k==p->data)
           {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
           }
        q=p;
        p=p->next;
    }
    return NULL;
};

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    //check for validiy of index
    if(index<0 ||index> count(p))
        return;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0){
        t->next=first;
        first=t;
    }

    else
    {

    for(int i=0;i<index-1;i++)
         p=p->next;
    t->next=p->next;
    p->next=t;
    }


}

//Inserting Node in a Sorted Link List
void Insert_Sorted(struct Node *p,int x)
{
    struct Node *t,*q;
    t=(struct Node *)malloc(sizeof(struct Node));

    t->data=x;
    q=NULL;

    if(x<p->data)
    {
        t->next=p;
        first=t;
        return;
    }

   while(p&&p->data<x)
   {
       q=p;
       p=p->next;
   }
   q->next=t;
   t->next=p;
}


//Delete a Node From Link List
int Delete_Node(struct Node *p,int index)
{
    struct Node*q;

    q=NULL;
    int x=-1;

    if(index<1||index>count(p))
        return -1;
    if(index==1)
    {
        q=first;
         x=first->data;
        first=first->next;
        delete q;
        return x;

    }

    for(int i=0;i<index-1;i++)
    {
        q=p;
        p=p->next;
    }

    q->next=p->next;
    delete p;
    return x;
}


int main()
{
    struct Node *temp;
    int A[]={3,5,7,10,15,18,20,22};
    create(A,8);
    Display(first);
    printf("\nLength is %d",count(first));

    printf("\nSum = %d",Rsum(first));
    printf("\nMax is= %d\n",Maxl(first));

    temp=LSearch(first,100);

    if(temp)
        printf("Key is found %d\n",temp->data);
    else
        printf("Key is not found\n");

    Display(first);//After Linear Search Node brought to first

    Insert(first,2,6);
    printf("After Inserting New Elements: \n");
    Display(first);

    Insert_Sorted(first,2);
    printf("After Inserting in Sorted List New Elements: \n");
     Display(first);

     Delete_Node(first,1);
     printf("After Deleting Elements: \n");
     Display(first);
}

