#include <iostream>
#include <string>
#include <vector>

using namespace std;



int factorial(int val){
    if (val == 2){
        return 2;
    }
    return(val*factorial(val-1));  
}


int main(){
    int num = factorial(5);
    cout << "number is " << num; 
    return 0;
}
