#include <bits/stdc++.h>
using namespace std;

int main() {
    int m; cin >> m;
    int n; cin >> n;
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        string lane; cin >> lane;
        for (int j = 0; j < m; ++j) {
            if (lane[j] == '.') count++;
        }
    }
    double res = count / (1.0 * m * n);
    cout << res << endl;
    return 0;
}