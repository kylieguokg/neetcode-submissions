class Solution {
   public:
    string encode(vector<string>& strs) {
        string result;
        for (string str : strs) {
            result += '*' + to_string(str.size()) + '*';
            result += str;
        }
        cout << result;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int curLength = -1;
        int i = 0;
        int delimeterCount = 0;
        while (i < s.length()) {
            if (curLength >= 0) {
                i += 1;
                string curWord = "";
                int curIndex = 0;
                while (curIndex < curLength) {
                    curWord += s[i];
                    i += 1;
                    curIndex += 1;
                }
                decoded.push_back(curWord);
                curLength = -1;
            } else {
                string length;
                char c = s[++i];
                while (c != '*') {
                    length += c;
                    c = s[++i];
                }
                curLength = stoi(length);
            }
        }
        return decoded;
    }
};
