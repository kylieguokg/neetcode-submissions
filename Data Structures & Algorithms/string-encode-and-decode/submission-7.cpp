class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (const string& str : strs){
            result += to_string(str.size()) + '#';
            result += str;
        }
        return result;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()){
            int delimeter = s.find('#', i);
            int length = stoi(s.substr(i, delimeter - i));

            i = delimeter + 1;
            result.push_back(s.substr(i, length));
            
            i += length;
        }

        return result;
    }
};
