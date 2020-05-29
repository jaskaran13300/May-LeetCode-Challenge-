class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>graph[numCourses];
        for(auto c:prerequisites){
            graph[c[1]].push_back(c[0]);
        }
        vector<int>vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(cycle(vis,graph,i)){
                return false;
            }
        }
        return true;
    }
    bool cycle(vector<int>&vis,vector<int>graph[],int ind){
        if(vis[ind]==1){
            return true;
        }
        if(vis[ind]==0){
            vis[ind]=1;
            for(auto abc:graph[ind]){
                if(cycle(vis,graph,abc)){
                    return true;
                }
            }
        }
        vis[ind]=2;
        return false;
    }
    
};
