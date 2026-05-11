class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = 0;
        int left = 0;
        int right = n-1;

        while(left<right){
            int area = (right-left) * min(heights[left] , heights[right]);
            maxarea = max( maxarea , area );

            if(heights[left]<heights[right]){
                left++;
            }else{
                right--;
            }
        }

          return maxarea; 
    }
  
};
