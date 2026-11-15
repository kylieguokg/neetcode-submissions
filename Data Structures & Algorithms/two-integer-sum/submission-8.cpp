class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // < number already seen, its index >
        unordered_map<int, int> seen = {};

        for (int i = 0; i < size(nums); i++){
            int complement = target - nums[i];
            auto complementIndex = seen.find(complement);
            if (complementIndex != seen.end()){
                return { complementIndex -> second , i};
            }
            seen[nums[i]] = i;
        }
        return { -1, -1 };
    }
};
