class Solution {
public:
    vector<int> helper(string &a)
    {
        vector<int> f(26,0);
        for(auto x:a)
        {
            int z=x-'a';
            f[z]++;
        }
        return f;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> frq(26,0);
        vector<string> ans;
        for(auto z:words2)
        {
            vector<int>tmp=helper(z);
            for(int i=0;i<26;i++)
                frq[i]=max(frq[i],tmp[i]);
        }
        
        for(auto z:words1 )
        {   
            bool mil=true;
            vector<int> tmp=helper(z);
            for(int i=0;i<26;i++)
            {
                if(tmp[i]<frq[i])
                {
                    mil=false;
                    break;
                }
            }
            if(mil)
                ans.push_back(z);
        }
    return ans;
    }
};