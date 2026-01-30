#include <list>
using namespace std;
class MyStack {
public:
    list<int> q1;
    list<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        if (q1.empty()) {
            q1.push_back(x);
            while (!q2.empty()) {
                q1.push_back(q2.front());
                q2.pop_front();
            }
        }
        else {
            q2.push_back(x);
            while (!q1.empty()) {
                q2.push_back(q1.front());
                q1.pop_front();
            }
        }
    }
    
    int pop() {
        int val = top();
        if (!q1.empty()) q1.pop_front();
        else q2.pop_front();
        return val;
    }
    
    int top() {
        if (!q1.empty()) return q1.front();
        else return q2.front();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */