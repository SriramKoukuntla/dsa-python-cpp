#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //Sort both lists in ascending order
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0;
        while (!g.empty() && !s.empty()) {
            if (g.back() <= s.back()) {
                g.pop_back();
                s.pop_back();
                ++res;
            }
            else g.pop_back();
        }
        return res;
    }
};

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //Count how many we can satisfy
        int res = 0;
        unordered_map<int, int> gFreq;
        unordered_map<int, int> sFreq;
        for (int greed : g) ++gFreq[greed];
        for (int size : s) ++sFreq[size];

        //Satifify the greediest child
        priority_queue<pair<int, int>> greediest; //max heap
        for (auto [greed, freq] : gFreq) greediest.push({greed, freq});
        priority_queue<pair<int, int>> biggest;
        for (auto [size, freq] : sFreq) biggest.push({size, freq});


        int numCookiesAtLeastGreed = 0;
        while (!greediest.empty()) {
            auto [greed, freq] = greediest.top();
            greediest.pop();

            //Need to keep track of all cookies that a child is elligable to eat
            while (!biggest.empty() && biggest.top().first >= greed) {
                numCookiesAtLeastGreed += biggest.top().second;
                biggest.pop();
            }

            int numCookiesAte = min(freq, numCookiesAtLeastGreed);
            numCookiesAtLeastGreed -= numCookiesAte;
            res += numCookiesAte;
        }

        return res; 
    }
};