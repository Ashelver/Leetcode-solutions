class Solution {
    public String longestPalindrome(String s) {
        HashMap<Integer, Integer> oddStartEnd = new HashMap<>();
        HashMap<Integer, Integer> evenStartEnd = new HashMap<>();
        for (int j = 0; j < s.length(); j++){
            // Initially push all the indices into the array
            if (j < (s.length() - 1) && s.charAt(j) == s.charAt(j+1)) {
                evenStartEnd.put(j,j + 1);
            }
            oddStartEnd.put(j,j);
        }
        if (oddStartEnd.isEmpty()){
            // Deal with empty string
            return "";
        }

        while (true){
            int randomStart = 0;
            int randomEnd = 0;
            HashMap<Integer, Integer> oddNextLevel = new HashMap<>();
            HashMap<Integer, Integer> evenNextLevel = new HashMap<>();
            for (Integer start: oddStartEnd.keySet()) {
                Integer end = oddStartEnd.get(start);
                // Odd length
                randomStart = start;
                randomEnd = end;
                if (start - 1 >= 0 && end + 1 < s.length() && s.charAt(start - 1) == s.charAt(end + 1)){
                    oddNextLevel.put(start - 1,end + 1);

                }
            }

            for (Integer start: evenStartEnd.keySet()) {
                Integer end = evenStartEnd.get(start);
                randomStart = start;
                randomEnd = end;
                // Odd length
                if (start - 1 >= 0 && end + 1 < s.length() && s.charAt(start - 1) == s.charAt(end + 1)){
                    evenNextLevel.put(start - 1,end + 1);
                    
                }
            }

            if (oddNextLevel.isEmpty() && evenNextLevel.isEmpty()){
                // Can not go forward
                return s.substring(randomStart, randomEnd + 1);
            } else {
                oddStartEnd.clear();
                oddStartEnd.putAll(oddNextLevel);
                evenStartEnd.clear();
                evenStartEnd.putAll(evenNextLevel);
            }
        }

    }
}