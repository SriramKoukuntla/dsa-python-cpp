#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int helper(vector<int>& a, int l, int r, int count, int res) {
    if (count == 0) return res; 

    int resA = helper(a, l-1, r, count-1, res+a[l]);
    int resB = helper(a, l, r+1, count-1, res+a[r]);

    cout << "l: " << l << " r: " << r << " resA: " << resA << " resB: " << resB << endl;

    // int resA;
    // if (l + 1 == r) {
    //     resA = helper(a, ogL, ogR, ogR+1, r, res + a[l]);
    // }
    // else {
    //     resA = helper(a, ogL, ogR, l+1, r, res + a[l]);
    // }
    // int resB;
    // if (r - 1 == l) {
    //     resB = helper(a, ogL, ogR, l, ogL-1, res + a[r]);
    // }
    // else {
    //     resB = helper(a, ogL, ogR, l, r-1, res + a[r]);
    // }
    
    return max(resA, resB);
}

// []-[]-[1]-[]-[]-[]-[1]-[]-[]


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        int k;
        cin >> n;
        cin >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        cout << "n: " << n << " k: " << k << endl;
        int resA = helper(nums, k-1-1, ((int)nums.size())-k+1, k-1, 0);
        int resB = 0;
        for (int i = k-1; i <= ((int)nums.size())-k; ++i) resB += nums[i];
        // int res = 0;
        int res = resA + resB;
        cout << "res: " << res << endl;; 
        // cout << "resA: " << resA << " resB: " << resB << endl;
    }

    return 0;
}