class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> waiting;
        waiting.push({temperatures[0], 0});
        vector<int> warmerTempWait(temperatures.size(), 0);

        for (int i = 1; i < temperatures.size(); i++){
            while (!waiting.empty() &&
                    temperatures[i] > waiting.top().first){
                // printf("temp: %d wait: %d %d\n", temperatures[i], waiting.top().first, waiting.top().second);
                warmerTempWait[waiting.top().second] = i - waiting.top().second;
                waiting.pop();
            }
            waiting.push({temperatures[i], i});
        }

        return warmerTempWait;
    }
};
