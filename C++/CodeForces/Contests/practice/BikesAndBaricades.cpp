#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    double res = DBL_MAX;
    while (n--) {
        double x1;
        double y1;
        double x2;
        double y2;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;
        double slope = (y2-y1)/(x2-x1);
        double yIntercept = y1 - (slope * x1);
        if (yIntercept > 0) res = min(res, yIntercept);
    }
    if (res == DBL_MAX) res = -1;
    cout << res;
    
    return 0;
}