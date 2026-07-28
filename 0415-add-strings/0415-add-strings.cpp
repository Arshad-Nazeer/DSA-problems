class Solution {
public:
    string addStrings(string num1, string num2){
        //optimal approach
        string ans;
        int i=num1.length()-1, j=num2.length()-1, carry=0;
        while(i>=0 || j>=0 || carry){
            int sum=carry;

            if(i>=0) sum+=num1[i--]-'0';
            if(j>=0) sum+=num2[j--]-'0';

            ans.push_back((sum%10)+'0');
            carry=sum/10;
        }
        reverse(ans.begin(), ans.end());
        return ans;

        // brute approach
        // string ans;
        // int i=num1.length()-1, j=num2.length()-1, carry=0;
        // while(i>=0 && j>=0){
        //     int sum=(num1[i--]-'0')+(num2[j--]-'0')+carry;
        //     ans.push_back((sum%10)+'0');
        //     carry=sum/10;
        // }       
        // while(i>=0){
        //     int sum=(num1[i--]-'0')+carry;
        //     ans.push_back((sum%10)+'0');
        //     carry=sum/10;
        // }
        // while(j>=0){
        //     int sum=(num2[j--]-'0')+carry;
        //     ans.push_back((sum%10)+'0');
        //     carry=sum/10;
        // }
        // if(carry){
        //     ans.append(to_string(carry));
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
    }
};
