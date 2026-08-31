#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    MyQueue() {}
    
    void push(int x) {
        if (s2.empty()) {
            s2.push(x);
            while(!s1.empty()) { //move s1 to s3
                s3.push(s1.top());
                s1.pop();
            }
            while(!s3.empty()) { //move s3 to s2
                s2.push(s3.top());
                s3.pop();
            }
        }
        else {
            s1.push(x);
            while(!s2.empty()){ //move s2 to s3
                s3.push(s2.top());
                s2.pop();
            }
            while(!s3.empty()){ //move s3 to s1
                s1.push(s3.top());
                s3.pop();
            }
        }
    }
    
    int pop() {
        int temp = peek();
        if (!s1.empty()) s1.pop();
        if (!s2.empty()) s2.pop();
        return temp;
    }
    
    int peek() {
        int temp = 0;
        if (!s1.empty()) temp = s1.top();
        if (!s2.empty()) temp = s2.top();
        return temp;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */