#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, count;
    cin >> n;

    int number = 666;
    string strnumber;
    
    while(true)
    {
        strnumber = to_string(number);
        if(strnumber.find("666") != string::npos){
            count ++;
        }
        if(count == n){
            break;
        }
        
        number++;
    }
    
    cout << number;
}