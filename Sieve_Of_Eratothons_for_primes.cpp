class solution{
    public:
          void count_primes(int n){
                vector<bool> primes(n+1,false);
                for(int i = 2; i <= n; i++){
                        if(!prime[i]){
                            for(int j = i*i; j <= n; j = j + i){
                                prime[j] = true;
                            }
                        }
                }
                for(int i = 2; i <= n; i++){
                      if(!prime[i]){
                          cout<<prime[i]<<endl;
                      }
                }
          }
};
