class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int srow=0, scol=0, erow=matrix.size()-1, ecol=matrix[0].size()-1;
        vector<int> result;
        //logical and is used due to validity of the smaller number between ros and columns
        while(srow<=erow && scol<=ecol){  //eqaulity is needed for odd number of rows and columns
            for(int j=scol; j<=ecol; j++){
                result.push_back(matrix[srow][j]); //top
            }
            for(int i=srow+1; i<=erow; i++){
                result.push_back(matrix[i][ecol]); //right
            }
            for(int j=ecol-1; j>=scol; j--){
                if(srow==erow) break; //edge case:- row will print twice
                result.push_back(matrix[erow][j]); //bottom
            }
            for(int i=erow-1; i>=srow+1; i--){
                if(scol==ecol) break;   //edge case:- column will print twice
                result.push_back(matrix[i][scol]); //left
            }
            srow++;
            scol++;
            erow--;
            ecol--;
        }
        return result;
    }
};