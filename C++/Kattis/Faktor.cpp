#include <bits/stdc++.h>
using namespace std;
int main() {
    int A; cin >> A; //publish
    int B; cin >> B; //impact factor
    int ans = 1 + (A * (B-1));
    cout << ans << endl;
    return 0;
}