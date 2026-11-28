class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> descending_weight;

        for (int stone : stones){
            descending_weight.push(stone);
        }

        while (descending_weight.size() > 1){
            int x = descending_weight.top();
            descending_weight.pop();
            int y = descending_weight.top();
            descending_weight.pop();

            descending_weight.push(abs(x - y));
        }

        return descending_weight.top();
        
    }
};
