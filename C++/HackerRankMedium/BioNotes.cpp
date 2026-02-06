#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// if a comma is contained within a filed then that field must be enclosed in double quotes
//if a double quote is contained within a field then, that field must be enclosed in double quotes

vector<string> extractElement(string& s) {
    vector<string> res;
    int i = 0;
    while (i < s.size()) {
        string curr = "";
        if (s[i] != '"') {
            while (i < s.size() && s[i] != ',') {
                if (s[i] == '"' && s[i+1] == '"') ++i;
                curr += s[i++];
            }
            ++i;
        }
        else {
            ++i;
            while (i < s.size() && !(s[i] == ',' && s[i-1] == '"')) {
                if (s[i] == '"' && s[i+1] == '"') ++i;
                curr += s[i++];
            }
            ++i;
            curr.pop_back();
        }
        res.push_back(curr);
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