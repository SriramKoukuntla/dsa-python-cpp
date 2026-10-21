#include <bits/stdc++.h>
using namespace std;

int main() {
    //last group is all pixels that haven't been accounted for
    //If an image has a piexel unique to them, they get a group
    //
    int N; cin >> N;
    int H; cin >> H;
    int W; cin >> W;
    vector<string> images;
    for (int i = 0; i < N; ++i) {
        string tempS;
        for (int j = 0; j < H; ++j) {
            for (int k  = 0; k < W; ++k) {
                char tempC; cin >> tempC;
                tempS += tempC;
            }
        }
        images.push_back(tempS);
    }
    string finalImage = string(H * W, '*');
    images.push_back(finalImage);

    unordered_set<string> groups;
    int length = images[0].size();
    for (int i = 0; i < length; ++i) {
        string temp;
        for (int j = 0; j < images.size(); ++j) {
            temp += images[j][i];
        }
        groups.insert(temp);
    }
    cout << groups.size() << endl;
    return 0;
}