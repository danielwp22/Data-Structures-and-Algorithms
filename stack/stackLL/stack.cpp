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
    }

    void pop(){ 
        Node *old = top;
        if(!top){
            cout << "Stack underflow" << endl;
        }
        else{
            top = top->pointer;
            cout << old->value << endl;
            free(old);
            cout << "new top: " << top->value << endl;
        }
    }
};


int main(){
    Stack myStack = Stack();
    myStack.push(3);
    myStack.peek();
    myStack.push(5);
    myStack.peek();
    myStack.pop();
    myStack.peek();
    //Should give 3 5 3 ?

    return 0;
}
