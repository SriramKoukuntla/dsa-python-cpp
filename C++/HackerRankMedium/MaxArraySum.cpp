#include <vector>
using namespace std;
int helper(vector<int>& arr, int i, vector<int>& mem, vector<bool>& computed) {
    if (i >= arr.size()) return 0;
    if (computed[i]) return mem[i];
    int choose = helper(arr, i+2, mem, computed) + arr[i];
    int skip = helper(arr, i+1,mem, computed);
    int res = max(choose, skip);
    computed[i] = true;
    mem[i] = res;
    return res;
}

int maxSubsetSum(vector<int> arr) {
    vector<int> mem(arr.size());
    vector<bool> computed(arr.size(), false);
    return helper(arr, 0, mem, computed);
}