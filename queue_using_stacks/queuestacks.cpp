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

class Stack{
public:
    int length;
    Node *top;
    Node *bottom;

    Stack(){
        length = 0;
        top = NULL;
        bottom = NULL;
    }

    int peek(){
        cout << "top value is " << top->value << endl;
        return top->value;
        
    }

    void push(int val){
        Node *new_node = new Node(val);

        if(!top){
            top = new_node;
        }
        else{
            new_node->pointer = top;
            top = new_node;
        }
        length++;
    }

    int pop(){ 
        Node *old = top;
        if(!top){
            cout << "Stack underflow" << endl;
            return(-1);
        }
        else{
            top = top->pointer;
            cout << old->value << endl;
            return old->value;
            free(old);
            cout << "new top: " << top->value << endl;
        }
        length--;
    }
};


    /*
    Stack 1 2 3
    push: 1 2 3 1
    enqueue 1: 1 1 2 3 

    for (1 1 2 3)
    pop: 1 1 2
    dequeue: 1 2 3

    so.... for the enqueue, you would have to ... pop the whole list, push the 1, push the whole list again ? 

    pop: remove from end, dequeue, remove from start. 
    dequeue:
    pop whole list, then push everything except the dequeued last one ? 

    issue: where do you save the values? in an array of size of the list ..? I guess so
    
    */

class Queue{
public:
    Stack myQueueStack;
    
    
    Queue(){

    }

    void enqueue(int val){
        int num;
        int index = 0;
        int length = myQueueStack.length;
        int node_array[length];
        while (!(myQueueStack.top == NULL)){
            num = myQueueStack.pop();
            node_array[index] = num;
        }
        myQueueStack.push(val);

        for (int number: node_array){
            myQueueStack.push(number);
        }
    }

    void dequeue(){
        myQueueStack.pop();
    }

    void peek(){
        myQueueStack.peek();
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
