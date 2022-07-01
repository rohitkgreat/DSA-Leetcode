class Solution {
public:
    
    static bool comp(vector<int> a,vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        
        sort(box.begin(),box.end(),comp);
        
        int count=0;
        int ans=0;
        for(int i=0;i<box.size();i++)
        {
            int z=box[i][0];
            count+=z;
            if(count<=truckSize)
                ans+=box[i][0]*box[i][1];
            else
            {
                count=count-z;
                int temp=truckSize-count;
                ans+=temp*box[i][1];
                break;
            }
        }
        
        return ans;
    }
};