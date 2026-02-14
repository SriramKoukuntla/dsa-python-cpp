#include <vector>
using namespace std;
class Solution {
    public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {


        //For every drop of water we need to insert it
        for (int i = 0; i < volume; ++i) {
            int index = k;

            pair<int, int> minHeightAndIdx = {heights[k], k};
            for (int j = k-1; j >= 0; --j) {
                if (heights[j] > heights[j+1]) break;
                if (heights[j] < minHeightAndIdx.first) minHeightAndIdx = {heights[j], j};
            }
            if (minHeightAndIdx.second != k) {
                ++heights[minHeightAndIdx.second];
                continue;
            }

            for (int j = k+1; j < heights.size(); ++j) {
                if (heights[j] > heights[j-1]) break;
                if (heights[j] < minHeightAndIdx.first) minHeightAndIdx = {heights[j], j};
            }
            if (minHeightAndIdx.second != k) {
                ++heights[minHeightAndIdx.second];
                continue;
            }
            
            ++heights[minHeightAndIdx.second];
        }

        return heights;

    }
};