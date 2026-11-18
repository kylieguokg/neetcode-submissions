class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> waiting; // waiting indexes
        int n = temperatures.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            while (!waiting.empty() && 
                    temperatures[i] > temperatures[waiting.top()]) {
                int prevIndex = waiting.top();
                result[prevIndex] = i - prevIndex;
                waiting.pop();
            }
            waiting.push(i);
        }

        return result;
    }
};
