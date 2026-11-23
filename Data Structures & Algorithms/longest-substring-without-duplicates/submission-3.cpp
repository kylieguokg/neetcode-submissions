class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = 0;
        int maxLength = 0;
        unordered_set<char> uniqueChars;

        for (int right = 0; right < s.size(); right++) {
            while (uniqueChars.contains(s[right])){
                uniqueChars.erase(s[left]);
                left += 1;
            }
            uniqueChars.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);

        }
        return maxLength;
        
    }
};
