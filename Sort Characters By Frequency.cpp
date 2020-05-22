class Solution:
    def frequencySort(self, s: str) -> str:
        # a=sorted(s)
        count=dict()
        for ss in s:
            count[ss]=count.get(ss,0)+1
        arr=sorted([(v,k) for (k,v) in count.items()],reverse=True)
        ans=''
        for k,v in arr:
            ans=ans+(v*k)
        return ans

//Alternative for cpp using pq

class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        mp[s[i]]++;
        priority_queue<pair<int,char>>pq;
        for(auto x:mp)
        pq.push({x.second,x.first});
        string st="";
        while(!pq.empty())
        {
            pair<int,char>x=pq.top();
            int temp=x.first;
            while(temp--)
            st+=x.second;
            pq.pop();
        }
        return st;
    }
};
