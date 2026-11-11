class Solution {
public:
    bool isAnagram(string s, string t) {
        int chars[26] = {};
        for (char c : s){
            chars[c - 'a'] += 1;
        }

        for (char c : t){
            chars[c - 'a'] -= 1;
        }

        for (int count : chars){
            if (count != 0){
                return false;
            }
        }
        return true;
        
    }
};
