//https://www.hackerrank.com/challenges/the-power-sum/problem

#include <bits/stdc++.h>
using namespace std;

int ans = 0;

/// time complexity O(power)
int slowPow(int x, int power)
{
    int res = 1;
    for(int i=0; i<power; ++i)
    {
        res*=x;
    }
    return res;
}

/// time complexity O(log2(power))
int fastPow(int x, int power)
{
    if(power == 0){
        return 1;
    }
    if(power%2 == 0){
        return pow(x, power/2) * pow(x, power/2);
    }
    return x*pow(x, power/2) * pow(x, power/2);
}

/*
Solution (implementation proposed by Angel Tzankov)
    The function recursively generates all the sums of distinct
    n-th powers and counts the ones that equal x.
*/
void generatePowerSum(int x, int n, int lastUsed){
    if(x < 0){
        return;
    }
    if(x == 0){
        ans++;
        return;
    }
    for(int i = lastUsed + 1; fastPow(i, n) <= x; i++){
        generatePowerSum(x - fastPow(i, n), n, i);
    }
}

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);
    generatePowerSum(x, n, 0);
    printf("%d\n", ans);
}
