#include <vector>
using namespace std;
vector<int> rotLeft(vector<int> a, int d) {
    vector<int> res(a.size());
    for (int i = 0; i < a.size(); ++i) res[(a.size()+i-d) % a.size()] = a[i];
    return res;
}