#include<bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;
public:
    Queue(){front=rear=-1;size=10;Q=new int[size];}
    Queue(int size){front=rear=-1;this->size=size;Q=new int[this->size];}

    void enqueu(int x);
    int deque();
    void Display();

};

void Queue::enqueu(int x)
{

    if(rear==size-1)
        printf("Size FULL\n");
        else{
            rear++;
            Q[rear]=x;
        }

}

int Queue::deque()
{
    int x=-1;
    if(front==rear)
        printf("Queue is empty\n");

    else
        {

        x=Q[front+1];
        front++;
    }
    return x;

}

void Queue::Display()
{

    for(int i=front+1;i<=rear;i++)
    {
        printf("%d ",Q[i]);
    }

    printf("\n");
}

int main()
{

    Queue q(5);
    q.enqueu(10);
    q.enqueu(30);
    q.enqueu(50);

    q.Display();
    q.deque();
    q.Display();

    return 0;
}
