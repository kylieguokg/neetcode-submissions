class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exists(nums.begin(), nums.end());
        int maxLength = 0;
        for (int num : exists){
            if (!exists.contains(num - 1)){
                int curNum = num;
                int curLength = 1;
                while (exists.contains(++curNum)){
                    curLength ++;
                }
                maxLength = max(curLength, maxLength);
            }
        }
        return maxLength;
    }
};
