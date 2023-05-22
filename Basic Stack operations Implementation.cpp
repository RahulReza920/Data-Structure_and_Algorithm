#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define MAX 10
int sz = 0;

// Creating a stack
typedef struct stack {
  int items[MAX];
  int top;
}st;
//typedef struct stack st;


void createEmptyStack(st *s){
    s->top=-1;
}


//check if the stack is full

int isfull(st *s){
    if(s->top==MAX-1)
        return 1;
    else 
        return 0;
}


//check if the stack is empty

int isempty(st *s){
    if(s->top==-1)
        return 1;
    else
        return 0;
}


//Add Element into stack

void push(st *s,int newitem){
    if(isfull(s)){
        cout<<"STACK FULL"<<endl;
    }
    else{
        s->top++;
        s->items[s->top]=newitem;
    }
    sz++;
}

//Remove Element From Stack

void pop(st *s){
    if(isempty(s)){
        cout<<"Stack is EMPTY"<<endl;
    }
    else{
        cout<<"Item Popped: "<<s->items[s->top]<<endl;
        s->top--;

    }
    sz--;
}


//print elemts of stack

void printStack(st *s){
    cout<<"Stack is: ";
    for(int i=0;i<sz;i++){
        cout<<s->items[i];
    }
    cout<<endl;
}

int main()
{

ios::sync_with_stdio(false);
cin.tie(0); cout.tie(0);

  int ch;
  st *s = (st *)malloc(sizeof(st));

  createEmptyStack(s);

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  printStack(s);

  pop(s);

  cout << "\nAfter popping out\n";
  printStack(s);
   

}
