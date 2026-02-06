#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
void whatFlavors(vector<int> cost, int money) {
    unordered_map<int, int> map;
    for (int i = 0; i < cost.size(); ++i) {
        if (map.find(money-cost[i]) != map.end()) {
            cout << map[money-cost[i]]+1 << " " << i+1 << endl;
            return;
        }
        map[cost[i]] = i;
    }
    cout << "This should never print unless not possible" << endl;
    return;
}