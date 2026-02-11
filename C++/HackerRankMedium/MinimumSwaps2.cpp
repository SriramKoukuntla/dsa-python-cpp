#include <vector>
using namespace std;
int minimumSwaps(vector<int> arr) {
    int swaps = 0;
    for (int i = 0; i < arr.size(); ++i) {
        while (arr[i] != i + 1) {
            int correctIdx = arr[i] - 1;     
            swap(arr[i], arr[correctIdx]);    
            swaps++;
        }
    }
    return swaps;
}