#include <vector>
using namespace std;
int hourglassSum(vector<vector<int>> arr) {
    int res = INT_MIN;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
        int center = arr[i][j];        
        int upperPortion = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1];
        int lowerPortion = arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
        int temp = center + upperPortion + lowerPortion;
        res = max(res, temp);
        }
    }
    return res;
}