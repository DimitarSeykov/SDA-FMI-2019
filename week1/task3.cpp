/**
    Task:recursively check if a given string is a palindrome
    Hint: Use the following property: Any 1-symbol string is a palindrome
*/

#include <iostream>

using namespace std;

///Declare the string here so we don't have to carry it with us all the time in the recursive function
string s;

///l for left and r for right indexes
bool checkIfPalindrome(int l, int r){
    if(l >= r){
        return true;
    }
    if(s[l] != s[r]){
        return false;
    }
    return checkIfPalindrome(l + 1, r - 1);
}

int main(){
    cin >> s;
    int len = s.size();

    bool result = checkIfPalindrome(0, len - 1);

    result ?  cout << "Is Palindrome\n" : cout <<"Is not Palindrome\n";
}
