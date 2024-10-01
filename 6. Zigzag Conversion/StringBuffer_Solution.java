class Solution {
    public String convert(String s, int numRows) {
        int zigzagPart = 2 * (numRows - 1);
        if (numRows == 1 || s.length() <= numRows) {
            return s;  // If numRows is 1 or length of string is shorter than numRows
        }

        StringBuilder[] rows = new StringBuilder[Math.min(numRows, s.length())];
        for (int i = 0; i < rows.length; i++) {
            rows[i] = new StringBuilder();
        }

        int currentRow = 0;
        boolean goingDown = false;

        // Go through the string
        for (char c : s.toCharArray()) {
            rows[currentRow].append(c);
            // Change direction
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate
        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }

        return result.toString();      
    }
}