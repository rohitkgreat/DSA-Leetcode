class Solution {
public:
    int check[26];
    int find(int x)
    {
        return check[x]==x?x:(check[x]=find(check[x]));    
    }
    bool equationsPossible(vector<string>& equations) {
    
        
        for(int i=0;i<26;i++)
            check[i]=i;
        
        for(auto z:equations)
        {
            if(z[1]=='=')
                check[find(z[0]-'a')]=find(z[3]-'a');
                
        }
        for(auto z:equations)
        {
            if(z[1]=='!')
                if(check[find(z[0]-'a')]==check[find(z[3]-'a')])
                return false;
        }
        // for(int i=0;i<5;i++)
        //     cout<<check[i]<<" ";
        
        return true;
    }
};