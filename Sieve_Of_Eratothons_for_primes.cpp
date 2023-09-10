class solution{
    public:
          void countPrimes(int n) {
                vector<bool> prime(n,true);
                int count = 0;
                for(int i = 2; i < n; i++){
                    if(prime[i]){
                        for(long long j = (long long)i*i; j < n; j = j + i){
                            prime[j] = false;
                        }
                    }
                }    
                for(int i= 2; i < n; i++){
                    if(prime[i]){
                        cout<<i<<endl;
                    }
                }
                return count;
            }
};
