#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val){
        value = val;
        left = NULL;
        right = NULL;
    }
};

/*
Sorting the tree:
Look at current node value. Is it full? if its greater, move to the right node (for example)
Look at this node. Is it greater or less? if its greater, move right, if its less, move left. 
IF that node is null, end the loop we did it.

*/

class BinarySearchTree{
public:
    Node *parent;

    BinarySearchTree(){
        parent = NULL;
    }

    void insert (int val){
        Node *new_node = new Node(val);
        Node *current_node = parent;
        if (parent == NULL){
            parent = new_node;
        }
        while(current_node){
            if(val < current_node->value){
                if (current_node->left){
                    current_node = current_node->left;
                }
                else{
                    current_node->left = new_node;
                    current_node = NULL;
                }
            }
            else{
                if (current_node->right){
                    current_node = current_node->right;
                }
                else{
                    current_node->right = new_node;
                    current_node = NULL;
                }
            }
        }
    }

    void lookup(int val){
        Node *current_node = parent;
        if (parent == NULL){
            cout << "nothin here" << endl;
        }
        
        int index = 0;
        while(current_node){
            if(val < current_node->value){
                if (current_node->left){
                    current_node = current_node->left;
                    index++;
                }
                else{
                    current_node = NULL;
                }
            }
            else if (val > current_node->value){
                if (current_node->right){
                    current_node = current_node->right;
                    index++;
                }
                else{
                    current_node = NULL;
                }
            }
            else{
                cout << "ya " << val << " is here at index " << index << endl;
                return;
            }
        }
        cout << "nah " << val << " not here" << endl;
    }

    vector<int> depthFirstSearchPreOrder(Node* root, vector<int> list){
        
        if (root == NULL){
            return(list);
        }

        list.push_back(root->value);
        //4, {9}
        // Pushes 4 to list(9,4)
        // Goes to 1, (9,4)
        //List (9,4,1)
        //
        list = depthFirstSearchPreOrder(root->left, list);
        list = depthFirstSearchPreOrder(root->right, list);
        
        return list;
    }

    vector<int> depthFirstSearchInOrder(Node* root, vector<int> list){
        
        if (root == NULL){
            return(list);
        }

        
        //4, {9}
        // Pushes 4 to list(9,4)
        // Goes to 1, (9,4)
        //List (9,4,1)
        //
        list = depthFirstSearchInOrder(root->left, list);
        list.push_back(root->value);
        list = depthFirstSearchInOrder(root->right, list);
        
        return list;
    }
};

int main(){
    BinarySearchTree tree = BinarySearchTree();
    tree.insert(9);
    tree.insert(4);
    tree.insert(20);
    tree.insert(170);
    tree.insert(15);
    tree.insert(1);
    tree.insert(6);
    tree.lookup(9);
    tree.lookup(20);
    tree.lookup(170);
    tree.lookup(22);
    vector<int> starting_list = {};
    vector<int> list = tree.depthFirstSearchInOrder(tree.parent,starting_list);
    cout << "list: " << endl;
    for (int num : list){
        
        cout << num << endl;
    }
    return 0;
}
