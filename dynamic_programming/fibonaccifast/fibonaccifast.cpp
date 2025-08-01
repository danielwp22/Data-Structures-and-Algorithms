
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 0, 1, 1, 2, 3, 5, 8, 13


int fibonacciHelper(int value, unordered_map<int,int> map){
    int val1;
    int val2;
    int total;
    if (value < 2){
        return value;
    }

    if (map.count(value)){
        return map.count(value);
    }
    return map[value] = fibonacciHelper(value-1, map) + fibonacciHelper(value-2, map);
}

int fibonacci(int value){
    unordered_map<int,int> map;
    
    return fibonacciHelper(value, map);


}

int main(){
    int num = fibonacci(6);
    cout << "number is " << num << endl; 
    return 0;
}
