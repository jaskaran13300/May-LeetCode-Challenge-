class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int row=coordinates.size();
        int col=0;
        if(row){
            col=coordinates[0].size();
        }
        if(row==1 || row==2){
            return true;
        }
        double x1=coordinates[0][0],y1=coordinates[0][1];
        double x2=coordinates[1][0],y2=coordinates[1][1];
        double slope=(double)(y2-y1)/(double)(x2-x1);
        for(int i=1;i<row-1;i++){
            x1=coordinates[i][0],y1=coordinates[i][1];
            x2=coordinates[i+1][0],y2=coordinates[i+1][1];
            double m=(double)(y2-y1)/(double)(x2-x1);
            // cout<<m<<" "<<slope<<endl;
            if(m!=slope){
                return false;
            }
        }
        return true;
    }
};
