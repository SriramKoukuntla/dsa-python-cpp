#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> m1;
        for (int i = 0; i < s.size(); ++i){
            ++m1[s[i]];
            --m1[t[i]];
        }

        for (auto& [c, i] : m1) if (i != 0) return false;
        return true;
    }
};

#include <map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        map<char, int> m1;
        map<char, int> m2;
        for (int i = 0; i < s.size(); ++i){
            ++m1[s[i]];
            ++m2[t[i]];
        }

        return m1==m2;
    }
};


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