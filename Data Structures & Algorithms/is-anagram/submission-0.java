class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> sCount = new HashMap<Character, Integer>();
        for (char c : s.toCharArray()){
            sCount.put(c, sCount.getOrDefault(c, 0) + 1);
        }

        for (char c : t.toCharArray()){
            sCount.put(c, sCount.getOrDefault(c, 0) - 1);
        }

        for (char c : sCount.keySet()){
            if (sCount.get(c) != 0){
                return false;
            }
        }
        return true;
    }
}
