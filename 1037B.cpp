#include<iostream>
#include<vector>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }
        int cnt = 0;
        int i = 0;
        while ( i <= n-k ) {
            bool check = false;
            int j = i;
            while ( j < i+k ) {
                if ( a[j] == 1 ) {
                    check = true;
                    break;
                }
                j++;
            }
            if ( check ) i++;
            else {
                cnt++;
                i = j;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
