#include <vector>
#include <algorithm>
using namespace std;

int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int res = INT_MAX;
    for (int i = 1; i < arr.size(); ++i) res = min(res, arr[i] - arr[i-1]);
    return res;
}