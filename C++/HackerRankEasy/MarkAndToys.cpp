#include <vector>
#include <algorithm>
using namespace std;
int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int res = 0;
    for (int i = 0; i < prices.size(); ++i) {
        int currPrice = prices[i];
        if (k >= currPrice) k -= currPrice;
        else break;
        ++res;
    }
    return res;
}