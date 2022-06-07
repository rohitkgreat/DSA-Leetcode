/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   static bool compare(pair<int,int> a,pair<int,int> b)
      {  return a.second<b.second;
      }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       
      
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        // vector<pair<int,pair<int,int>>> temp;
        map<int, map<int, multiset<int>>> nodes;
      
        while(!q.empty())
        {
            TreeNode* fnt=q.front().first;
            int z=q.front().second.first;
            int h=q.front().second.second;
            q.pop();
            
             nodes[z][h].insert(fnt -> val);
            
//             temp.push_back({fnt->val,{z,h}});
//             mn=min(mn,z);
//             mx=max(mx,z);
            
            if(fnt->left)
            {q.push({fnt->left,{z-1,h+1}});
            }
            if(fnt->right)
              {  q.push({fnt->right,{z+1,h+1}});
              }
            
        }
        
//         int zz=abs(mn)+1+mx;
        
//         vector<vector<pair<int,int>>> ans(zz);
        
//         int sz=temp.size();
        
//         for(int i=0;i<sz;i++)
//         {
//             temp[i].second.first+=abs(mn);
                      
//         }
        
//         for(int i=0;i<sz;i++)
//         {
//             ans[temp[i].second.first].push_back({temp[i].first,temp[i].second.second});            
//         }
        
//         for(auto z:ans[0])
//             cout<<z.first<<" ";
        
//         vector<vector<int>> finans;
//         return finans;
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};