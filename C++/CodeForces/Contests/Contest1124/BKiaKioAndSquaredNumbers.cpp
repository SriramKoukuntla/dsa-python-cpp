#include <bits/stdc++.h>
using namespace std;

long long factorial(int a) {
    if (a == 1 || a == 0) return 1; 
    return a * factorial(a-1);
}

int transform (int a) {
    int tempNum = 0;
    while (a != 0) {
        tempNum += (int)pow((a % 10), 2);
        a /= 10;
    }
    return tempNum;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        unordered_map<int, int> endNumCount; 
        //takes end num, and we keep track of how many times it has happened
        vector<int> lightHouseNums(n);
        for (int j = 0; j < n; ++j) cin >> lightHouseNums[j];
        for (int j = 0; j < n; ++j) {
            int currNum = lightHouseNums[j];
            for (int z = 0; z < 100; ++z) {
                currNum = transform(currNum);
            }
            endNumCount[currNum]++;
        }
        int res = 0;
        for (auto [endNum, count] : endNumCount) {
            if (count == 1) continue;
            // res += (int)(factorial(count)) / (factorial(2) * factorial(count-2));
            res += (int)((1LL * count * (count - 1)) / 2); //talk to hassan about this modified counting formula
        }
        cout << res << endl;
    }
    return 0; 
}

// C(3, 2) = 3!/2!(1)!
// 2!/0!(2!)
