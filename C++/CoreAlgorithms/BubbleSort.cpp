#include <vector>
using namespace std;
vector<int> sort(vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size()-1; ++j) if (a[j] > a[j+1]) swap(a[j], a[j+1]);
    }
    return a;
}