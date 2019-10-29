#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;


/*
  https://judge.openfmi.net/practice/open_contest?contest_id=141
  Task: Сортирания
  The idea is simple - we binary search the answer. We could do that in linear time, which could be slow. 
  We find the biggest value that satisfies our requirments. 
*/
int main(){
    long long c, t;
    cin >> c >> t;
    long long left = 0,
              right = t*100;

    while(left <= right){
        long long mid = (left + right) / 2;
        double result = c * mid * log2(mid) * 0.01;
        double nextPotential = c * (mid + 1) * log2(mid + 1) * 0.01;
        if(result <= t && nextPotential > t){
            cout << mid << endl;
            break;
        }
        else if(result < t){
            left = mid + 1;
        }
        else if(result > t){
            right = mid - 1;
        }
    }
}
