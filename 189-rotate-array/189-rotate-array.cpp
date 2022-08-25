class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        // if(k>=n)
        //     return;
        k=k%n;
        int x=n-k;
        for(int i=x;i<n;i++)
            nums.push_back(nums[i]);
        int y=x-1;
        int m=n-1;
        while(y>=0)
        {
            nums[m]=nums[y];
            m--;
            y--;
        }
        
        for(int i=0;i<k;i++)
            nums[i]=nums[n+i];
        
        while(k--)
            nums.pop_back();
    }
};