class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //First Row and First Column as Markers
        int col0=1;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0; //first row
                    if(j!=0) matrix[0][j]=0; //first col
                    else col0=0;
                }
            }
        }

        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][j]!=0){
                    if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j]=0;
                }
            }
        }

        if(matrix[0][0]==0){
            for(int j=0; j<matrix[0].size(); j++) matrix[0][j]=0;
        }
        if(col0==0){
            for(int i=0; i<matrix.size(); i++) matrix[i][0]=0;
        }

        // //separate arrays for rows and columns TC:- O(n*m) This approach growth remains same irrespective of number of zeroes
        // vector<int> row(matrix.size());
        // vector<int> col(matrix[0].size());
        // for(int i=0; i<matrix.size(); i++){
        //     for(int j=0; j<matrix[0].size(); j++){
        //         if(matrix[i][j]==0){
        //             row[i]=1;
        //             col[j]=1;
        //         }
        //     }
        // }

        // for(int i=0; i<matrix.size(); i++){
        //     for(int j=0; j<matrix[0].size(); j++){
        //         if(row[i]==1 || col[j]==1) matrix[i][j]=0;
        //     }
        // }

        // //Extra List to Track Zero Positions   TC:-O(n*m + k*(n+m)) This approach fails terribly when number of zeroes are a lot
        // vector<pair<int, int>> index;
        // for(int i=0; i<matrix.size(); i++){
        //     for(int j=0; j<matrix[0].size(); j++){
        //         if(matrix[i][j]==0) index.push_back({i, j});
        //     }
        // }

        // for(auto &k: index){
        //     for(int i=0; i<matrix.size(); i++){
        //         matrix[i][k.second]=0;
        //     }
        //     for(int i=0; i<matrix[0].size(); i++){
        //         matrix[k.first][i]=0;
        //     }
        // }
    }
};