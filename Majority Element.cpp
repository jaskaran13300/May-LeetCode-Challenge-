class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second>(nums.size()/2)){
                return itr->first;
            }
        }
        return 0;
    }
};
