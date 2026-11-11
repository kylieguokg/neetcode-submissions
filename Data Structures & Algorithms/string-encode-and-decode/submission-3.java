class Solution {

    public String encode(List<String> strs) {
        var encoded = new StringBuilder();
        var numWords = strs.size(); 
        // count is 2 chars long
        encoded.append(String.format("%02d", numWords));
        for (String s : strs){
            // count of each word is 3 chars long
            encoded.append(String.format("%03d", s.length()));
        }

        for (String s : strs){
            encoded.append(s);
        }

        return new String(encoded);

    }

    public List<String> decode(String str) {
        var curIndex = 0;
        var strArray = str.toCharArray();
        var numWordsArray = new String(Arrays.copyOfRange(strArray, 0, 2));
        int numWords = Integer.valueOf(numWordsArray);
        
        curIndex = 2;
        var wordSizes = new int[numWords];
        for (int i = 0; i < numWords; i++){
            var endOfWordSizeIndex = curIndex + 3;
            var wordSizeArr = Arrays.copyOfRange(strArray, curIndex, endOfWordSizeIndex);
            var wordSize = Integer.valueOf(new String(wordSizeArr));
            wordSizes[i] = wordSize;
            curIndex = endOfWordSizeIndex;
        }

        var decoded = new ArrayList<String>();
        int wordIndex = 0;
        // System.out.println(Arrays.toString(wordSizes));

        while (wordIndex < wordSizes.length){
            var curWordSize = wordSizes[wordIndex];
            var curStrArr = Arrays.copyOfRange(strArray, curIndex, curIndex + curWordSize);
            decoded.add(new String(curStrArr));
            curIndex += curWordSize;
            wordIndex += 1;
        }

        return decoded;
    }
}
