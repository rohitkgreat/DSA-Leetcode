class Solution {
public:
    int trap(vector<int>& height) {
        int sz=height.size();
        int left=0;
        int right=sz-1;
        
        int mxright=0,mxleft=0,ans=0;
        while(left<=right)
        {
            if(height[right]>=height[left])
            {
                 if(height[left]>=mxleft)
                    mxleft=height[left];
                else
                    ans+=mxleft-height[left];
                left++;
                
            }
            else
            {
               
                if(height[right]>=mxright)
                    mxright=height[right];
                else
                    ans+=mxright-height[right];
                
                right--;
            }
        }
        return ans;
    }
};