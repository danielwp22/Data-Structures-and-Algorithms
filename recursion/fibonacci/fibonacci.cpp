
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
0 + 1 + 1 + 2 + 3 + 5 + 8 + 13 + 21
return 1 + .... until counter is 1
fibonacci(val)
returns the number at that index
current value - fibonacci (val-1) - 

fibonacci(3)

current number + last (sum) 
number 3 = number 2 + number 1

0, 1 to start base case. 

new number = 0 + 1;

fibonacci(0)


*/

int fibonacci_iter(int val){
    int number1 = 0;
    int number2 = 1;
    int temp;
    for(int i=1; i<val; i++){
        temp = number1;
        number1 = number2;
        number2 += temp;
    }
    return number2;
}

int fibonacci(int val){
    int number;
    if (val == 0){
        return(0);
    }
    if (val == 1){
        return(1);
    }
    number = fibonacci(val-1) + fibonacci(val-2);
    return number;
}

int main(){
    int num = fibonacci(6);
    cout << "number is " << num << endl; 
    int num2 = fibonacci_iter(6);
    cout << "iter number is " << num2 << endl; 
    return 0;
}
