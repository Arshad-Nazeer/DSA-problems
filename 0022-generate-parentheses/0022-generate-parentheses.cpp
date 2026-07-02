class Solution {
public:
    // bool check(string& str){
    //     int k=0;
    //     for(char &c: str){
    //         if(c=='(') k++;
    //         else {
    //             k--;
    //             if(k<0) return false;
    //         }
    //     }
    //     return !k;
    // }

    // void generate(vector<string>& result, string str, int n){
    //     if(str.length()==n*2) {
    //         if(check(str)) result.push_back(str);
    //         return ;
    //     }

    //     str+='(';
    //     generate(result, str, n);
    //     str.pop_back();
    //     str+=')';
    //     generate(result, str, n);
    //     str.pop_back();
    // }

    void backtrack(vector<string>& result, string& str, int n, int open, int close){
        if(str.size()==2*n) {
            result.push_back(str);
            return;
        }
        if(open<n){
            str.push_back('(');
            backtrack(result, str, n, open+1, close);
            str.pop_back();
        }
        if(close<open){
            //close<n && close!=open
            //close can never exceed open, this condition also incorporates clsoe<n, it also prunes incorrect branches
            str.push_back(')');
            backtrack(result, str, n, open, close+1);
            str.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        // //recursion
        // // brute force
        // // TC:-O(n*2^(2*n)), Sc:- O(n)
        // vector<string> result;
        // generate(result, "", n);
        // return result;

        // optimal
        // Backtracking
        // TC:- O(number of valid parentheses combo)
        // TC:- O(n) // maximum recursion depth is 2*n
        vector<string> result;
        string str="";
        backtrack(result, str, n, 0, 0);
        return result;
    }
};
