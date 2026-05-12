class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        for( int left =0; left< n; left++){
            int right = n - 1;  
            while(right>left){
                if(nums[left] == nums[right]){
                    if(abs(left-right) <= k){
                    return true;
                   }
                
               }
            
                right --;

            }
        }
    
        return false;
    }
};