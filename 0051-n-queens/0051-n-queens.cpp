class Solution {
public:
    //O(n!*n)
    // bool isSafe(vector<string>& board, int row, int k, int n){
    //     // for(int j=0; j<n; j++){   //horizontol check
    //     //     if(board[row][j]=='Q') return false;
    //     // }
    //     for(int i=0; i<row; i++){  //vertical check
    //         if(board[i][k]=='Q') return false;
    //     }
    //     for(int i=row-1, j=k-1; i>=0 && j>=0; i--, j--){  
    //         if(board[i][j]=='Q') return false;  //left diagonal
    //     }
    //     for(int i=row-1, j=k+1; i>=0 && j<n; i--, j++){
    //         if(board[i][j]=='Q') return false;  //right diagonal
    //     }
    //     return true;
    // }

    void nqueens(vector<string>& board, int row, int n, vector<vector<string>> &ans, vector<int>& vertical, vector<int>& leftdiag, vector<int>& rightdiag){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int k=0; k<n; k++){
            // if(isSafe(board, row, k, n)) {
            if(vertical[k] == 0 && leftdiag[row - k + (n - 1)] == 0 && rightdiag[row + k] ==0) {
                board[row][k]='Q';
                vertical[k]=1;
                leftdiag[row - k + (n - 1)]=1;
                rightdiag[row+k]=1;
                nqueens(board, row+1, n, ans, vertical, leftdiag, rightdiag);
                board[row][k]='.';
                vertical[k]=0;
                leftdiag[row - k + (n - 1)]=0;
                rightdiag[row+k]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<int> vertical(n);
        vector<int> leftdiag(n+n);
        vector<int> rightdiag(n+n);

        nqueens(board, 0, n, ans, vertical, leftdiag, rightdiag);
        return ans;
    }
};