class Solution {
public:
    bool check(string& str){
        int k=0;
        for(char &c: str){
            if(c=='(') k++;
            else {
                k--;
                if(k<0) return false;
            }
        }
        return !k;
    }

    void generate(vector<string>& result, string str, int n){
        if(str.length()==n*2) {
            if(check(str)) result.push_back(str);
            return ;
        }

        str+='(';
        generate(result, str, n);
        str.pop_back();
        str+=')';
        generate(result, str, n);
        str.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "", n);
        return result;
    }
};