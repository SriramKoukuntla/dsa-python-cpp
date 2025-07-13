#include <unordered_map>
#include <iterator>
using namespace std;

class Solution{
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.size(); i++){
            hashmap[s[i]] += 1;
            hashmap[t[i]] -= 1;
        }
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it){
            if (it->second != 0) return false;
        }
        return true;
    }
}