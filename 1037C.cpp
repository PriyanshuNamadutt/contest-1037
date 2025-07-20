#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

bool solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    set<ll> st;
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
        st.insert( a[i] );
    }
    ll x = a[k-1];
    ll t = 0;
    for ( auto it : st ) {
        if ( it > x ) {

            t += it-x;
            if ( t <= x ) x = it;
            else return false;
        }
    }
    return true;
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        cout << ( solve() ? "YES" : "NO" ) << endl;
    }
    return 0;
}
