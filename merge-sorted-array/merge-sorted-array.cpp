class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int z=nums1.size();
        int i=0,j=0,x=z-nums2.size();
        while(i<x && n!=0)
        {
            if(nums1[i]<=nums2[j])
                i++;
            else if( nums1[i]>nums2[j])
            {
                swap(nums1[i],nums2[j]);
                sort(nums2.begin(),nums2.end());
                i++;
            }
          
            
        }
        
        while(i<z && n!=0)
        {       nums1[i]=nums2[j];
                j++;
                i++;
            
        }
    }
};