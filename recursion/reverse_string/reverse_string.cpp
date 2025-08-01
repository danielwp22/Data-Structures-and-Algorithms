
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverseStringIter(string str){
    string reverseStr = str;
    int length = str.length();
    for (int i = 0; i < length; i++){
        reverseStr[i] = str[length-i-1];
    }
    return reverseStr;
}


void reverseString(string &str, int i = 0){
    int length = str.length();
    if (i == length/2){
        return;
    }
    char first_char = str[i];
    str[i] = str[length-i-1];
    str[length-i-1] = first_char;
    cout << "string is now " << str << endl;
    reverseString(str, i+1);
}

int main(){
    string myString = "hello";
    string revString = reverseStringIter(myString);
    cout << "reversed is: " << revString << endl;

    string myString2 = "alright";
    reverseString(myString2);
    cout << "2nd string reversed is: " << myString2 << endl;
    return 0;
}
