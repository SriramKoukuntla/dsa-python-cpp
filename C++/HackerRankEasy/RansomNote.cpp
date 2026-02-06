#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> usableWords;
    for (string word : magazine) ++usableWords[word];
    
    for (string word : note) {
        if (usableWords[word]-- == 0) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}