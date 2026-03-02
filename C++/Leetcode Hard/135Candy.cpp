#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> resVec(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) if (ratings[i] > ratings[i-1]) resVec[i] = resVec[i-1]+1;
        for (int i = ratings.size()-2; i >= 0; --i) if (ratings[i] > ratings[i+1] && resVec[i] <= resVec[i+1]) resVec[i] = resVec[i+1]+1;
        int res = 0;
        for (int candy : resVec) res += candy;
        return res;
    }
};
