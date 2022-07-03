class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int i=0;
        int n=nums.size();
        int cur=-1; 
        int ans=1;
        while(i<n-1)
        {
            int dif=nums[i+1]-nums[i];
             
            if(cur==-1)
            {
                if(dif>0)
                  {ans++;
                   cur=1;}
                else if(dif<0)
                   {ans++;
                    cur=0;}
                else 
                    {i++;
                    continue;}
            }
          
            else if(dif>0 && cur==0)
               {cur=1;
                ans++;}
            else if(dif<0 && cur==1)
               {cur=0;
                ans++;}
            else 
                {i++;
                continue;}
            
         i++;       
        }
        
        return ans;
    }
};