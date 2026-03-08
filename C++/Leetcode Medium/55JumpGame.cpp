class Solution {
public:
    bool canJump(vector<int>& nums) {
        //From the current position
        //Find the best location to go to for the furthest range
        //Go to that position
        int currPos = 0;
        while (true) {
            if (currPos == nums.size()-1) return true;
            int nextPos = -1;
            int range = currPos;
            for (int i = 1; i <= nums[currPos] && currPos+i < nums.size(); ++i) {
                if (currPos + i + nums[currPos+i] > range) {
                    nextPos = currPos+i;
                    range = currPos + i + nums[currPos+i];
                }
            }
            if (nextPos == -1) return false;
            currPos = nextPos;
        }
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > range) return false;
            range = max(range, i + nums[i]);
        }
        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //From the current position, if we can jump to the last index, return true.
        //From the current position, if we can only jump 0 squares, return false;
        //Our next position should be the one that let's us explore the most range

        int currPos = 0;
        while (true) {
            if (currPos + nums[currPos] >= nums.size()-1) return true;
            if (nums[currPos] == 0) return false;

            int range = currPos;
            int nextPos = -1;
            for (int i = 1; i <= nums[currPos]; ++i) {
                if (currPos + i + nums[currPos + i] > range) {
                    range = currPos + i + nums[currPos + i];
                    nextPos = currPos+i;
                }
            }

            currPos = nextPos;
        }        
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //From the current position, calculate the position that allows us to go the farthest that is within our reach

        int currPos = 0;
        while (true) {
            if (currPos >= nums.size()-1) return true;
            if (nums[currPos] == 0) return false;

            int nextPos = -1;
            int range = currPos;

            for (int nextPosCandidate = currPos+1; nextPosCandidate-currPos <= nums[currPos] && nextPosCandidate < nums.size(); ++nextPosCandidate) {
                if (nextPosCandidate + nums[nextPosCandidate] > range) {
                    range = nextPosCandidate + nums[nextPosCandidate];
                    nextPos = nextPosCandidate;
                }
            }

            currPos = nextPos;
        }
    }
};

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool helper(vector<int>& nums, int currPos, unordered_map<int, bool>& mem) {
        if (currPos == nums.size()-1) return true;
        if (currPos >= nums.size()) return false;
        if (mem.find(currPos) != mem.end()) return mem[currPos];
        for (int i = 1; i <= nums[currPos]; ++i) if (helper(nums, currPos + i, mem)) return true;
        mem[currPos] = false;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> mem;
        return helper(nums, 0, mem);
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = 0;
        while (true){
            if (idx + nums[idx] >= nums.size()-1) return true;
            if (nums[idx] == 0) return false;

            int range = 0;
            int idxJump;

            for (int i = idx; i < idx + nums[idx] + 1; ++i){
                if (i + nums[i] >= range){
                    range = i + nums[i];
                    idxJump = i;
                }
            }

            idx = idxJump;
        }
        return true; 

    }
};