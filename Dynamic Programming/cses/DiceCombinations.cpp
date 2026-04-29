/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
4

*/


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int  long long
#define pb(n) push_back(n)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define all(x) x.begin(), x.end()
#define print(vec) for (auto it = vec.begin(); it != vec.end(); it++) cout << *it << " "; cout << endl;
#define mod 1000000007
void solve() {
    int n  ;cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
 
    for (int i = 1; i <= n; i++)
        for (int face = 1; face <= 6; face++)
            if (i - face >= 0)
                dp[i] = (dp[i] + dp[i - face]) % mod;
 
    cout <<  dp[n];
 
}
int32_t main() {
 
    FAST
#ifndef ONLINE_JUDGE
freopen("Input.txt", "r", stdin);
   freopen("Output.txt", "w", stdout);
#endif
 
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
