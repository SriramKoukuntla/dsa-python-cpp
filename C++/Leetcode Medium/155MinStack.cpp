#include <vector>
using namespace std;
class MinStack {
public:
    vector<int> stack;
    vector<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if (minStack.empty() || minStack.back() >= val) minStack.push_back(val);
    }
    
    void pop() {
        if (minStack.back() == stack.back()) minStack.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#include <vector>
#include <algorithm>
using namespace std;

class MinStack {
public:
    vector<int> stack;
    vector<int> minStack;
    MinStack() {

    }
    
    void push(int val) {
        stack.push_back(val);
        if (minStack.empty()) minStack.push_back(val);
        else {
            if (val <= minStack.back()) minStack.push_back(val);
        }
    }
    
    void pop() {
        if (stack.back() == minStack.back()) minStack.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

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