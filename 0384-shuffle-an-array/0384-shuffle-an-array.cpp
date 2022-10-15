class Solution {
public:
    vector<int> org;
    vector<int> a;
    Solution(vector<int>& nums) {
        org=nums;
        a=nums;
    }
    
    vector<int> reset() {
        // nums=org;
        return org;
    }
    
    vector<int> shuffle() {
        next_permutation(a.begin(),a.end());
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */