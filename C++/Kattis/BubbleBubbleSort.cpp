#include <bits/stdc++.h>
using namespace std;

bool inCorrectOrder(vector<int>& arr) {
    for (int i = 0; i < arr.size()-1; ++i) {
        if (arr[i] > arr[i+1]) return false;
    }
    return true;
}

int main() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> bubbles;
    for (int i = 0; i < n; ++i) {
        int temp; cin >> temp;
        bubbles.push_back(temp);
    }
    int counter = 0;
    while (!inCorrectOrder(bubbles)) {
        for (int i = 0; i < n-k+1; ++i) {
            sort(bubbles.begin() + i, bubbles.begin() + k + i);
        }
        ++counter;
    }
    cout << counter << endl;

    return 0;
}