class Solution {
public:
    string countAndSay(int n) {
        string ans="1";

        for(int k=0; k<n-1; k++){
            int count=1;
            string temp="";
            for(int i=1; i<ans.size(); i++){
                if(ans[i]==ans[i-1])count++;
                else{
                    temp+=to_string(count);
                    temp+=ans[i-1];
                    count=1;
                }
            }
            temp+=to_string(count);
            temp+=ans.back();
            ans=temp;
        }
        return ans;
    }
};