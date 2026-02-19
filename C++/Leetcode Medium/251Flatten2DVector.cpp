class Vector2D {
public:
    vector<vector<int>> v;
    int row;
    int col;
    void advance() {
        while (row < v.size() && (v[row].size() == 0 || col == v[row].size())) {
            ++row;
            col = 0;
        }
    }

    Vector2D(vector<vector<int>>& vec) {
        v = vec;
        row = 0;
        col = 0;
        advance();
    }
    
    int next() {
        advance();
        int val = v[row][col];
        ++col;
        advance();
        return val;
    }
    
    bool hasNext() {
        advance();
        return (row < v.size());
        
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

 
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