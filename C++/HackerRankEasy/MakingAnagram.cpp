#include <string>
#include <unordered_map>
using namespace std;
int makeAnagram(string a, string b) {
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    for (char c : a) ++map1[c];
    for (char c : b) ++map2[c];
    int res = 0;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (char letter : alphabet) res += abs(map1[letter]-map2[letter]);
    return res;
}