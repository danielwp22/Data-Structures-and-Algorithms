#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LLNode{
public:
    int value;
    LLNode *pointer;
    LLNode *pointer_back;
    LLNode(int val){
        value = val;
        pointer = NULL;
        pointer_back = NULL;
    }

};

class LinkedList{

public:
    LLNode *head;
    LLNode *tail;
    int length;
    LinkedList(int h){
        head = new LLNode(h);
        tail = head;
        length = 1;
    }

    void prepend(int number){
        LLNode *node = new LLNode(number);
        node->pointer = head;
        head->pointer_back = node;
        head = node;
        length += 1;
    }

    void append(int number){
        LLNode *node = new LLNode(number);
        tail->pointer = node;
        node->pointer_back = tail;
        tail = node;
        length += 1;
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
                    head->pointer_back = node;
                    head = node;
                }
                else{
                    target_node = head;
                }
            }

            else if (iteration == index){
                node->pointer = target_node->pointer;
                node->pointer_back = target_node;
                node->pointer->pointer_back = node;
                node->pointer_back->pointer = node;
                target_node->pointer = node;
            }
            else{
                if (target_node->pointer != NULL){
                    target_node = target_node->pointer;
                }
            }
            iteration++;
        }
        length += 1;
    }

    LinkedList reverse(){
        LinkedList reversed_list(tail->value);
        LLNode *current_node = tail;
        while (current_node->pointer_back != NULL){
            reversed_list.append(current_node->pointer_back->value);
            current_node = current_node->pointer_back;
        }
        return reversed_list;
    }
    /*
    [10,4,7]
    So we start at 7, and we go backwards appending numbers to the end of the list.
    We start with 4, the starting node pointing backwards to it. We say, attach it to the tail, and now 7 points back to 10, which points at 7. 
    We repeat this again, except we attach the 10 to the end, and see that before it was null, so we set the pointerback of 4 to null.
    We don't have to care about the pointers of the previous ones since they become nul anyways. 
    [3,4,5,6]
    For the first step, we want to bring the 10 to the front,
    Ideal btw: [7,4,10] tail is 10
    */
    // // First implementation:
    // void reverse_self(){
    //     int index = 1;
    //     LLNode *start_node = tail;
    //     LLNode *last = tail;
    //     while (index<length){
    //         if (start_node->pointer_back->pointer_back != NULL){
    //         last = start_node->pointer_back->pointer_back;
    //         tail->pointer = start_node->pointer_back;
    //         start_node->pointer_back->pointer_back = tail;
    //         tail = start_node->pointer_back;
    //         last->pointer = start_node;
    //         start_node->pointer_back = last;
    //         tail->pointer = NULL;
    //         }
    //         else{
    //             tail->pointer = start_node->pointer_back;
    //             start_node->pointer_back->pointer_back = tail;
    //             tail = start_node->pointer_back;
    //             start_node->pointer_back = NULL;
    //             tail->pointer = NULL;
    //             head = start_node;
    //         }
    //         index++;
    //     }
    //     cout << "we out da while loop, tail is " << tail->value << endl; 
    //     cout << "head is " << head->value << endl; 
    // }

    void reverse_self(){
        LLNode *current = head;
        LLNode *temp = current->pointer;
        //Check if its just a size 1 LL, then you can just return because its the same
        if (!current->pointer){
            return;
        }
        head = tail;
        tail = current;
        while (current){
            temp = current->pointer;
            current->pointer = current->pointer_back;
            current->pointer_back = temp;
            current = current->pointer_back;
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
    cout << "First list: " << " Head is " << myNewList.head->value << " tail is " << myNewList.tail->value << endl;
    cout << "middle item is " << myNewList.get(1) << endl;
    myNewList.reverse_self();
    cout << "Second list: " << " Head is " << myNewList.head->value << " tail is " << myNewList.tail->value << endl;
    cout << "middle item is " << myNewList.get(1) << endl;
    return 0;
}
