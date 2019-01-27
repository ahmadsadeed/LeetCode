class MinStack {
    stack<int> iStack1;
    stack<int> iStack2;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        iStack1.push(x);
        if (iStack2.empty() || x <= getMin()) {
            iStack2.push(x);
        }
    }

    void pop() {
        if (iStack1.top() == getMin()) {
            iStack2.pop();
        }
        iStack1.pop();
    }

    int top() {
        return iStack1.top();
    }

    int getMin() {
        return iStack2.top();
    }
};
