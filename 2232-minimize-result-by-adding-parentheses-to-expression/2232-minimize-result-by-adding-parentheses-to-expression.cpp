class Solution {
public:
    
    void helper(string &z,vector<int> &check)
    {
        int n=z.size();
        int mul=1,sum=0;
        
        int sb,add,end;
        for(int i=0;i<n;i++)
        {
            if(z[i]=='(')
                sb=i;
            else if(z[i]=='+')
                add=i;
            else if(z[i]==')')
                end=i;
        }
        int mult=1;
        string temp=z.substr(0,sb);
        if(temp.size()){
        int a=stoi(temp);
        mult*=a;
        }
        // cout<<mult<<" ";
        temp=z.substr(sb+1,add-sb);
        int x=stoi(temp);
        
        temp=z.substr(add+1,end-add);
        x+=stoi(temp);
        
        if(end!=n-1)
        {
            temp=z.substr(end+1,n-end);
            int y=stoi(temp);
            mult*=y;
        }
        
        int ans=x*mult;
        // cout<<ans;
        check.push_back(ans);
            
 }
    
    string minimizeResult(string ex) {
        vector<string> ans;
        int idx=0;
        
        for(int i=0;i<ex.length();i++)
        {
            if(ex[i]=='+')
            {
                idx=i;
                break;
            }
        }
                
        for(int i=0;i<idx;i++)
        {
            string temp="";
            temp+=ex.substr(0,i);
            temp+='(';
            temp+=ex.substr(i,idx-i);
            for(int j=idx+1;j<ex.length();j++)
            {   string z="";
                z+=temp;
                z+=ex.substr(idx,j-idx+1);
                z+=')';
                z+=ex.substr(j+1,ex.length()-j);
                
                ans.push_back(z);
            }
        }
        vector<int> check;
        
        for(int i=0;i<ans.size();i++)
            helper(ans[i],check);
        
        int ansi=0;
        int mn=check[0];
        for(int i=1;i<ans.size();i++)
        {
            if(mn>check[i])
            {
                ansi=i;
                mn=check[i];
            }
        }
        
        return ans[ansi];
    }
};