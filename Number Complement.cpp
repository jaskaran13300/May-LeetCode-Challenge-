class Solution {
public:
    int countBits(int n) 
    { 
       int count = 0; 
       while (n) 
       { 
            count++; 
            n >>= 1; 
        } 
        return count; 
    } 
    int findComplement(int num) {
        if(num == 0)
            return 1 ;
        int n=countBits(num);
        for(int i=0;i<n;i++){
            num=(1<<i)^num;
        }
        return num;
    }
};
