#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen[0] = 1;

        int prefix = 0;
        int count = 0;

        for (int num : nums) {
            prefix += num;

            if (seen.find(prefix - k) != seen.end()) {
                count += seen[prefix - k];
            }

            seen[prefix]++;
        }

        return count;
    }
};