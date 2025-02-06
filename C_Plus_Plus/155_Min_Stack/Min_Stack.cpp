#include <vector>
#include <limits>
#include <stack>

using namespace std;
class MinStack {
private:
        vector<int> container;
        stack<int> minValues;
        int topIndex;
        int min;
public:
    MinStack() {
        topIndex = -1;
        min = __INT_MAX__;
    }
    
    void push(int val) {
        ++topIndex;
        container.push_back(val);
        if(minValues.empty() || val <= minValues.top())
            minValues.push(val);
    }
    
    void pop() {
        if(container[topIndex] == minValues.top())
            minValues.pop();
        --topIndex;
        container.pop_back();
    }
    
    int top() {
        return container[topIndex];
    }
    
    int getMin() {
        return minValues.top();
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