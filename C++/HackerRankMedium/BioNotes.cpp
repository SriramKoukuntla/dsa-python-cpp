#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> extractElement(string& s) {
    vector<string> res;
    string curr = "";
    int i = 0;
    while (i < s.size()) {
        if (s[i] != '"') {
            while (i != s.size() && s[i] != ',') curr += s[i++];
            ++i;
        }
        else {
            ++i;
            while (!(i == s.size() && s[i-1] == '"') && 
            !(s[i] == ',' && s[i-1] == '"')) {
                if (s[i] == '"' && s[i+1] == '"') {
                    curr += s[i];
                    i += 2;
                }
                curr += s[i++];
            }
            curr.pop_back();
            ++i;
        }
        res.push_back(curr);
        curr = "";    
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string currLine;
    while (getline(cin, currLine)){
        vector<string> e = extractElement(currLine);
        cout << e[0] << ", " << e[6] << " years old, is from " << e[5] << " and is interested in "
        << e[3] << "." << endl;      
    }
    return 0;
}