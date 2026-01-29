#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        else if (n == 1) return {0, 1};
        vector<int> res(n+1, 0);
        res[0] = 0; res[1] = 1;
        for (int curr = 2; curr <= n; ++curr) {
            int temp = curr % 2;
            temp += res[curr/2];
            res[curr] = temp;
        }
        return res;
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for (int i = 1; i < n+1; ++i){
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};