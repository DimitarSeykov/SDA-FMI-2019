/**
    Task: For std::vector exercise , given a long number ( < 10^18 ),
          push all its digits in a std::vector and print them
*/

#include <iostream>
#include <vector>
#include <algorithm> //reverse

using namespace std;

void printVectorContent(vector<int>& vec){
    int len = vec.size();

    for(int i = 0; i < len; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> digits;

    long long n;
    cin >> n;

    while(n != 0){
        int lastDigit = n % 10;
        digits.push_back(lastDigit);
        n /= 10;
    }

    reverse(digits.begin(), digits.end());
    printVectorContent(digits);
}
