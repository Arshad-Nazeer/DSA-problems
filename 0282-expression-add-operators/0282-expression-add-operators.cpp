class Solution {
public:
    void backtrack(string &num, int target, int idx, long long value, long long last, string& temp, vector<string>& result){
        // TC:- O(n^2*3^n)
        if(idx==num.size()) {
            if(value==target) result.push_back(temp);
            return;
        }
        for(int k=idx; k<num.size(); k++){
            string str=num.substr(idx, k-idx+1);
            if(k!=idx && num[idx] == '0') break; //invalid leading zero
            long long curr=stoll(str);
            int len=temp.size();
            if(idx==0){
                backtrack(num, target, k+1, curr, curr, str, result);
            }else{
                temp+='+'+str;
                backtrack(num, target, k+1, value+curr, curr, temp, result);
                temp.resize(len);
                temp+='-'+str;
                backtrack(num, target, k+1, value-curr, -curr, temp, result);
                temp.resize(len);
                temp+='*'+str;
                backtrack(num, target, k+1, value-last+last*curr, last*curr, temp, result);
                temp.resize(len);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string temp="";
        backtrack(num, target, 0, 0, 0, temp, result);
        return result;
    }
};