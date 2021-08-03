class Solution {
public:
    int findComplement(int num) {
      
        int x=floor(log2(num))+1;
        int z=pow(2,x)-1;
        return z^num;
        
    }
};