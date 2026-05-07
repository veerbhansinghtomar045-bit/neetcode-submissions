class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        int output = 0;

        for (auto it : mpp) {
            int num = it.first;

            if (mpp.find(num - 1) == mpp.end()) {
                int count = 1;

                while (mpp.find(num + 1) != mpp.end()) {
                    count++;
                    num++;
                }

                output = max(output, count);
            }
        }

        return output;
    }
};