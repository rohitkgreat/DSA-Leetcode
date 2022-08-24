class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(auto z:chalk)
            sum+=z;        
        
        // cout<<sum<<" ";
       k=k%sum;
//        cout<<y<<endl;
        int i=0;
        int n=chalk.size();
        while(i<n)
        {
            k=k-chalk[i];
            if(k<0)
                return i;
            i++;
        }

        return 0;
     
    // k %= accumulate(begin(chalk), end(chalk), 0l);
    //     cout<<k;
    // for (int i = 0; i < chalk.size(); ++i)
    //     if ((k -= chalk[i]) < 0)
    //         return i;
    // return 0;
    }
};