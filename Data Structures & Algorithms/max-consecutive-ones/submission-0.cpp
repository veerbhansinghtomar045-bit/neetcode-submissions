class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int cnt = 0;
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] == 1) {
                cnt++;
                m = max(cnt, m);
            } else {
                cnt = 0;
            }
            i++;
        }

        return m;
    }
};