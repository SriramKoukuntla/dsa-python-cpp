#include <unordered_set> 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int n : nums) {
            if (set.find(n) != set.end()) return true;
            set.insert(n);
        }
        return false;
    }
};

//Redid (1/9/2026)
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int i = 0; i < nums.size(); ++i){
            if (hashset.find(nums[i]) != hashset.end()){
                return true;
            }
            hashset.insert(nums[i]);
        }
        return false;
    }
};

#include <unordered_set>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public: 
    bool containsDuplicates(vector<int>& list){
        unordered_set <int> hashset;
        for (int i = 0; i < list.size(); i++){
            if (hashset.find(list.at(i)) != hashset.end()){
                return true;
            }
            hashset.insert(list.at(i));
        }
        return false;
    }
};