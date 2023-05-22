#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;



class Queue {
public:
  Queue() {
    front = rear = 0;
  }

  //Insert Element in queue

   void enqueue(int data) {
    if (isFull()) {
      cout << "Queue is full!" << endl;
      return;
    }

    rear++;
    if (rear == QUEUE_SIZE) {
      rear = 0;
    }

    queue[rear] = data;
  }
 //Delete element from queue
  int dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty!" << endl;
      return -1;
    }

    front++;
    if (front == QUEUE_SIZE) {
      front = 0;
    }

    return queue[front];
  }

  bool isEmpty() {
    return front == -1;
  }

  bool isFull() {
    return (rear + 1) % QUEUE_SIZE == front;
  }

private:
  static const int QUEUE_SIZE = 10;
  int queue[QUEUE_SIZE];
  int front;
  int rear;
};

int main() {
  Queue q;

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);

  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;

  return 0;
}
