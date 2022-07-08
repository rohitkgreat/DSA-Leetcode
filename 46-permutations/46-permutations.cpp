// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         int n=nums.size();
//         int arr[n+1];
        
//         for(int i=0;i<n;i++)
//             arr[i]=0;
        
//         vector<vector<int>> ans;
//         vector<int> temp;
        
//         helper(nums,ans,temp,arr,n,0);
        
//         return ans;
        
//     }
    
//     void helper(vector<int> nums,vector<vector<int>> &ans,vector<int> temp,int arr[],int n,int idx)
//     {
//         if(temp.size()==n)
//         {
//             ans.push_back(temp);
//             return;
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             if(arr[i]==0)
//             {
//                 temp.push_back(nums[i]);
//                 arr[i]=1;
//                 helper(nums,ans,temp,arr,n,i+1);
//                 arr[i]=0;
//                 temp.pop_back();
//             }
//         }
        
//         return;
//     }
// };

class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>> &ans,vector<int>temp,int arr[])
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(arr[i]==0)
            {
                arr[i]=1;
                temp.push_back(nums[i]);
                helper(nums,ans,temp,arr);
                arr[i]=0;
                temp.pop_back();
            }
        }
        return;
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        int arr[n+1];
        
        for(int i=0;i<n;i++)
            arr[i]=0;
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        helper(nums,ans,temp,arr);
        
        return ans;
        
    }
    
  
};