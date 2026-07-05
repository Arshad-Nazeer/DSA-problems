class Solution {
public:
    void recur(vector<string>& result, string& digits, int idx, string& temp, vector<string>& keypad){
        if(idx==digits.size()){
            result.push_back(temp);
            return;
        }
        for(char &c: keypad[digits[idx]-'0']){
            temp.push_back(c);
            recur(result, digits, idx+1, temp, keypad);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        //TC:- O(n*3^n-k*4^k)  total digits=n, string copy->n, {7, 9}=k digits, rest=> n-k digits
        if (digits.empty()) return {};
        vector<string> keypad={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string temp="";
        recur(result, digits, 0, temp, keypad);
        return result;
    }
};