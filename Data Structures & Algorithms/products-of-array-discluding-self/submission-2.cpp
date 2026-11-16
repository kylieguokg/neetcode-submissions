class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        int leftProduct = 1;
        // Left Product: product of all numbers left to i
        for (int i = 0; i < nums.size(); i++){
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // Right Product: product of all numbers right of i
        int rightProduct = 1;
        for (int i = nums.size() - 1; i >= 0; i--){
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return result;
    }
};
