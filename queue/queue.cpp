#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{
public:
    Node *pointer;
    int value;
    Node(int val){
        value = val;
        pointer = NULL;
    }
};

class Queue{
public:
    int length;
    Node *front;
    Node *back;

    Queue(){
        length = 0;
        front = NULL;
        back = NULL;
    }

    void enqueue(int val){
        Node *new_node = new Node(val);

        if(!back){
            back = new_node;
            front = back;
        }
        else{
            back->pointer = new_node;
            back = new_node;
        }
        length+=1;
    }

    void dequeue(){ 
        Node *old = front;
        if(!front){
            cout << "Stack underflow" << endl;
        }
        else{
            old = front;
            front = front->pointer;
            cout << "dequeued " << old->value << endl;
            free(old);
        }
        length -= 1;
    }

    int peek(){
        cout << "front value is " << front->value << endl;
        return front->value;
    }
};


int main(){
    Queue myQueue = Queue();
    myQueue.enqueue(3);
    myQueue.peek();
    myQueue.enqueue(4);
    myQueue.peek();
    myQueue.dequeue();
    myQueue.peek();
    //Should give 3 3 4 

    return 0;
}
