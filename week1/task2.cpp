/**
Task: Given a string (that may contain any ASCII symbol),
      find which symbol has occurred the most times and how many times did it occur.
*/

#include <iostream>
#include <string>

using namespace std;

const int ASCII_SIZE = 256;
//By initializing it in the global scope, all its values are set to 0
int holder[ASCII_SIZE + 5]; //ASCII has 256 symbols. We leave some buffer, just in case

int main(){
    string s;
    cin >> s;

    int len = s.size();

    for(int i = 0; i < len; i++){
        int intValue = int(s[i]);
        holder[intValue] += 1;
    }

    int maxNum = holder[0];
    int idxOfMaxOccuredSymbol = 0;
    for (int i = 0; i < ASCII_SIZE; i++){
        if (holder[i] > maxNum){
            maxNum = holder[i];
            idxOfMaxOccuredSymbol = i;
        }
    }

    cout << "Symbol: " << char(idxOfMaxOccuredSymbol) << endl;
    cout << "Number of times: " << maxNum << endl;


}
