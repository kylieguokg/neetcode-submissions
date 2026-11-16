class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // sort nums and get count of each num
        unordered_map<int, int> num_count = {};

        for (int num : nums){
            num_count[num] += 1;
        }

        vector<int> uniqueNums;
        for (const auto& [num, count] : num_count) {
            uniqueNums.push_back(num);
        }

        sort(uniqueNums.begin(), uniqueNums.end(), [&](int a, int b){
            return num_count[a] > num_count[b];
        });
        uniqueNums.resize(k);
        return uniqueNums;
    }
};
