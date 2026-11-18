class Solution {
   public:
    vector<int> getLastTwoNums(stack<int>& nums){
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
                auto num = getLastTwoNums(nums);
                nums.push(num[0] + num[1]);
            } else if (token == "-") {
                auto num = getLastTwoNums(nums);
                nums.push(num[0] - num[1]);
            } else if (token == "*") {
                auto num = getLastTwoNums(nums);
                nums.push(num[0] * num[1]);
            } else if (token == "/") {
                auto num = getLastTwoNums(nums);
                nums.push(num[0] / num[1]);
            } else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};
