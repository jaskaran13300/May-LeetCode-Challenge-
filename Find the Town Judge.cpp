class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,int>mp;
        if(N==1){
            return 1;
        }
        for(int i=0;i<trust.size();i++){
            mp[trust[i][0]]--;
            mp[trust[i][1]]++;
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second==N-1){
                return itr->first;
            }
        }
        return -1;
    }
};
