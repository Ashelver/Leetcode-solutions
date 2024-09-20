class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int anchar = -1;
        int total_length = s.size();
        unordered_map<char, int>hash_map; // key will be the char, value will be index of its last occuring
        for (int i = 0; i < total_length; i++){
            int substring_length;
            if (hash_map.find(s[i]) == hash_map.end()){
                // This character is not in the hash_map
                hash_map[s[i]] = i;
            } else {
                // This character is in the hash_map
                if (hash_map[s[i]] > anchar){
                    anchar = hash_map[s[i]];
                }
                hash_map[s[i]] = i;
            }
            substring_length = i - anchar;
            if (substring_length > max_length){
                max_length = substring_length;
            }
        }
        return max_length;
    }
};