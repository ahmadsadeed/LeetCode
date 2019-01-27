class MyQueue {
    stack<int> myStack1;
    stack<int> myStack2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        myStack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (myStack2.empty()) {
            while (!myStack1.empty()) {
                myStack2.push(myStack1.top());
                myStack1.pop();
            }
        }
        int front = myStack2.top();
        myStack2.pop();
        return front;
    }

    /** Get the front element. */
    int peek() {
        if (!myStack2.empty()) {
            return myStack2.top();
        } else {
            while (!myStack1.empty()) {
                myStack2.push(myStack1.top());
                myStack1.pop();
            }
        }
        int front = myStack2.top();
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return myStack2.empty() && myStack1.empty();
    }
};
