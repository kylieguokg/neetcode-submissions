class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()){
            return false;
        }

        var letterCount = new HashMap<Character, Integer>();

        for (char c : s.toCharArray()){
            letterCount.put(c, letterCount.getOrDefault(c, 0) + 1);
        }

        for (char c : t.toCharArray()){
            var count = letterCount.get(c);
            if (count == null){
                return false;
            }
            letterCount.put(c, count - 1);
        }

        for (int count : letterCount.values())
        {
            if (count != 0){
                return false;
            }
        }

        return true;
    }
}
