class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exists(nums.begin(), nums.end());
        unordered_set<int> startNums;
        // find possible start points
        for (int num : nums){
            if (!exists.contains(num - 1)){
                startNums.insert(num);
            }
        }

        int maxLength = 0;
        for (const auto& start : startNums){
            int num = start;
            int curLength = 1;
            while (exists.contains(++num)){
                curLength ++;
            }
            maxLength = max(curLength, maxLength);
        }
        return maxLength;
        
    }
};
