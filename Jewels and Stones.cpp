class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans=0;
        unordered_map<char,int> jew;
        for(int i=0;i<J.length();i++){
            jew[J[i]]++;
        }
        for(int i=0;i<S.length();i++){
            if(jew.find(S[i])!=jew.end()){
                ans++;
            }
        }
        return ans;
    }
};
