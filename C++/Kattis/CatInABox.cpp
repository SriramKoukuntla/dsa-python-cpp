#include <bits/stdc++.h>
using namespace std;
int main(){
    int h; cin >> h;
    int w; cin >> w;
    int l; cin >> l;
    int c; cin >> c;
    if (h * w * l > c) {
        cout << "SO MUCH SPACE";
    }
    else if (h * w * l < c) {
        cout << "TOO TIGHT";
    }
    else {
        cout << "COZY";
    }
    return 0;
}