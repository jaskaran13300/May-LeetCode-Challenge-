class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0 || num==1 || num==2){
            return true;
        }
        long long i,n=num;
        for(i=0;i*i<=n;i++){
            if(i*i>n){
                break;
            }
        }
        if((i-1)*(i-1)==n){
            return true;
        }
        return false;
    }
};
//Using Binary Search
bool isPerfectSquare(int num) {
        long start = 1, end = num;
        while(start <= end){
            long mid = start + (end - start)/2;
            if(mid * mid == num) return true;
            if(mid * mid < num)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
