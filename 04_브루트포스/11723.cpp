#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    string op;
    int count, num;
    cin >> count;
    
    int bitmasking = 0;
    
    while(count--)
    {
        cin >> op;
        if(op == "add"){
            cin >> num;
            bitmasking = bitmasking | (1 << num);
        }
        else if(op == "remove"){
            cin >> num;
            bitmasking = bitmasking & ~(1 << num);
        }
        else if(op == "check"){
            cin >> num;
            if(bitmasking & (1 << num)){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(op == "toggle"){
            cin >> num;
            bitmasking = bitmasking ^ (1 << num);
        }
        else if(op == "all"){
            bitmasking = 2097150;
        }
        else{
            bitmasking = 0;
        }
        
    }
    
    return 0;
}