#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int m; cin >> m;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0; i < n; ++i) {
        int currNum; cin >> currNum;
        minVal = min(minVal, currNum);
        maxVal = max(maxVal, currNum);
    }
    if (maxVal - minVal > 1) cout << "ósvífinn kapítalisti";
    else cout << "da komrad";

    return 0;
}