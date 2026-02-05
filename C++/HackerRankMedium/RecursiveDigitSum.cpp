#include <string>
#include <iostream>
using namespace std;
int superDigit(string n, int k) {
    long long res = 0;
    for (int i = 0; i < n.size(); ++i) res += stoi(string(1, n[i])); 
    res *= k;
    if (res >= 10) res = superDigit(to_string(res), 1);
    return res;
}