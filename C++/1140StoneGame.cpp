#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> tab(piles.size()+1, vector<int>(piles.size()+1, 0));
        for (int index = piles.size()-1; index >= 0; --index) {
            for (int M = 1; M <= piles.size(); ++M) {
                tab[index][M] = INT_MIN;
                int sum = 0;
                int upperBoundsPilesTaken = min(2 * M, (int)piles.size() - index);
                for (int pilesTaken = 1; pilesTaken <= upperBoundsPilesTaken; ++pilesTaken) {
                    int pileTakenIndex = index + pilesTaken -1;
                    sum += piles[pileTakenIndex];
                    int newM = max(M, pilesTaken);
                    tab[index][M] = max(tab[index][M], sum - tab[pileTakenIndex+1][newM]);
                }
            }
        }
        int sum = 0;
        for (int pile : piles) sum += pile;
        return (sum + tab[0][1]) / 2;
    }
};