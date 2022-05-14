// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
      //Your code here
      stack<int> st1;
      stack<int> st2;
      
      vector<int> ans1(n,0);
      vector<int> ans2(n,0);
      
      st1.push(A[0]);
      st2.push(A[n-1]);
      
      for(int j=n-2;j>=0;j--)
      {
        if(A[j]>st2.top())
        {
            ans2[j]=st2.top();
            st2.push(A[j]);
            
        }
        
        else
        {
            while(!st2.empty() && st2.top()>=A[j])
            st2.pop();
            
            if(!st2.empty())
            ans2[j]=st2.top();
            
            st2.push(A[j]);
        }
      }
      
      for(int j=1;j<n;j++)
      {
        if(A[j]>st1.top())
        {
            ans1[j]=st1.top();
            st1.push(A[j]);
            
        }
        
        else
        {
            while(!st1.empty() && st1.top()>=A[j])
            st1.pop();
            
            if(!st1.empty())
            ans1[j]=st1.top();
            
            st1.push(A[j]);
        }
      }
      
      int mx=-1;
      for(int i=0;i<n;i++)
      {
          mx=max(abs(ans1[i]-ans2[i]),mx);
      }
      
      return mx;
      
      
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}


  // } Driver Code Ends