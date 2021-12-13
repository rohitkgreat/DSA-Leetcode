class Solution {
public:
    bool palindrome(string s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        ans+=s[0];
        vector<int>*index=new vector<int>[257]();
        for(int i=0;i<s.size();i++){
            int a=s[i];
            index[a].push_back(i);
        }
        for(int i=0;i<256;i++){
            for(int j=0;j<index[i].size();j++){
                for(int k=index[i].size()-1;k>=0;k--){
                    int start=index[i][j];
                    int end=index[i][k];
                    string temp=s.substr(index[i][j],index[i][k]-index[i][j]+1);
                    // cout<<temp<<endl;
                    if(palindrome(temp)){
                        if(temp.size()>ans.size())
                            ans=temp;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};