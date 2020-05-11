class Solution {
public:
    void help(vector<vector<int>>& image, int sr, int sc, int newColor,int c){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=c){
            return;
        }
        int arr1[]={-1,0,1,0},arr2[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            help(image,sr+arr1[i],sc+arr2[i],newColor,c);
            image[sr][sc]=newColor;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int c=image[sr][sc];
        if(newColor==c){
            return image;
        }
        help(image,sr,sc,newColor,c);
        return image;
    }
};
