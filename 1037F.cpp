#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void dfs( int node, unordered_map<int,list<pair<int,ll>>> &adj, vector<int> &a, vector<int> &vis, ll &sum ) {

    vis[node] = 1;
    for ( auto it : adj[node] ) {
        if ( !vis[it.first] ) {
            
            if ( a[node] != a[it.first] ) sum += it.second;
            dfs( it.first, adj, a, vis, sum );
        }
    }
}

void solve( int node, unordered_map<int,list<pair<int,ll>>> &adj, vector<int> &a, ll &sum, int prev_col ) {
    for ( auto it : adj[node] ) {
        if ( a[it.first] == a[node] ) sum -= it.second;
        if ( a[it.first] == prev_col ) sum += it.second;
    }
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        int q; cin >> q;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }
        unordered_map<int,list<pair<int,ll>>> adj;
        for ( int i = 1; i < n; i++ ) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            ll wt; cin >> wt;
            adj[u].push_back( {v,wt} );
            adj[v].push_back( {u,wt} );
        }
        vector<int> vis( n, 0 );
        ll sum = 0;
        dfs( 0, adj, a, vis, sum );

        for ( int i = 0; i < q; i++ ) {
            int idx, col;
            cin >> idx >> col;
            int prev_col = a[idx-1]; 
            a[idx-1] = col;
            solve( idx-1, adj, a, sum, prev_col );
            cout << sum << endl;
        }
    }
    return 0;
}
