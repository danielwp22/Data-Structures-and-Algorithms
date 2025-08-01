#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
Lemme think, Go through each index (for j in length)
For that index, go through previous. 
Is it less than this? 
[1,3,7,5,0]

0, 
So for 1 3 5 6 8 7 

7 is less than 8! 
(enter the loop) (this part is ok)

is 7 less than 8? yes! It can take 7's spot, 1 3 5 6 8 8
                                             0 1 2 3

Now, 6? Is 7 < 6? no, Ah ok, I guess 7 can just take the current spot then, where 8 was. arr[i] = temp ? 


*/
// My first naive version
// vector<int> insertionsort(vector<int> arr){
//     int length = arr.size(); 
//     int temp;
//     for (int j = 1; j<length; j++){
//         if (arr[j] < arr[j-1]){
//             temp = arr[j];
//             cout << "Resorting " << temp << endl;
//             for (int i = j-1; i>=-1; i--){
//                 cout << "Comparing " << temp << " and " << arr[i] << endl;
//                 if (i == -1){
//                     arr[0] = temp;
//                 }

//                 else if (temp < arr[i]){
//                     arr[i+1] = arr[i];
//                 }
                
//                 else if (temp > arr[i]){
//                     arr[i+1] = temp;
//                     i = -2;
//                 }
//             }
//         }
//         cout << "Iteration " << j << " and list is: " << endl;
//         for(int num: arr){
//             cout << num << endl;
//         }
//     }
//     return arr;
// }

vector<int> insertionsort(vector<int> arr){
    int length = arr.size(); 
    int temp;
    for (int j = 1; j<length; j++){
        if (arr[j] < arr[j-1]){
            temp = arr[j];
            int i = j-1;
            while((temp < arr[i]) && (i>=0)){
                arr[i+1] = arr[i];
                i--;
            }
            arr[i+1] = temp;
        }
    }
    return arr;
}

int main(){
    vector<int> arr = {6,5,3,1,8,7,2,4};
    vector <int> lst = insertionsort(arr);
    cout << "printing out da list" << endl;
    for(int num: lst){
        cout << num << endl;
    }
}
