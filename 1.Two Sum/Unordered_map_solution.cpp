#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>hash_map; // key will be the number in `nums`, value will be the indice of the number 
        int current_num;
        int complement_num;
        for (int i = 0; i < nums.size(); i++){
            current_num = nums[i];
            complement_num = target - current_num;
            unordered_map<int, int>::iterator it = hash_map.find(complement_num);
            if (it == hash_map.end()){
                hash_map[current_num] = i;
            } else {
                return {it->second, i};
            }
        }
        return {-1, -1}; // fail to find the answer
    }
};