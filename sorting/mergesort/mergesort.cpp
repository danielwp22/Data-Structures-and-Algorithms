#include <iostream>
#include <string>
#include <vector>

using namespace std;


// My approach (worked!!)
vector<int> mergesort(vector<int> arr){
    int length = arr.size();
    int middle = length / 2;
    vector <int> new_arr = {};
    
    if (length == 1){
        cout << "somehow got 1 idk" << endl;
        return arr;
    }

    else if (length == 2){
        if (arr[0] > arr[1]){
            swap(arr[0], arr[1]);
        }
        cout << "list is 2, sorted " << arr[0] << " and " << arr[1] << endl;
        return arr;
    }

    else{
        // If its bigger than 2, split and go sort?
        vector<int> list1 = {};
        vector<int> list2 = {};
        for(int i=0; i<middle; i++){
            list1.push_back(arr[i]);
        }

        for(int i=middle; i<length; i++){
            list2.push_back(arr[i]);
        }

        vector<int> final_list1;        
        vector<int> final_list2;   
        final_list1 = mergesort(list1);
        final_list2 = mergesort(list2);

        int final_list2_index = 0;
        int j;
        int final_list2_size = final_list2.size();
        for(int num1 : final_list1){
            j = 0+final_list2_index;
            // 1 2 3 + 4 5 6
            //
            while ((j<final_list2_size)&&(num1 > final_list2[j])){
                new_arr.push_back(final_list2[j]);
                final_list2_index++;
                j++;
            }
            new_arr.push_back(num1);    
        }
        for (int i = final_list2_index; i < final_list2_size; i++){
            new_arr.push_back(final_list2[i]); 
        }
        return new_arr;
    }
}

int main(){
    vector<int> arr = {6,5,3,1,8,7,2,4};
    vector <int> lst = mergesort(arr);
    for(int num: lst){
        cout << num << endl;
    }
    return 0;
}
