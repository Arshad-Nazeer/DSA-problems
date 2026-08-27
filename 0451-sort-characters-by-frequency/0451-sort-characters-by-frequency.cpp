class Solution {
public:
    string frequencySort(string s) {
        //bucket sort  TC:-O(n), SC:-O(n)
        unordered_map<char, int> freq;
        for(char &c: s) freq[c]++;
        vector<string> buckets(s.size()+1);
        for(auto &k: freq){
            // buckets[k.second].append(k.second, k.first);
            buckets[k.second].push_back(k.first);
        }
        s="";
        for(int i=buckets.size()-1; i>0; i--){
            // s+=buckets[i];
            for(char &c: buckets[i]) s.append(i, c);
        }
        return s;
        
        // //priority queue TC:-O(n), SC:-O(n);
        // unordered_map<char, int> freq;
        // for(char &c: s) freq[c]++;
        // priority_queue<pair<int, char>> pq;
        // for(auto &k: freq){
        //     pq.push({k.second, k.first});
        // }
        // s="";
        // while(!pq.empty()){
        //     auto [i, c]=pq.top();
        //     s.append(i, c);   //append multiple times: (number of times, string) default:- (string, start index, number of char)
        //     pq.pop();
        // }
        // return s;

        // //map-based custom comparator TC:-O(nlogn), SC:-O(k);
        // unordered_map<char, int> freq;
        // for(char &c: s) freq[c]++;
        // sort(s.begin(), s.end(), [&](char a, char b){
        //     if(freq[a]==freq[b]) return a>b;  //comparator function would return false for both cases (a, b) and (b, a) if not for this line
        //     return freq[a]>freq[b];
        // });
        // return s;

        // //map based approach  TC:- O(n+klogk), SC:-O(k)
        // unordered_map<char, int> mp;
        // for(char &c: s){
        //     mp[c]++;
        // }
        // s="";
        // map<int, vector<char>, greater<int>> freq;
        // for(auto &k: mp){
        //     freq[k.second].push_back(k.first);
        // }
        // for(auto &k: freq){
        //     for(char &c: k.second){
        //         s.append(k.first, c);
        //     }
        // }
        // return s;
    }
};