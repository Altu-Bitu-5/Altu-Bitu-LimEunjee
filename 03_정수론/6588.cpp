#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000001;

vector<bool> isPrime()
{
    vector<bool> primes(MAX, true);
    
    primes[0] = primes[1] = false;
    for(int i = 2; i*i <= MAX; i++){
        if(!primes[i]){
            continue;
        }
        for(int j = i * i; j <= MAX; j += i){
            primes[j] = false;
        }
    }
    return primes;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n;
    vector<bool> is_prime;
    
    is_prime = isPrime();
   
   // 입력 & 연산 & 출력
   while(true){
       bool check = false;
       
       cin >> n;
       if(n == 0){
           break;
       }
       
       for(int i = 3; i < n/2+1 ; i += 2){
           if(is_prime[i] == true && is_prime[n-i] == true){
               cout << n << " = " << i << " + " << n-i << "\n";
               check = true;
               break;
           }
        }
        
        if(check == false){
           cout << "Goldbach's conjecture is wrong.\n";
        }
   }
    return 0;
}