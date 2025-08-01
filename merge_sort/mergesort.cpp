#include <iostream>
#include <string>
#include <vector>

using namespace std;

int *mergeSortedArrays(int *arr1, int *arr2, int length1, int length2){
    
    int *arr3 = new int[length1+length2];
    for (int i = 0; i < (length1); i++){
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < (length2); i++){
        arr3[i+length1] = arr2[i];
    }   
    return arr3;

}

int main(){
    int arr1[] = {1,2,3};
    int arr2[] = {4,5,6};
    
    int length1 = sizeof(arr1)/sizeof(arr1[0]);
    int length2 = sizeof(arr2)/sizeof(arr2[0]);

    int *arr3 = mergeSortedArrays(arr1,arr2, length1, length2);

    for (int i = 0; i < (length1+length2); i++){
        cout << arr3[i] << " "; 
    }
    
    
    return 0;
}
