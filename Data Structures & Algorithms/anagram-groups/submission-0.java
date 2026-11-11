class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // 1. Sort each string and if the sort is the same, group them
        var sortedAnagrams = new HashMap<String, List<String>>();
        for (String s : strs){
            var chars = s.toCharArray();
            Arrays.sort(chars);
            var sortedS = Arrays.toString(chars);
            var anagrams = sortedAnagrams.getOrDefault(sortedS, new ArrayList<String>());
            anagrams.add(s);
            sortedAnagrams.put(sortedS, anagrams);
        }

        return new ArrayList<>(sortedAnagrams.values());
    }
}
