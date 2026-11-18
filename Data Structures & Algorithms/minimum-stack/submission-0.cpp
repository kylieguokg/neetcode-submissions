class MinStack {

    private:
        stack<int> numStack;
        stack<int> min;

   public:
    MinStack() { min.push(INT_MAX); }

    void push(int val) {
        if (val <= min.top()){
            min.push(val);
        }
        numStack.push(val);
    }

    void pop() {
        if (numStack.top() == min.top()){
            min.pop();
        }
        numStack.pop();
    }

    int top() {
        return numStack.top();
    }

    int getMin() {
        return min.top();
    }
};
