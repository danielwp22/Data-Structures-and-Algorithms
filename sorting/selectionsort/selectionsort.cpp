#include <iostream>
#include <string>
#include <vector>

using namespace std;


// My old shitty version LOL
// vector<int> selectionsort(vector<int> arr){
//     int length = arr.size(); 
//     int lowestNum;
//     int dynamicStart = 0;
//     int lowestNumIndex;

//     for (int j = 0; j<length; j++){
//         lowestNumIndex = dynamicStart;
//         for (int i = dynamicStart; i<length; i++){
//             if (i == dynamicStart){
//                 lowestNum = arr[i];
//             }
//             else{
//                 if (arr[i] < lowestNum){
//                     lowestNum = arr[i];
//                     lowestNumIndex = i;
//                 }
//             }
//         }
//         arr.erase(arr.begin()+lowestNumIndex);
//         arr.insert(arr.begin()+dynamicStart, lowestNum);
//         dynamicStart++;
//     }
//     return arr;
// }


vector<int> selectionsort(vector<int> arr){
    int length = arr.size(); 
    int lowestNumIndex;

    for (int j = 0; j<length; j++){
        lowestNumIndex = j;
        for (int i = j; i<length; i++){
            if (arr[i] < arr[lowestNumIndex]){
                    lowestNumIndex = i;
                }
            }
            swap(arr[j], arr[lowestNumIndex]);
        }

        return arr;
    }

int main(){
    vector<int> arr = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    vector <int> lst = selectionsort(arr);
    cout << "Printing the list now: " << endl;
    for(int num: lst){
        cout << num << endl;
    }
}