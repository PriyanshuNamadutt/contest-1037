#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll lcm ( ll a, ll b ) {
    return a / __gcd( a, b) * b;
} 

bool solve() {
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    for ( int i = 0; i < n; i++ ) {
        cin >> b[i];
    }

    int mx = a[0];
    int mn = b[0];
    for ( int i = 1; i < n; i++ ) {
        if ( mx < a[i] ) return false;
        else mx = a[i];

        if ( mn > b[i] ) return false;
        else mn = b[i];
    }

    vector<ll> ans(n);
    for ( int i = 0; i < n; i++ ) {
        ans[i] = lcm( a[i], b[i] );
    }

    ll gcd1 = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( __gcd( gcd1, a[i] ) != a[i] ) return false;
        gcd1 = __gcd( gcd1, a[i] );
    }
    ll gcd2 = 0;
    for ( int i = n-1; i >= 0; i-- ) {
        if ( __gcd( gcd2, b[i]) != b[i] ) return false;
        gcd2 = __gcd( gcd2, b[i] );
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
