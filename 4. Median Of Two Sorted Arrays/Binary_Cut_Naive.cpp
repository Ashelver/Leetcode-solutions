class Solution {
private:
    double findMedianInRange(vector<int>& nums, int start, int end) {
        if (start < 0 || end >= nums.size() || start > end) {
            throw invalid_argument("Invalid start or end index.");
        }
        int n = end - start + 1;
        if (n % 2 == 1) {
            return nums[start + n / 2]/1.0;
        } else {
            return (nums[start + n / 2 - 1] + nums[start + n / 2]) / 2.0;
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Use binary cut
        int start_1 = 0;
        int start_2 = 0;
        int end_1 = nums1.size() - 1;
        int end_2 = nums2.size() - 1;
        // Process for empty array
        if (end_1 == -1){
            return findMedianInRange(nums2,start_2,end_2);
        }
        if (end_2 == -1){
            return findMedianInRange(nums1,start_1,end_1);
        }
        while(true){
            // Stop conditions
            if (end_1 < start_1){
                return findMedianInRange(nums2,start_2,end_2);
            }

            if (end_2 < start_2){
                return findMedianInRange(nums1,start_1,end_1);
            }


            int length_1 = end_1 - start_1 + 1;
            int length_2 = end_2 - start_2 + 1;
            if (length_1 == 1 && length_2 == 1){
                return (nums1[start_1] + nums2[start_2]) / 2.0;
            }
            if (length_1 == 1){
                if (length_2 % 2 == 1){
                    // Odd length of another array
                    if (nums1[start_1] >= nums2[start_2 + (length_2 / 2) + 1]){
                        return (nums2[start_2 + (length_2 / 2)] + nums2[start_2 + (length_2 / 2) + 1])/2.0;
                    }
                    if (nums1[start_1] <= nums2[start_2 + (length_2 / 2) - 1]){
                        return (nums2[start_2 + (length_2 / 2) - 1] + nums2[start_2 + (length_2 / 2)])/2.0;
                    }
                    return (nums1[start_1] + nums2[start_2 + (length_2 / 2)])/2.0;
                } else {
                    // Even length of another array 
                    if (nums1[start_1] >= nums2[start_2 + (length_2 / 2)]){
                        return nums2[start_2 + (length_2 / 2)]/1.0;
                    }
                    if (nums1[start_1] <= nums2[start_2 + (length_2 / 2) - 1]){
                        return nums2[start_2 + (length_2 / 2) - 1]/1.0;
                    }
                    return nums1[start_1]/1.0;
                }
            }

            if (length_2 == 1){
                if (length_1 % 2 == 1){
                    // Odd length of another array
                    if (nums2[start_2] >= nums1[start_1 + (length_1 / 2) + 1]){
                        return (nums1[start_1 + (length_1 / 2)] + nums1[start_1 + (length_1 / 2) + 1])/2.0;
                    }
                    if (nums2[start_2] <= nums1[start_1 + (length_1 / 2) - 1]){
                        return (nums1[start_1 + (length_1 / 2) - 1] + nums1[start_1 + (length_1 / 2)])/2.0;
                    }
                    return (nums2[start_2] + nums1[start_1 + (length_1 / 2)])/2.0;
                } else {
                    // Even length of another array 
                    if (nums2[start_2] >= nums1[start_1 + (length_1 / 2)]){
                        return nums1[start_1 + (length_1 / 2)]/1.0;
                    }
                    if (nums2[start_2] <= nums1[start_1 + (length_1 / 2) - 1]){
                        return nums1[start_1 + (length_1 / 2) - 1]/1.0;
                    }
                    return nums2[start_2]/1.0;
                }
            }

            int half_length_1 = length_1/2;
            int half_length_2 = length_2/2;
            int shorter_length;
            if (half_length_1 >= half_length_2){
                shorter_length = half_length_2;
            } else {
                shorter_length = half_length_1;
            }

            // Cut right
            if (nums1[start_1 + half_length_1] >= nums2[start_2 + half_length_2]){
                end_1 -= shorter_length;
            } else {
                end_2 -= shorter_length;
            }

            // Cut left
            if (nums1[start_1 + half_length_1 - 1] >= nums2[start_2 + half_length_2 - 1]){
                start_2 += shorter_length;
            } else {
                start_1 += shorter_length;
            }

        }
    }
};