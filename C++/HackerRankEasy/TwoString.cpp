#include <string>
#include <unordered_map>
using namespace std;
string twoStrings(string s1, string s2) {
    unordered_map<char, int> map;
    for (char c : s1) ++map[c];
    for (char c : s2) if (map.find(c) != map.end()) return "YES";
    return "NO";
}
