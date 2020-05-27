class Solution {
public:
    bool assign(unordered_map<int,vector<int>>&graph,vector<int>&color,int ind,int clr){
        //if grp is already assigned
        if(color[ind]!=0){
            //if grp on that node is same that we want to assign then it is fine
            if(clr==color[ind]){
                return true;
            }
            return false;
        }
        color[ind]=clr;
        if(graph[ind].size()==0){
            return true;
        }
        for(int node:graph[ind]){//trverse to each value on graph 
            if(!assign(graph,color,node,-clr)){
//                 if we are not able to assign it in other group->return false
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<dislikes.size();i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }//build a graph
        vector<int>color(N+1,0);//0 for grp not assigned,1->grp 1,-1->grp2
        for(int i=1;i<=N;i++){
            //we will asssign group if it is not assigned yet
            if(color[i]==0 && !assign(graph,color,i,1)){
                // initially we will try to assign for group 1
                return false;
            }
        }
        return true;
    }
};
