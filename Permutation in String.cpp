class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26);
        vector<int>v2(26);
        int l1=s1.size();
        int l2=s2.size();
        if(l2<l1){
            return false;
        }
        for(int i=0;i<l1;i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(v1==v2){
            return true;
        }
        for(int i=l1;i<l2;i++){
            v2[s2[i]-'a']++;
            v2[s2[i-l1]-'a']--;
            if(v1==v2)
                return true;
        }
        return false;
    }
};
