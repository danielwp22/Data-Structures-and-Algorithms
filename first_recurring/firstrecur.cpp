#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int firstReccuring(int *arr, int length){

    unordered_map<int,int> MyMap;

    for (int i = 0; i < length; i++){
        if (MyMap.count(arr[i])){
            return arr[i];
        }
        else{
            MyMap[arr[i]] = 1;
        }

    }
    return -1;
}

int main(){
    int arr[] = {1,3,2,3,4,2,3};
    int length = sizeof(arr)/sizeof(arr[0]);
    int reccuring = firstReccuring(arr, length);
    cout << "recurring char: " << reccuring << endl;
    
    return 0;
}
