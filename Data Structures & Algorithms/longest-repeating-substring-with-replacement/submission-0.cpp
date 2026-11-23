class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCount;

        int left = 0;
        int longest = 0;
        int mostCommonCharacterCount = 0;

        for (int right = 0; right < s.size(); right++){
            char c = s[right];
            charCount[c] += 1;

            mostCommonCharacterCount = max(
                mostCommonCharacterCount,
                charCount[c]
            );

            int windowSize = right - left + 1;
            if (windowSize - mostCommonCharacterCount > k){
                charCount[s[left]] -= 1;
                left += 1;
            }

            longest = max(longest, right - left + 1);
        }
        return longest;



        
    }
};
