class Solution {
public:
    bool isValid(string s) {
        stack<char> closing_brackets;
        unordered_map<char, char> bracket_pairs = { 
            {'[', ']'}, 
            {'{', '}'},
            {'(', ')'}
        };

        for (char c : s){
            if (bracket_pairs.contains(c)){
                closing_brackets.push(bracket_pairs[c]);
            } else {
                if (closing_brackets.empty() || c != closing_brackets.top()){
                    return false;
                }
                closing_brackets.pop();
            }
        }
        return closing_brackets.empty();
    }
};
