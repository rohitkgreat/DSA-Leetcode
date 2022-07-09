class Solution {
public:
    void helper(int i,string temp,vector<string> &ans,int dot,string &s)
    {
      
        if(temp.length()==s.length()+4 && dot==0)
        {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
       if(dot<0)
            return;
        
        string tmp="";
        for(int x=i;x<s.size();x++)
        {
            if(s[x]=='0')
                helper(x+1,temp+s[x]+'.',ans,dot-1,s);
            
            else
            {
                while(x<s.length() && stoi(tmp+s[x])<256)
                {
                    tmp=tmp+s[x];
                    helper(x+1,temp+tmp+'.',ans,dot-1,s);
                    x++;
                }
            }
            
        }
        
        return;
        
        
    }
    
    vector<string> restoreIpAddresses(string s) {      
        vector<string> ans;
        helper(0,"",ans,4,s);
        return ans;
    }
};