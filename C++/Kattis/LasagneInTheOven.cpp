#include <bits/stdc++.h>
using namespace std;
int main() {
    int input; cin >> input;
    //(32°F − 32) × 5/9 = 0°C
    double output = ((input - 32) * (5.0 / 9.0));
    int realoutput = floor(output + 0.5);
    cout << realoutput << endl;
    return 0;
}