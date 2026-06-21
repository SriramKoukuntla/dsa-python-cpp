#include <vector>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res = {};
        for (int asteroid : asteroids) {
            while (true) {
                if (asteroid > 0 || res.empty() || res.back() < 0) {res.push_back(asteroid); break;}
                else if (res.back() == abs(asteroid)) {res.pop_back(); break;}
                else if (res.back() < abs(asteroid)) res.pop_back();
                else if (res.back() > abs(asteroid)) break;
            }
        }
        return res;
    }
};