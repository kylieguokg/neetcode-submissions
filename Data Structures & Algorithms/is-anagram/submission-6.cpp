class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        int letterCount[26];

        for (char c : s){
            letterCount[c - 'a'] += 1;
        }

        for (char c : t){
            letterCount[c - 'a'] -= 1;
        }

        for (int count : letterCount){
            if (count != 0){
                return false;
            }
        }
        return true;
        
    }
};
