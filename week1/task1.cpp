/**
Task: Find the n-th Fibonacci number using recursion (without memoization)
Hint: Fibonacci numbers are defined as follows:
    f(0) = 0
    f(1) = 1
    f(n) = f(n - 1) + f(n - 2), n > 1
*/

#include <iostream>

using namespace std;

int fibonacci(int n){
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    return fibonacci(n - 1) + fibonacci (n - 2);
}

int main(){
    cout << "Enter N: ";
    int n;
    cin >> n;

    int result = fibonacci(n);
    cout << "N-th Fibonacci number is: " << result << endl;

}
