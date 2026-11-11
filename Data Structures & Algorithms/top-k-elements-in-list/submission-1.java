class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        // 1. Get count of each num in map
        var numCount = new HashMap<Integer, Integer>();
        for (int num : nums){
            numCount.put(num, numCount.getOrDefault(num, 0) + 1);
        }
        // 2. Inverse the map to be count -> num
        var countInverse = new HashMap<Integer, Set<Integer>>();
        for (int num : numCount.keySet()){
            var count = numCount.get(num);
            var numsWithCount = countInverse.getOrDefault(count, new HashSet<Integer>());
            numsWithCount.add(num);
            countInverse.put(count, numsWithCount);
        }

        // 3. Sort the counts
        var sortedCounts = countInverse.keySet().toArray();
        Arrays.sort(sortedCounts, Collections.reverseOrder());

        var kMostFrequent = new int[k];
        int i = 0;
        int j = 0;
        while (j < k){
            var count = sortedCounts[i];
            var numsWithCount = countInverse.get(count);
            for (int num : numsWithCount){
                kMostFrequent[j] = num;
                j += 1;
            }
            i += 1;
        }
        return kMostFrequent;
    }
}
