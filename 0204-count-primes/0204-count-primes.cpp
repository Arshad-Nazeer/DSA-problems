class Solution {
public:
    int countPrimes(int n) {
        // // brute TC:-O(n*sqrt(n))
        // int count=0;
        // for(int i=2; i<n; i++){
        //     bool flag=true;
        //     for(int j=2;  j*j<=i; j++){
        //         if(i%j==0) {
        //             flag=false;
        //             break;
        //         }
        //     }
        //     if(flag) count++;
        // }
        // return count;

        // sieve of eratosthenes TC:- O(n*log(log(n)))
        vector<bool> prime(n, true);
        int count=0;

        if(n>0) prime[0]=false;
        if(n>1) prime[1]=false;

        for(int i=2; i*i<n; i++){  
            //inner loop starts from i*i, there's no point if it exceeeds n
            if(prime[i]){  
                //to prevent looping thorughb earlier cancelled out numbers
                for(int j=i*i; j<n; j+=i){  
                    // multiples less than i*i have already been accounted for by smaller numbers
                    prime[j]=false;
                }
            }
        }

        for(bool k: prime){
            if(k) count++;
        }

        return count;
    }
};