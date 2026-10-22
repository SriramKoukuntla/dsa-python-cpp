#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >>t;
    for (int p = 0; p < t; ++p) {
        int test = p+1;
        cout << "Test " << test << endl;
        int r; cin >> r;
        int c; cin >> c;
        vector<vector<char>> image(r, vector<char>(c, '_'));
        for (int i = 0; i < r; ++i) {
            string line; cin >> line;
            for (int j = 0; j < c; ++j) {
                image[r-1-i][c-1-j] = line[j];
            }
        }


        for (int i = 0; i < image.size(); ++i) {
            for (int j = 0; j < image[0].size(); ++j) {
                cout << image[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}