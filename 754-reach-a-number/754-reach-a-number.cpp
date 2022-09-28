class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int in=0;
        int step=1;
        int moves=0;
        while(true)
        {
            moves++;
            in+=step;
            step++;
            
            if(in==target)
                return moves;
            if(in>target && abs(in-target)%2==0)
                return moves;
        }
        return 0;
    }
};