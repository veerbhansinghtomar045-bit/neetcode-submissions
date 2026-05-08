class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        int k = n;

        for (int i = 0; i < k - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
                k--;
                i--;
            }
        }

        return k;
    }
};