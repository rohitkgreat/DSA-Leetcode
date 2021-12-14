class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n=strs.size();
        int x=strs[0].size();
     
        int flag=0,i,j;
        string ans="";
        
        for(i=0;i<x;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(strs[j][i]!=strs[j+1][i])
                {
                    flag=1;
                    break;
                }    
                
            }
            if(flag==1)
                break;
            else
            {ans+=strs[j][i];
             flag=0;
            }
            
        }
        
        return ans;
        
    }
};