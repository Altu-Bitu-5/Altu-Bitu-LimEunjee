#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int ALPH = 26;

int palindromeCheck(int count[])
{
    int oddcnt = 0;
    
    for(int i = 0; i < ALPH; i++){
        if(count[i] % 2 == 1){
            oddcnt++;
        }
    }
    
    if(oddcnt > 1){
        return 0;
    }
    else{
        return 1;
    }
}

void palindrome(int count[], int cnt)
{
    int times, oddcheck = 0;
    char letter, mid;
    
    for(int i = 0; i < ALPH; i++){
        times = count[i] / 2;
        if(oddcheck == 0 && count[i] % 2 == 1){
            mid = 65 + i;
            oddcheck = 1;
            count[i]--;
        }
        count[i] -= times;
        letter = 65 + i;
        for(int j = 0; j < times; j++){
            cout << letter;
        }
    }
    
    if(cnt % 2 == 1){
        cout << mid;
    }
    
    for(int i = ALPH-1; i >= 0; i--){
        times = count[i];
        letter = 65 + i;
        for(int j = 0; j < times; j++){
            cout << letter;
        }
    }
}

int main()
{
    string name;
    char letter;
    int results, cnt = 0;
    int count[ALPH] = {0, };
    
    cin >> name;
    
    for(int i = 0; i < name.length(); i++){
        letter = name[i];
        count[letter-65] += 1;
        cnt++;
    }
    
    results = palindromeCheck(count);
    if(results == 0){
        cout << "I'm Sorry Hansoo\n";
    }
    else{
        palindrome(count, cnt);
    }
    
    return 0;
}