#include <vector>
using namespace std;
class Vector2D {
public:
    vector<int> vec1D;
    vector<int>::iterator it;
    Vector2D(vector<vector<int>>& vec) {
        for (vector<int> v : vec) for (int val : v) vec1D.push_back(val);
        it = vec1D.begin();
    }
    
    int next() {
        int ret = *it;
        ++it;
        return ret;
    }
    
    bool hasNext() {
        return it !=vec1D.end();
    }
};