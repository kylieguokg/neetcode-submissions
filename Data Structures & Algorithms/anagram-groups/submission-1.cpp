class Solution {
public:
    string sortString(string str){
        sort(str.begin(), str.end());
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> anagramGroups;

        for (string str : strs){
            string sorted = sortString(str);
            auto groups = anagramGroups.find(sorted);
            if (groups == anagramGroups.end()){
                anagramGroups[sorted] = { str };
            } else {
                anagramGroups[sorted].push_back(str);
            }
        }

vector<vector<string>> groups;

for (const auto& [key, group] : anagramGroups) {
    groups.push_back(group);
}

        return groups;
    }
};
