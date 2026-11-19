class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        // sort by position
        vector<pair<int, int>> positionSpeed(position.size());
        for (int i = 0; i < position.size(); i++){
            positionSpeed[i] = { position[i], speed[i] };
        }
        sort(positionSpeed.begin(), positionSpeed.end(), greater<>());
        
        stack<double> fleetTimes;
        for (int i = 0; i < positionSpeed.size(); i++){
            double time = (target - positionSpeed[i].first)/
                        static_cast<double>(positionSpeed[i].second);
            if (fleetTimes.empty() || 
                time > fleetTimes.top()){
                fleetTimes.push(time);
            }
        
        }

        return fleetTimes.size();
    }
};
