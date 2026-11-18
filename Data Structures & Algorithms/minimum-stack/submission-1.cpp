class MinStack {

    private:
        stack<int> numStack;
        stack<int> minStack;

   public:
    MinStack() { }

    void push(int val) {
        if (minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
        numStack.push(val);
    }

    void pop() {
        if (numStack.top() == minStack.top()){
            minStack.pop();
        }
        numStack.pop();
    }

    int top() {
        return numStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
