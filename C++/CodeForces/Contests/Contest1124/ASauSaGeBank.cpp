#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; //num test cases
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        int k;
        cin >> n;
        cin >> k;
        cout << (int)(pow(2, n-(k-1)) + (2 * (k-1))) << endl; //pow returns double
    }

    //(2^(n-(k-1))) + (2 * (k-1))
    return 0;
}