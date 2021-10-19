class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
//         vector<vector<int>> ans;
        
//         sort(intervals.begin(),intervals.end());
        
//         int n=intervals.size();
//         int j=0,i=0,x;
//         vector<int> temp;
//         while(j<n)
//         {
//             if(intervals[i][1]>=intervals[j][0])
//             {
//                 temp.clear();
//                 temp.push_back(intervals[i][0]);
//                 temp.push_back(intervals[j][1]);
//                 j++;
//                 x=j;
//             }
//             else if(intervals[i][1]<intervals[j][0])
//             {
//                 ans.push_back(temp);
//                 temp.clear();
//                 i=x;
//                 j=i;
//             }
            
//         }
        
//         return ans;
         sort(v.begin(),v.end());
        vector<vector<int>>ans;
   
        ans.push_back(v[0]);

        int first = ans[0][0];
        int last = ans[0][1];
        int k=0;

        for(int i=1;i<v.size();i++)
        {

            if(v[i][0]<=last)
            {
                ans[k][1] = max(v[i][1],last);
                ans[k][0] =  min(v[i][0],first);
                first = ans[k][0];
                last = ans[k][1];
            }
            else{

                vector<int>temp;
                temp.push_back(v[i][0]);
                temp.push_back(v[i][1]);

                ans.push_back(temp);

                k++;
                first =  ans[k][0];
                last =  ans[k][1];

            }
    }
            return ans;
        
    }
};