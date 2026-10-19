#include <bits/stdc++.h>
using namespace std;


int main() {
    int pairs; cin >> pairs;
    vector<int> pile; 
    for (int i = 0; i < pairs * 2; ++i) {
        int temp; cin >> temp;
        pile.push_back(temp);
    }
    reverse(pile.begin(), pile.end());
    vector<int> pile2;

    int counter = 0;
    while (true) {
        if (pile.empty() && pile2.empty()) {
            cout << counter << endl;
            return 0;
        }
        if (pile.empty()){
            cout << "impossible" << endl;
            return 0;
        }
        if (!pile2.empty() && pile.back() == pile2.back()) {
            pile.pop_back();
            pile2.pop_back();
            ++counter;
        }
        else {
            pile2.push_back(pile.back());
            pile.pop_back();
            ++counter;
        }
    }
    return 0;
}