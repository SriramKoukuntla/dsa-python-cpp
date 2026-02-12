#include <vector>
using namespace std;
long largestRectangle(vector<int> h) {    
    vector<int> stack;          
    long res = 0;

    for (int i = 0; i <= h.size(); ++i) {
        long curr = (i == h.size()) ? 0 : h[i];  // sentinel 0 at the end

        while (!stack.empty() && h[stack.back()] > curr) {
            int top = stack.back();
            stack.pop_back();

            long height = h[top];
            int leftLess = stack.empty() ? -1 : stack.back();
            long width = i - leftLess - 1;   // from leftLess+1 to i-1
            res = max(res, height * width);
        }
        stack.push_back(i);
    }

    return res;
    // long res = 0;
    // for (int i = 0; i < h.size(); ++i) {
    //     if (i != 0 && h[i] <= h[i-1]) continue;
    //     long bottleNeck = INT_MAX;
    //     for (int j = i; j < h.size(); ++j) {
    //         bottleNeck = min(bottleNeck, (long)h[j]);
    //         res = max(res, ((j-i+1) * bottleNeck));
    //     }
    // }
    // return res;
}