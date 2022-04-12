class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int z=nums.size();
        
        vector<int> zero;
        for(int i=0;i<z;i++)
        {
            
            if(nums[i]==0)
                zero.push_back(i);
        }
        
        if(zero.size()==0)
            return true;
        else
        {
            for(auto x:zero)
            {
                int flag=0;
                int j=x-1;
                
                if(x==z-1)
                    return true;
                
                while(j>=0)
                {
                    if(nums[j]>x-j)
                        flag=1;
                    j--;
                }
                if(flag==0)
                return false;
            }
        }
        
        return true;
    }
};