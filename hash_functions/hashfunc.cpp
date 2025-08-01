#include <iostream>
#include <string>
#include <vector>
#include <variant>

using namespace std;

// Needs .set, .get. 
class HashNode{
    private:
    int key;
    int value;
    public:
    HashNode(int k, int v){
        key = k;
        value = v;

    }
    int getKey(){
        return value;
    }
};


class HashTable{
private:
    int size;
    HashNode **arr;
    int i = 0;
public:
    HashTable(int s){
        size = s;
        arr = new HashNode*[size];
        for(int i = 0; i < size; i++) {
            arr[i] = NULL;
        }
    }

    int HashFunction(int key){
        int hash = key % size;
        return hash;
    }

    void set(int key, int value){
        int hash = HashFunction(key);
        arr[hash] = new HashNode(key,value);
    }



    int get(int key){
        int hash = HashFunction(key);
        return arr[hash]->getKey();
    }
};


int main(){

    HashTable ht = HashTable(50);
    ht.set(1,1);
    ht.set(2,2);
    ht.set(2,3);
    ht.set(2,8);  // note then when displayed the value of key->2 should be only 8.
    ht.set(12,21);


    cout << "this should be 4: " << ht.get(2) << endl;
    return 0;
}
