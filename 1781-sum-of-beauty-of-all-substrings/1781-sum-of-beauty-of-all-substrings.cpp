class Solution {
public: 
    int beautySum(string s) {
        // TC:- O(n*n*26) -> O(n^2)
        int ans=0, n=s.size();
        for(int i=0; i<n; i++){
            int freq[26]={0};
            for(int j=i; j<n; j++){
                int maxele=INT_MIN, minele=INT_MAX;
                freq[s[j]-'a']++;
                for(int k: freq){
                    if(k){ 
                        maxele=max(maxele, k);
                        minele=min(minele, k);
                    }
                }
                ans+=maxele-minele;
            }
        }
        return ans;
    }
};