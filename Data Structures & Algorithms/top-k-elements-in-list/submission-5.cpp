class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // sort nums and get count of each num
        unordered_map<int, int> num_count = {};
        unordered_set<int> uniqueNums = {};

        for (int num : nums){
            num_count[num] += 1;
            uniqueNums.insert(num);
        }

        vector<int> uniqueNumsSorted(uniqueNums.begin(), uniqueNums.end());
        sort(uniqueNumsSorted.begin(), uniqueNumsSorted.end(), [&](int a, int b){
            if (num_count[a] != num_count[b]){
                return num_count[a] > num_count[b];
            }
            return a < b;
        });

        int kCount = 1;
        vector<int> topKFrequent = { uniqueNumsSorted[0] };
        for (int i = 1; i < size(uniqueNumsSorted); i++){
            if (kCount == k){
                break;
            }
            topKFrequent.push_back(uniqueNumsSorted[i]);
            kCount ++;
        }
        return topKFrequent;
    }
};
