class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        char begin_ch = s[0];
        int total_length = s.size();
        int index = 0;
        int substring_length = 0;
        unordered_map<char, int>hash_map; // key will be the char, value will be index of its last occuring
        while (index < total_length) {
            if (hash_map.find(s[index]) == hash_map.end()){
                // This character is not in the hash map
                substring_length += 1;
                hash_map[s[index]] = index;
                index ++;
                if (substring_length > max_length) {
                    max_length = substring_length;
                }
            } else {
                // This character is in the hash map
                if (substring_length > max_length) {
                    max_length = substring_length;
                }
                index = hash_map[s[index]] + 1;
                hash_map.clear();
                substring_length = 0;
            }
        }

        return max_length;
    }
};