class Solution {
public:
    void recur(vector<string>& result, string& digits, int idx, string& temp, unordered_map<char, string>& keypad){
        if(idx==digits.size()){
            result.push_back(temp);
            return;
        }
        for(char &c: keypad[digits[idx]]){
            temp.push_back(c);
            recur(result, digits, idx+1, temp, keypad);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        //TC:- O(n*3^n-k*4^k)  total digits=n, string copy->n, {7, 9}=k digits, rest=> n-k digits
        if (digits.empty()) return {};
        unordered_map<char, string> keypad={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> result;
        string temp="";
        recur(result, digits, 0, temp, keypad);
        return result;
    }
};