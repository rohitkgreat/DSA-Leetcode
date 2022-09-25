class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        int x=0;
        while(x<2){
        int start=0,end=nums.size()-1;
        int i=-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            
            if(nums[mid]==target)
            {   
                
                if(x%2==0)
                end=mid-1;
                else
                start=mid+1;
                
                i=mid;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
                start=mid+1;
        }
         if(i!=-1)
         ans.push_back(i);
         x++;
        }  
                  
        if(ans.size()==0)
            return {-1,-1};
        return ans;
    }
};