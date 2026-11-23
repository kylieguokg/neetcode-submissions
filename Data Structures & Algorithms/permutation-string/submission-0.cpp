class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()){
            return false;
        }
        
        int s1CharCount[26] = {};
        int s2CharCount[26] = {};

        // get char count for chars [0, len(s1) - 1]
        for (int i = 0; i < s1.size(); i++){
            s1CharCount[s1[i] - 'a'] += 1;
            s2CharCount[s2[i] - 'a'] += 1;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++){
            if (s1CharCount[i] == s2CharCount[i]){
                matches += 1;
            }
        }

        int left = 0;
        for (int right = s1.size(); right < s2.size(); right++){
            if (matches == 26){
                return true;
            }

            // introduce right letter
            int index = s2[right] - 'a';
            s2CharCount[index] += 1;
            if (s1CharCount[index] == s2CharCount[index]){
                matches += 1;
            } else if (s1CharCount[index] + 1 == s2CharCount[index]){
                matches -= 1;
            }

            // remove left letter
            index = s2[left] - 'a';
            s2CharCount[index] -= 1;
            if (s1CharCount[index] == s2CharCount[index]){
                matches += 1;
            } else if (s1CharCount[index] - 1 == s2CharCount[index]){
                matches -= 1;
            }

            left += 1;
        }
        return matches == 26;
    }
};

/**
bec -> matches = 24 (inc c)
a -> match += 1 25
l -> 

**/
