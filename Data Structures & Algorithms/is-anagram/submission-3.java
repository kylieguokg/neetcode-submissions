class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()){
            return false;
        }

        var sChars = new int[26];
        for (char c : s.toCharArray()){
            sChars[c - 'a'] += 1;
        }

        for (char c: t.toCharArray()){
            sChars[c - 'a'] -= 1;
        }

        for (int charCount : sChars){
            if (charCount != 0){
                return false;
            }
        }

        return true;
    }
}
