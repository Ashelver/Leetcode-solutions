class Solution {
    public String longestPalindrome(String s) {
        int i = 0; // start from zero length of the string
        ArrayList<Integer> indices = new ArrayList<>();
        for (int j = 0; j < s.length(); j++){
            // Initially push all the indices into the array
            indices.add(j);
        }

        if (indices.isEmpty()){
            // Deal with empty string
            return "";
        }

        while (true){          
            // Use Iterator to do deletion safely
            Iterator<Integer> iterator = indices.iterator();
            String randomPS = s.substring(indices.get(0)-i, indices.get(0) + i + 1);
            while (iterator.hasNext()) {
                int index = iterator.next();
                if (index - i < 0 || index + i >= s.length() || s.charAt(index - i) != s.charAt(index + i)){
                    iterator.remove();
                }
            }
           

            // Stop conditions  
            if (indices.isEmpty()){
                return randomPS;
            }

            i ++;
        }
    }
}