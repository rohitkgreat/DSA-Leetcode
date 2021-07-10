class Solution {
public:
    int minSwapsCouples(vector<int>& A) {
        
        for( auto &x : A ) x /= 2 ;
        int N = A.size(); 
        int cnt = 0 ; 
        for( int i = 0 ; i < N ; i += 2 )
        {
             if( A[i+1] == A[i] ) continue;
             else cnt++;
             for( int j = i+2 ; j < N ;j++ )if( A[i] == A[j] )swap( A[i+1] , A[j] );
        }
        return cnt; 
    }
};