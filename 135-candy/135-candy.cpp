class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n=ratings.size();
        vector<int> ans(n,1);
        vector<int> ans2(n,1);
        
        for(int i=0;i<ratings.size()-1;i++)
        {
            if(ratings[i]<ratings[i+1])
                ans[i+1]=ans[i]+1;
       
        }
        for(int i=n-1;i>0;i--)
        {
            if(ratings[i-1]>ratings[i])
               ans2[i-1]=ans2[i]+1;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
           
            sum+=max(ans[i],ans2[i]);
        }
//         
        return sum;
            
    }
};