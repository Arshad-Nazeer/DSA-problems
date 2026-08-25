class Solution {
public:
    int count=0;
    void nqueens(int row, int n, vector<int>& vertical, vector<int>& diag, vector<int>& anti){
        if(row==n){
            count++;
            return;
        }
        for(int col=0; col<n; col++){
            if(vertical[col]==0 && diag[row-col+(n-1)]==0 && anti[row+col]==0){
                vertical[col]=1;
                diag[row-col+(n-1)]=1;
                anti[row+col]=1;
                nqueens(row+1, n, vertical, diag, anti);
                vertical[col]=0;
                diag[row-col+(n-1)]=0;
                anti[row+col]=0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<int> vertical(n);
        vector<int> diag(n+n);
        vector<int> anti(n+n);
        

        nqueens(0, n, vertical, diag, anti);
        return count;
    }
};