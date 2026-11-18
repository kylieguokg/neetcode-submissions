class Solution {
   public:
    pair<int, int> getLastTwoNums(stack<int>& nums){
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        return { num1, num2 };
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (string token : tokens) {
            if (token == "+") {
                auto [num1, num2] = getLastTwoNums(nums);
                nums.push(num1 + num2);
            } else if (token == "-") {
                auto [num1, num2] = getLastTwoNums(nums);
                nums.push(num1 - num2);
            } else if (token == "*") {
                auto [num1, num2] = getLastTwoNums(nums);
                nums.push(num1 * num2);
            } else if (token == "/") {
                auto [num1, num2] = getLastTwoNums(nums);
                nums.push(num1 / num2);
            } else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};
