/*
Priority Queue
*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums){
            counts[num] += 1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (const auto& [num, count] : counts){
            minHeap.push({count, num});
            if (minHeap.size() > k){
                // remove the number with lowest count
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()){
            result.push_back(minHeap.top().second); // num
            minHeap.pop();
        }
        return result;
    }
};
