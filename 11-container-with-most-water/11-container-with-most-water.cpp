class Solution {
public:
    int maxArea(vector<int>& height) {
        int curmax;
        int ans=0;
        
        int i=0;
        int j=height.size()-1;
        
        while(i<j)
        {
            curmax=min(height[i],height[j])*(j-i);
            ans=max(ans,curmax);
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return ans;
    }
};