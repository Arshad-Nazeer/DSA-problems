class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //hashing
        // unordered_map<char, char> mp2, mp;  //strictly one-to-one mapping
        // for(int i=0; i<s.size(); i++){
        //     if(mp.count(s[i]) && mp[s[i]]!=t[i]) return false;
        //     if(mp2.count(t[i]) && mp2[t[i]]!=s[i]) return false;
        //     mp2[t[i]]=s[i];
        //     mp[s[i]]=t[i];
        // }
        // return true;

        //vector
        // vector<int> arr(256, -1);
        // vector<int> arr2(256, -1);
        // for(int i=0; i<s.size(); i++){
        //     if((arr[s[i]]!=-1 && arr[s[i]]!=t[i]) || (arr2[t[i]]!=-1 && arr2[t[i]]!=s[i])) return false;
        //     arr[s[i]]=t[i];
        //     arr2[t[i]]=s[i];
        // }
        // return true;

        // //last occurence
        // vector<int> arr(256, -1);
        // vector<int> arr2(256, -1);  
        // for(int i=0; i<s.size(); i++){
        //     if(arr[s[i]]!=arr2[t[i]]) return false;
        //     arr[s[i]]=i;
        //     arr2[t[i]]=i;
        // }
        // return true;

        unordered_map<char, int> mp2, mp;
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]]!=mp2[t[i]]) return false;
            mp[s[i]]=i+1;  //because default value in map is 0
            mp2[t[i]]=i+1;
        }
        return true;
    }
};