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
