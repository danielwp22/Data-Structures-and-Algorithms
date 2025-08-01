#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack{

public:
    vector<int> stack;
    int length;
    int top;
    int bottom;

    Stack(){
        stack = {};
        length = 0;
    }

    void push(int val){
        stack.push_back(val);
        length +=1;
        top = val;
        if (length == 0){
            bottom = top;
        }
    }

    void pop(){
        if (stack.size() == 0){
            cout << "Stack underflow";
        }
        else{
            cout << "Removed " << stack[length-1] << endl;
            stack.pop_back();
        }
        length -= 1;
        top = stack[length-1];
    }

    void peek(){
        if (stack.size() == 0){
            cout << "nothing here" << endl;
        }
        else{
            cout << "last element is: " << stack[stack.size()-1] << endl;
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
    //Should give 3 5 3

    return 0;
}
