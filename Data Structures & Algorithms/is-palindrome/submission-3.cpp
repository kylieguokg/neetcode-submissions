class Solution {
public:
    bool isPalindrome(string s) {
        int startIndex = 0;
        int endIndex = s.size() - 1;
        while (startIndex < endIndex){
            while (startIndex < endIndex && !isalnum(s[startIndex])){
                startIndex++;
            }
            while (startIndex < endIndex && !isalnum(s[endIndex])){
                endIndex--;
            }
            if ((startIndex < endIndex) &&
                tolower(s[startIndex++]) != tolower(s[endIndex--])){
                return false;
            }
        }
        return true;
        
    }
};
