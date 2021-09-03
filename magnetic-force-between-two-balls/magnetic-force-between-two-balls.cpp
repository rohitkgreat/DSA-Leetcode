bool check(vector<int>& position,int size,int n,int minsep)
{
    int cow=position[0];
    int count=1;
    
    for(int i=1;i<size;i++)
    {
        if(position[i]-cow>=minsep)
        {
            count++;
            cow=position[i];
            if(count==n)
                return true;
        }
    }
    
    return false;
}





class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(),position.end());
        int n=position.size();
        int last=position[n-1];
        int start=0;
        int ans;
        while(start<=last)
        {
            int mid=(start+last)/2;
            if(check(position,n,m,mid))
            {
                ans=mid;
                start=mid+1;
            }
            else
                last=mid-1;
        }
        
        return ans;
        
    }
};