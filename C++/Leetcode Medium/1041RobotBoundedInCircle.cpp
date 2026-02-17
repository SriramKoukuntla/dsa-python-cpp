#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<char> directions = {'N', 'E', 'S', 'W'};
        int direction = 0;
        int x = 0;
        int y = 0;
        for (char c : instructions) {
            if (c == 'L') direction = (direction-1 + 4) % 4;
            else if (c == 'R') direction = (direction+1) % 4;
            else if (c == 'G') {
                char facing = directions[direction];
                if (facing == 'N') ++y;
                else if (facing == 'E') ++x;
                else if (facing == 'S') --y;
                else if (facing == 'W') --x;
            }
        }
        if (abs(x) + abs(y) > 0 && directions[direction] == 'N') return false;
        return true;
    }
};