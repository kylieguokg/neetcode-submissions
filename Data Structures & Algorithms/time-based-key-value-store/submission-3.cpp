class TimeMap {
public:
    map<string, pair<vector<int>, vector<string>>> timeMap;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].first.push_back(timestamp);
        timeMap[key].second.push_back(value);
    }
    
    string get(string key, int timestamp) {
        vector<int> timestamps = timeMap[key].first;
        int timeStampIdx = binarySearchMaxNumBeforeTarget(timestamps, timestamp);
        if (timeStampIdx == -1){
            return "";
        }
        return timeMap[key].second[timeStampIdx];
        
    }

    int binarySearchMaxNumBeforeTarget(vector<int>& vec, int target){
        int left = 0;
        int right = vec.size() - 1;
        int mid = 0;

        // cout << "meow\n";
        while (left <= right){
            mid = left + (right - left)/2;
            // cout << vec[mid] << "\n";
            if (vec[mid] == target){
                return mid;
            }
            if (vec[mid] < target){
                if (mid + 1 >= vec.size() || vec[mid + 1] > target){
                    return mid;
                }
            }

            if (vec[mid] > target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << mid << "moop\n";
        return -1;
    }
};
