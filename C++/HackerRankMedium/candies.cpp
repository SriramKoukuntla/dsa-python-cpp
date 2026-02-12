#include <vector>
using namespace std;
long candies(int n, vector<int> arr) {
    vector<long> c(n, 1);

    // left to right
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) c[i] = c[i - 1] + 1;
    }

    // right to left
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > arr[i + 1]) c[i] = max(c[i], c[i + 1] + 1);
    }

    long res = 0;
    for (long x : c) res += x;
    return res;


    // vector<int> candies(arr.size(), 1);
    // for (int i = arr.size()-1; i >= 0; --i) {
    //     for (int j = i+1; j < arr.size(); ++j) {
    //         if (arr[j-1] > arr[j] && !(candies[j-1] > candies[j])) candies[j-1] = candies[j]+1;   
    //         else if (arr[j-1] < arr[j] && !(candies[j-1] < candies[j])) candies[j] = candies[j-1]+1; 
    //         else break;        
    //     }
    // }
    // long res = 0;
    // for (int candy : candies) res += candy;
    // return res;

}
