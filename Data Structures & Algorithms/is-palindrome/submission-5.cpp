class Solution {
public:
    bool isPalindrome(string s) {
        int startIndex = 0;
        int endIndex = s.size() - 1;
        while (startIndex < endIndex){
            if (!isalnum(s[startIndex])){
                startIndex++;
            } else if (!isalnum(s[endIndex])){
                endIndex--;
            } else {
                if (tolower(s[startIndex]) != tolower(s[endIndex])){
                    return false;
                }
                startIndex++;
                endIndex--;
            }
        }
        return true;
        
    }
};
