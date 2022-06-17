class Solution {
public:
    int helper(int start,string s,int k,int end)
    {
        if(start>=end || k>(end-start))
            return 0;
        
        unordered_map<char,int> mp;
        for(int i=start;i<end;i++)
            mp[s[i]]++;
        
        int j=start;
        
        while(j<end && mp[s[j]]>=k)
            j++;
        
        if(j==end)
            return end-start;
        
        int left=helper(start,s,k,j);
        int right=helper(j+1,s,k,end);
        
        return max(left,right);
        
        
    }
    int longestSubstring(string s, int k) {
       
       return helper(0,s,k,s.size());    
    }
};