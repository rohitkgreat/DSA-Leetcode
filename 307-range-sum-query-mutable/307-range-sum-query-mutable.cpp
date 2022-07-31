class NumArray {
public:
    int*tree;
    int n;
    int size;
    void initialize(vector<int>&nums,int start,int end,int treeind,int*tree){
        if(start>end){
            return;
        }
        if(start==end){
            tree[treeind]=nums[start];
            return;
        }
        int mid=(start+end)/2;
        initialize(nums,start,mid,2*treeind+1,tree);
        initialize(nums,mid+1,end,2*treeind+2,tree);
        tree[treeind]=tree[2*treeind+2]+tree[2*treeind+1];
    }
    void update(int start,int end,int index,int val,int treeind,int*tree){
        if(start>end){
            return;
        }
        if(start==end && start==index){
            tree[treeind]=val;
            return;
        }
        int mid=(start+end)/2;
        if(index>mid){
            update(mid+1,end,index,val,2*treeind+2,tree);
        }else{
            update(start,mid,index,val,2*treeind+1,tree);
        }
        tree[treeind]=tree[2*treeind+2]+tree[2*treeind+1];
    }
    int sum(int start,int end,int left,int right,int treeind,int*tree){
        if(start>end){
            return 0;
        }
        if(start>right || end<left){
            return 0;
        }
        if(start>=left && end<=right){
            return tree[treeind];
        }
        int mid=(start+end)/2;
        int lsum=sum(start,mid,left,right,2*treeind+1,tree);
        int rsum=sum(mid+1,end,left,right,2*treeind+2,tree);
        return lsum+rsum;
    }
    NumArray(vector<int>& nums) {
        size=4*nums.size()+1;
        n=nums.size();
        tree=new int[size];
        initialize(nums,0,n-1,0,tree);
    }
    void update(int index, int val) {
        update(0,n-1,index,val,0,tree);
    }
    int sumRange(int left, int right) {
        return sum(0,n-1,left,right,0,tree);
    }
};