#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<vector<int>>> tab(piles.size(), vector<vector<int>>(piles.size(), vector<int>(2, -1)));
        for (int i = 0; i < piles.size(); ++i) {
            tab[i][i][0] = piles[i];
            tab[i][i][1] = -piles[i];
        }

        //simulate every size game
        for (int i = 1; i < piles.size(); ++i) {
            for (int j = 0; j < piles.size()-i; ++j) {
                int l = j;
                int r = j+i;

                tab[l][r][0] = max(piles[l] + tab[l+1][r][1], piles[r] + tab[l][r-1][1]);

                tab[l][r][1] = max(-piles[l] + tab[l+1][r][0], -piles[r] + tab[l][r-1][0]);
            }
        }
        return tab[0][piles.size()-1][0] > 0;
    }
};
//state space = who's turn it is, index l, index r
//tab[l][r][0,1]
//true means alice's turn. false means bob's turn

//alice starts first

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<vector<int>>> tab(piles.size(), vector<vector<int>>(piles.size(), vector<int>(2, -1)));
        for (int i = 0; i < piles.size(); ++i) {
            tab[i][i][0] = piles[i];
            tab[i][i][1] = -piles[i];
        }

        //simulate every size game
        for (int i = 1; i < piles.size(); ++i) {
            for (int j = 0; j < piles.size()-i; ++j) {
                int l = j;
                int r = j+i;
                //choose piles[l] for alice
                if (piles[l] + tab[l+1][r][1] > piles[r] + tab[l][r-1][1]) {
                    tab[l][r][0] = piles[l] + tab[l+1][r][1];
                }
                else {
                    tab[l][r][0] = piles[r] + tab[l][r-1][1];
                }

                //choose piles[l] for Bob
                if (-piles[l] + tab[l+1][r][0] < -piles[r] + tab[l][r-1][0]) {
                    tab[l][r][1] = -piles[l] + tab[l+1][r][0];
                }
                else {
                    tab[l][r][1] = -piles[r] + tab[l][r-1][0];
                }
            }
        }
        return tab[0][piles.size()-1][0] > 0;
    }
};
//state space = who's turn it is, index l, index r
//tab[l][r][0,1]
//true means alice's turn. false means bob's turn

//alice starts first