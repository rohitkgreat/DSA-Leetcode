class Solution {
public:
    void helper(int count,int k,vector<int> &ans,int n,int i,int z)
    {
        
        if(z==1)
        return;
        
        if(ans[i%n]==0)
            count--;
        
        else if(count==k && ans[i%n]!=0)
        {
            ans[i%n]=0;
            count=0;
            z--;
        }
        
        helper(count+1,k,ans,n,i+1,z);
        return;
    }
    int findTheWinner(int n, int k) {
        
        int count=1;
        vector<int> ans;
        
        for(int i=1;i<=n;i++)
            ans.push_back(i);
        int i=0;
        int z=n;
        helper(count,k,ans,n,i,z);
        
        for(auto z:ans)
           if(z!=0)
               return z;
        
        return -1;
        
    }
};