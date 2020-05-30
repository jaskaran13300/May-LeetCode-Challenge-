//first Approach
class Solution {
public:
    float distance(int a , int b){
        return sqrt(a*a+b*b);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<float,int>,vector<pair<float,int>>,greater<pair<float,int>>>q;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
            q.push(make_pair(distance(points[i][0],points[i][1]),i));
        }
        for(int i=0;i<K;i++){
            auto temp=q.top();
            q.pop();
            ans.push_back(points[temp.second]);
        }
        return ans;  
    }
};

//Second approach
class Solution {
public:
    float distance(int a , int b){
        return sqrt(a*a+b*b);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<float,int>mp;
        for(int i=0;i<points.size();i++){
            mp.insert({distance(points[i][0],points[i][1]),i});
        }
        auto itr=mp.begin();
        vector<vector<int>>ans;
        while(itr!=mp.end() && K--){
            ans.push_back(points[itr->second]);
            itr++;
        }
        return ans;
    }
};
