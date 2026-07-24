class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //sliding window
        if(s1.size() > s2.size()) return false;
        vector<int> freq(26);
        vector<int> freq2(26);
        for(char &c: s1){
            freq[c-'a']++;
        }
        for(int i=0; i<s1.size(); i++){
            freq2[s2[i]-'a']++;
        }
        if(freq==freq2) return true;

        int i=0;
        for(int j=s1.size(); j<s2.size(); j++){
            freq2[s2[j]-'a']++;
            freq2[s2[i]-'a']--;
            if(freq==freq2) return true;
            i++;
        }
        return false;

        // //freq appraoach
        // if(s1.size() > s2.size()) return false;
        // for(int i=0; i<s2.size()-s1.size()+1; i++){
        //     bool flag=true;
        //     string str=s2.substr(i, s1.size());
        //     vector<int> freq(26);
        //     for(char &c: s1){
        //         freq[c-'a']++;
        //     }
        //     for(char &c: str){
        //         freq[c-'a']--;
        //     }
        //     for(int &k: freq){
        //         if(k!=0) {
        //             flag=false;
        //             break;
        //         }
        //     }
        //     if(flag==true) return true;
        // }
        // return false;

        // //sort approach
        // sort(s1.begin(), s1.end());
        // for(int i=0; i<s2.size(); i++){
        //     string sub=s2.substr(i, s1.size());
        //     sort(sub.begin(), sub.end());
        //     if(sub==s1) return true;
        // }
        // return false;

        // if(s1.size() > s2.size()) return false;
        // vector<int> freq(26);
        // for(int i=0; i<s1.length(); i++){
        //     freq[s1[i]-'a']++;
        // }

        // for(int i=0; i<s2.length()-s1.length()+1; i++){
        //    vector<int> freq2(26);    
        //    bool flag=true;
        //    for(int j = 0; j < s1.length(); j++){
        //         freq2[s2[i + j] - 'a']++;
        //     }
        //    for(int j=0; j<26; j++){
        //         if(freq[j]!=freq2[j]) {
        //             flag=false;
        //             break;
        //         }
        //    }
        //    if(flag) return true;
        // }
        // return false;
    }
};