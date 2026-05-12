class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        for (int left = 0; left < n; left++) {
            int right = min(n - 1, left + k);

            while (right > left) {
                if (nums[left] == nums[right]) {
                    return true;
                }

                right--;
            }
        }

        return false;
    }
};