class Solution {
public:
    int minPartitions(string n) {
    
        int z=n.length();
        
        int mx=-1;
        for(int i=0;i<z;i++)
        {
            int x=n[i]-'0';
            mx=max(mx,x);
        }
        
        return mx;
    }
};