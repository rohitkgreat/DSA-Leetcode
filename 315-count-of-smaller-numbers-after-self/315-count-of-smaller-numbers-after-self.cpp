class Solution {
public:
    int query(vector<int>&segtree,int treeind,int left,int right,int start,int end){
        if(start>end){
            return 0;
        }
        if(start>right || end<left){
            return 0;
        }
        if(start>=left && end<=right){
            return segtree[treeind];
        }
        int mid=(start+end)/2;
        int left1=query(segtree,treeind*2+1,left,right,start,mid);
        int right1=query(segtree,treeind*2+2,left,right,mid+1,end);
        return left1+right1;
    }
    void update(vector<int>&segtree,int treeind,int num,int start,int end){
        if(start>end || start>num || end<num){
            return;
        }
        if(start==end){
            segtree[treeind]++;
            return;
        }
        int mid=(start+end)/2;
        update(segtree,treeind*2+1,num,start,mid);
        update(segtree,treeind*2+2,num,mid+1,end);
        segtree[treeind]=segtree[2*treeind+1]+segtree[2*treeind+2];
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
//      give index to each number so that we can make bit based on it
        map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        // assigning each number with a index in increasing order
        int index=1;
        for(auto it:map){
            int first=it.first;
            map[first]=index++;
        }
        vector<int>segtree(map.size()*4+1,0);
        vector<int>ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            index=map[nums[i]];
            int temp=query(segtree,0,1,index-1,1,map.size());
            ans[i]=temp;
            update(segtree,0,index,1,map.size());
        }
        return ans;
    }
};