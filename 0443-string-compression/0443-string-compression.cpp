class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0;
        for(int i=0; i<chars.size(); ){
            char c=chars[i];
            int count=0;
            while(i<chars.size() && chars[i]==c){
                count++;
                i++;
            }
            if(count==1) chars[idx++]=c;
            else{
                chars[idx++]=c;
                string str=to_string(count);
                for(char &digit: str){
                    chars[idx++]=digit;
                }
            }
        }
        chars.resize(idx);   //vector.resize(new_size, value);
        return idx;
    }
};