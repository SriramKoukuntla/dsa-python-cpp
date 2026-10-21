#include <bits/stdc++.h>
using namespace std;
int main() {
    string input; cin >> input;
    int index = 0;
    string numDie;
    while (input[index] != 'd') numDie += input[index++];
    index++;
    string sidedDie;
    while (input[index] != '+') sidedDie += input[index++];
    index++;
    string addedValue;
    while (index < (int)input.size()) addedValue += input[index++];



    double ans = (stoi(numDie) * ((1 + stoi(sidedDie)))/2.0) + stoi(addedValue);
    cout << ans << endl;
    return 0;
}