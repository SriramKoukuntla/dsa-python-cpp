#include <unordered_set>
#include <vector>
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