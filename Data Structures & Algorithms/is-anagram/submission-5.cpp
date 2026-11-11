class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        int count[26] = {};
        for (char c : s){
            count[c - 'a'] += 1;
        }

        for (char c : t){
            count[c - 'a'] -= 1;
        }

        for (int c : count){
            if (c != 0){
                return false;
            }
        }
        return true;
        
    }
};
