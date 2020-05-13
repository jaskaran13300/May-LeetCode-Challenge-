class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k && num.size()){
            int ind=0;
            while(num.size()>ind && num[ind]<=num[ind+1]){
                ind++;
            }
            num.erase(num.begin()+ind);
            while(num.size()!=0 && num[0]=='0'){
                num.erase(num.begin());
            }
            k--;
        }
        if(num.size()==0){
            return "0";
        }
        return num;
    }
};
