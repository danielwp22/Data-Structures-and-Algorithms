#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> mergeSortedArrays(vector<int> vector1, vector<int> vector2){
    string new_str;
    int len;
    int vector_len = vector1.size() + vector2.size();
    vector<int> new_vec(vector_len);
    if (vector1.size() > vector2.size()){
        len = vector1.size();
    }
    else{
        len = vector2.size();
    }
    int vec_index = 0;
    int index1 = 0;
    int index2 = 0;

    while (vec_index < vector_len){
        while (!(index1 == vector1.size()) && !(index2 == vector2.size())){
            if (vector1[index1] < vector2[index2]){
                new_vec[vec_index] = vector1[index1];
                vec_index++;
                index1++;
            } 
            else if (vector1[index1] > vector2[index2]){
                new_vec[vec_index] = vector2[index2];
                vec_index++;
                index2++;
            } 
            else{
                new_vec[vec_index] = vector1[index1];
                vec_index++;
                index1++;  
            } 
        }

        if (index1 == vector1.size()){
            new_vec[vec_index] = vector2[index2];
            vec_index++;
            index2++;  
        }
        else if (index2 == vector2.size()){
            new_vec[vec_index] = vector1[index1];
            vec_index++;
            index1++;  
        }

    }
    return new_vec;
}

int main(){
    vector<int> vec = mergeSortedArrays({0,3,4,31},{4,6,30});

    for (int num: vec){
        cout << num << " "; 
    }
    
    
    return 0;
}
