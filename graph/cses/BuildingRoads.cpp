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
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s) {
    visited[s] = true;
    for (int i : adj[s])
        if (visited[i] == false)
            dfsRec(adj, visited, i);
}

vector<int> dfs(vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> res;int comp=0 ;
    for (int i = 0; i < adj.size(); i++) {
        if (visited[i] == false) {
            res.push_back(i+1);
            dfsRec(adj, visited, i);

        }
    }

    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    vector <vector<int>>adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector <int> res=dfs(adj);
    cout << res.size()-1<< endl;
    for (int i = 0; i < res.size()-1; i++) {
        cout << res[i]<<" "<<res[i+1] << endl;
    }



}

int32_t main() {
    FAST
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    int t = 1;
    while (t--) solve();
}