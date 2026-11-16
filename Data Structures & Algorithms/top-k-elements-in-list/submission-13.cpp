/*
Using bucket sort - a number can have at most count n;
O(n) average
O(n + m) worst case - m representing number of buckets;
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts = {};
        int maxCount = 0;
        for (int num : nums){
            counts[num] += 1;
            if (counts[num] > maxCount){
                maxCount = counts[num];
            }
        } 

        vector<vector<int>> buckets(maxCount + 1);
        for (const auto& [num, count] : counts){
            buckets[count].push_back(num);
        }

        vector<int> result;
        result.reserve(k);
        for (int i = maxCount; i >= 0; i--){
            for (int num : buckets[i]){
                if (result.size() == k){
                    return result;
                }
                result.push_back(num);
            }
        }
        return result;
    }
};
