class Solution {
    public boolean isAnagram(String s, String t) {
        int[] sCount = new int[26];
        for (char c : s.toCharArray()){
            sCount[c - 'a'] += 1;
        }

        for (char c : t.toCharArray()){
            sCount[c - 'a'] -= 1;
        }

        for (int i = 0; i < 26; i++){
            if (sCount[i] != 0){
                return false;
            }
        }
        return true;
    }
}
