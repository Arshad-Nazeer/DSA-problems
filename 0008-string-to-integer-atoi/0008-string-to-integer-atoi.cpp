class Solution {
public:
    int recur(string &s, int i, int ans, int sign){
        if(i==s.size() || !isdigit(s[i])) return sign*ans;
        if(ans>(INT_MAX-(s[i]-'0'))/10) return sign==1 ? INT_MAX: INT_MIN;
        ans=ans*10+(s[i]-'0');
        return recur(s, i+1, ans, sign);
    }

    // int recur(string &s, int i, int ans, int sign, bool started){
    //     if(i==s.size()) return sign*ans;
    //     if(!started && s[i]==' ') return recur(s, i+1, ans, sign, started);
    //     if(!started && (s[i]=='-' || s[i]=='+')) return recur(s, i+1, ans, s[i]=='-' ? -1 : 1, true); //started set to true after first sign encountered so that all the if conditions doesnt corrupt the ans
    //     if(!isdigit(s[i])) return sign*ans;
    //     if(ans>(INT_MAX-(s[i]-'0'))/10) return sign==1 ? INT_MAX: INT_MIN;
    //     ans=ans*10+(s[i]-'0');
    //     return recur(s, i+1, ans, sign, true);
    // }

    int myAtoi(string s) {
        int i=0, sign=1, num=0;
        while(i<s.size() && s[i]==' ') i++;
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        return recur(s, i, 0, sign);//helper recursion
        // //leading zeroes are handled automatically
        // while(i<s.size() && isdigit(s[i])){
        //     if(num>(INT_MAX-(s[i]-'0'))/10) return sign==1 ? INT_MAX: INT_MIN;
        //     num=num*10+(s[i]-'0');
        //     i++;
        // }
        // return sign*num;

        // // pure recursive approach
        // return recur(s, 0, 0, 1, false);
    }
};