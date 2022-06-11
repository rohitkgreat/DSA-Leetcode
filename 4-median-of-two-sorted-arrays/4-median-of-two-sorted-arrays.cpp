class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        
        vector<int> ans;
        int i=0,j=0;
        int n=nums1.size();
        int m=nums2.size();
        
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
            
        }
        while(i<n)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(nums2[j]);
            j++;
        }
        
        if((m+n)%2!=0)
        {
            int k=(m+n)/2;
            double anss=ans[k];
            
            return anss;
        }
        else
        {
            int k=(m+n)/2;
            double anss=(float(ans[k])+float(ans[k-1]))/2;
            return anss;
        }
      
        return 0;
        
    }
};