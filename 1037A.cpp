#include<iostream>
using namespace std;

int main () {
    int t; cin >> t;
    while( t-- ) {
        string s; cin >> s;
        int mn = 10;
        for ( int i = 0; i < s.size(); i++ ) {
            int num = s[i] - '0';
            mn = min( mn, num );
        }
        cout << mn << endl;
    }
    return 0;
}
