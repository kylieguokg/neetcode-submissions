/*
Using bucket sort - a number can have at most count k;
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

        int kCount = 0;
        vector<int> result;
        for (int i = maxCount; i >= 0; i--){
            if (kCount == k)
            {
                break;
            }
            if (buckets[i].size()){
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
                kCount += buckets[i].size();
            }
        }
        return result;
    }
};
