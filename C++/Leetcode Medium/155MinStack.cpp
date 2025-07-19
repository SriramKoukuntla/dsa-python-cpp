#include <vector>
#include <tuple>
using namespace std;
class MinStack {
public:

    vector<tuple<int, int>> stack;
    //1st is num, 2nd is minNum
    MinStack() {}
    
    void push(int val) {
        if (stack.size() == 0 || get<1>(stack.back()) > val) stack.emplace_back(val, val);
        else stack.emplace_back(val, get<1>(stack.back()));
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return get<0>(stack.back());
    }
    
    int getMin() {
        return get<1>(stack.back());
    }
};