class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> timeMap;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto t = timeMap.find(key);
        if (t == timeMap.end()){
            return "";
        }

        const auto& entries = t->second;
        int left = 0;
        int right = entries.size() - 1;
        int result = -1;

        while (left <= right){
            int mid = left + (right - left)/2;

            if (entries[mid].first <= timestamp){
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (result == -1){
            return "";
        }
        return entries[result].second;
    }
};
