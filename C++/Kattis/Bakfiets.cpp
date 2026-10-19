#include <bits/stdc++.h>
using namespace std;

int main() {
    int w; cin >> w;
    int h; cin >> h;
    int a; cin >> a;
    int b; cin >> b;
    long long unsigned firstCalc = 1ULL * min(w, a) * min(h, b);
    long long unsigned secondCalc = 1ULL * min(h, a) * min(w, b);
    long long unsigned  allFit = 1ULL * w * h;
    long long unsigned res = allFit - max(firstCalc, secondCalc);
    cout << res << endl;
    return 0;
}
