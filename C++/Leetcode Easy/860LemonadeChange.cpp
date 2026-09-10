#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change = {0, 0, 0}; //change[0] means 5$, change[1] means 10$, change[2] means 20$

        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) ++change[0];
            else if (bills[i] == 10) {
                ++change[1];
                if (change[0] >= 1) {
                    --change[0];
                }
                else {
                    return false;
                }
            }
            else if (bills[i] == 20) {
                ++change[2];
                if (change[1] >= 1 && change[0] >= 1) {
                    --change[1];
                    --change[0];
                }
                else if (change[0] >= 3) {
                    change[0] -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};