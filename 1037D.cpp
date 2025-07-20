#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        ll k; cin >> k;
        vector<vector<ll>> a( n, vector<ll>(3) );
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        sort( a.begin(), a.end() );

        ll ans = k;
        for ( int i = 0; i < n; i++ ) {
            if ( a[i][0] <= ans && a[i][1] >= ans ) {
                ans = max( ans, a[i][2] );
            }
        }
        cout << ans << endl;
    }
    return 0;
}
