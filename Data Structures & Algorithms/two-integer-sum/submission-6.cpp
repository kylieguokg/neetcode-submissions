class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // < num looking for, index of og number >
        unordered_map<int, int> lookingFor;

        for (int i = 0; i < size(nums); i++){
            int curLookingFor = target - nums[i];
            if (lookingFor.count(curLookingFor) > 0){
                vector<int> indices = { lookingFor[curLookingFor], i};
                return indices;
            }
            lookingFor[nums[i]] = i;
        }

        vector<int> nullResponse = { -1 , -1};
        return nullResponse;
    }
};
