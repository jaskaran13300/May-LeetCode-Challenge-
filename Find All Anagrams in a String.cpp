class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int> mp;
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        int left=0;
        int counter=p.size();
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]!=0){
                counter--;
                mp[s[i]]--;
                if(counter==0){
                    ans.push_back(left);
                }
            }
            else{
                for(int j=left;j<i;j++){
                    if(mp.find(s[j])!=mp.end()){
                        counter++;
                        mp[s[j]]++;
                    }
                    left++;
                    if(mp.find(s[i]) != mp.end() && mp[s[i]]){
                        i--;
                        break;
                   }
                }
                if(mp.find(s[left])==mp.end())
                    left = i + 1;
            }
        }
        return ans;
    }
};
