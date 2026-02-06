#include <vector>
#include <algorithm>
using namespace std;
int minimumLoss(vector<long> price) {
    vector<pair<long, int>> newPrices;
    for (int i = 0; i < (int)price.size(); ++i) newPrices.push_back({price[i], i});
    sort(newPrices.begin(), newPrices.end(), greater<pair<long, int>>());

    long res = INT_MAX;
    for (int i = 0; i < (int)price.size(); ++i) {
        for (int j = i+1; j < (int)price.size(); ++j) {
            if (newPrices[j].second < newPrices[i].second) continue;
            long diff = newPrices[i].first - newPrices[j].first;
            res = min(res, diff);            
            break;
        }
    }
    return (int)res;
}