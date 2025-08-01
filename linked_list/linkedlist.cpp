#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LLNode{
public:
    int value;
    LLNode *pointer;
    LLNode(int val){
        value = val;
        pointer = NULL;
    }

};

class LinkedList{

public:
    LLNode *head;
    LLNode *tail;
    LinkedList(int h){
        head = new LLNode(h);
        tail = head;
    }

    void prepend(int number){
        LLNode *node = new LLNode(number);
        node->pointer = head;
        head = node;
    }

    void append(int number){
        LLNode *node = new LLNode(number);
        tail->pointer = node;
        tail = node;
    }

    /*
    Start: iter 0, head node. 
    next iter,1, this is it! before we insert... 
    head node points to 

    index = 0
    Should insert immediately before head .... 
    index == 1, 
    need to use previous head to see where it pointed before, then point to our node

    So for iteration 0, we're BEFORE target node
    
    */

    void insert(int number, int index){
        LLNode *node = new LLNode(number);
        int iteration = 0;
        LLNode *target_node;


        while (iteration <= index){

            if (iteration == 0){
                if (iteration == index){
                    node->pointer = head;
                }
                else{
                    target_node = head;
                }
            }

            else if (iteration == index){
                node->pointer = target_node->pointer;
                cout << "previous node: " << target_node->value << endl;
                target_node->pointer = node;
                cout << "Current node: " << node->value << " Node after: "<< node->pointer->value << endl;
            }
            else{   
                if (target_node->pointer != NULL){
                    target_node = target_node->pointer;
                }
            }
            iteration++;
        }
    }

    /*
    
    
    */

    void reverse(){
        LLNode *node = new LLNode(number);
        int iteration = 0;
        LLNode *target_node;


        while (iteration <= index){

            if (iteration == 0){
                if (iteration == index){
                    node->pointer = head;
                }
                else{
                    target_node = head;
                }
            }

            else if (iteration == index){
                node->pointer = target_node->pointer;
                cout << "previous node: " << target_node->value << endl;
                target_node->pointer = node;
                cout << "Current node: " << node->value << " Node after: "<< node->pointer->value << endl;
            }
            else{   
                if (target_node->pointer != NULL){
                    target_node = target_node->pointer;
                }
            }
            iteration++;
        }
    }

    int get(int index){
        int iteration = 0;
        LLNode *target_node = head;
        while (iteration <= index){
                if (iteration == index){
                    
                    return target_node->value;
                }
                else{
                    target_node = target_node->pointer;
                }
            iteration++;
        }
        return -1;
    }
   
};
int main(){
    LinkedList myNewList = LinkedList(10);
    myNewList.append(7);
    myNewList.insert(4,1);
    int num = myNewList.get(1);
    cout << "number is " << num << endl;
    return 0;
}
