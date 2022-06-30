class Solution {
public:
    bool helper(vector<int>& nums,int start,int end,int turn,int scorea,int scoreb){
        if(start>end){
            return (scorea>=scoreb);
        }
        if(turn==0){
            bool temp=helper(nums,start+1,end,1-turn,scorea+nums[start],scoreb);
            bool x= helper(nums,start,end-1,1-turn,scorea+nums[end],scoreb);
            return temp||x;
        }else{
            bool temp=helper(nums,start+1,end,1-turn,scorea,scoreb+nums[start]);
            bool y=helper(nums,start,end-1,1-turn,scorea,scoreb+nums[end]);
            return y&&temp;
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums,0,nums.size()-1,0,0,0);
    }
};