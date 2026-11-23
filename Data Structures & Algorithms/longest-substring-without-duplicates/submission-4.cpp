class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> uniqueChars;
        int longestSubstring = 0;
        int left = 0;
        int right = 0;

        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            auto it = uniqueChars.find(c);
            if (it != uniqueChars.end()){ 
                left = max(left, uniqueChars[c] + 1);
            }
            uniqueChars[c] = i;
            right += 1;
            int curSubstring = right - left;
            longestSubstring = max(longestSubstring, curSubstring);
        }
        return longestSubstring;    
    }
};
