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
void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int r, int c) {
    visited[r][c] = true;
    vector<int> dr = {-1,0, 0, 1};
    vector<int> dc = {0,-1, 1, 0};
    for (int i = 0; i <4 ; i++) {
        int x = r + dr[i];
        int y = c + dc[i];
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !visited[x][y] && grid[x][y] == '.')
            dfs(grid, visited, x, y);
    }
}
int countRoom(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int nb  =0;
    vector <vector<bool>> visited(n, vector<bool>(m, false));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]=='.'&& !visited[i][j]) {
                dfs(grid, visited, i, j);
                nb++;
            }
 
        }
    }
    return nb;
}
 
void solve() {
    int n , m ;cin>>n>>m;int res=0;
    vector<vector<char>>grid(n,vector <char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin>>grid[i][j];
        }
 
    cout <<countRoom(grid)<<endl;
 
 
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