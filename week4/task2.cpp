#include <iostream>
using namespace std;

/*
  https://judge.openfmi.net/practice/open_contest?contest_id=141
  Task: Октопаки
  We apply the Ternary Search algorithm looking for value on each of the a[i] indexes.
*/

long long arr[100001];

long long getPower(int base, int power){
    if(power == 0) return 1;
    long long res = base;
    for(int i = 1; i < power; i++){
        res *= base;
    }
    return res;
}

int main(){
    int n, p;
    cin >> p >> n;
    long long maxRight = getPower(3,p);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        long long left = 1,
                  right = maxRight;
        int due = 1;
        while(left <= right){
            long long mid1 = (2 * left + right) / 3 + 1,
                      mid2 = (left + 2 * right) / 3;

            if(mid1 == mid2){
                if(arr[i] == mid1) {
                  cout << due << endl;
                }
                else {
                  cout << due + 1 << endl;
                }
                break;
            }

            if(arr[i] >= mid1 && arr[i] <= mid2 && mid1 != mid2){
                cout << due << endl;
                break;
            }
            else if(arr[i] <= mid1){
                right = mid1 - 1;
                due++;
            }
            else if(arr[i] > mid2){
                left = mid2 + 1;
                due++;
            }
        }
    }

}
