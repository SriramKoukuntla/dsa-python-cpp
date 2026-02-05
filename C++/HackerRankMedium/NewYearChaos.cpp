#include <vector>
using namespace std;
void minimumBribes(vector<int> q) {
    int res = 0;
    for (int i = 0; i < q.size(); ++i) {
        int currVal = q[i];
        int desVal = i+1;
        if (currVal > desVal+2) {
            cout << "Too chaotic" << endl;
            return;
        }
        int start = max(0, currVal-2-1);
        for (int j = start; j < i; ++j) if (q[j] > currVal) ++res;
    }
    cout << res << endl;
}