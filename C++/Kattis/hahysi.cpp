#include <bits/stdc++.h>
using namespace std;
long long helper(long long x) {
    int mod = 1000000000 + 7;
    long long a = x;
    long long b = x-1;
    if (a % 2 == 0) a/=2;
    else b /= 2;
    long long res = (((a % mod) * (b % mod)) % mod);
    return res;
}
int main() {
    long long n; cin >> n;
    long long m; cin >> m;
    int res = 0;
    int mod = 1000000000 + 7;
    long long temp1 = helper(n);
    long long temp2 = helper(m);
    res = (temp1 * temp2) % mod;
    cout << res << endl;
    return 0;
}
