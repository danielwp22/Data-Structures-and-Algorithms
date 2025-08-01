#include <iostream>
#include <string>
#include <vector>

using namespace std;



vector<int> bubblesort(vector<int> arr){
    int length = arr.size(); 
    int temp;
    for (int j = 0; j<length-1; j++){
        for (int i = 0; i<length-1; i++){
            if (arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    return arr;
}


int main(){
    vector<int> arr = {6,5,3,1,8,7,2,4};
    vector <int> lst = bubblesort(arr);
    for(int num: lst){
        cout << num << endl;
    }
}
