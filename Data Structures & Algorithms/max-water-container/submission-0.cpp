class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = 0;

        for(int i =0; i <n; i++){
            for(int j =i+1; j <n; j++){
                int area;

            if(heights[i]>heights[j]){
            area = (j-i) * (heights[j]);
            
            }else{
                area = (j-i) * heights[i];
             }
              if(area>maxarea){
                maxarea = area;
              }
            

         }  
        }  
          return maxarea; 
    }
  
};
