#include <iostream>
#include <string>
#include <vector>

using namespace std;

int moveR(pair<char, int> &kinglo, pair<char, int> &stonelo)
{
    if(kinglo.first == 'H'){
        return 0;
    }
    
    if(((char)(kinglo.first + 1) == stonelo.first) && (kinglo.second == stonelo.second)){
        if(stonelo.first == 'H'){
            return 0;
        }
        stonelo.first = (char)(stonelo.first + 1);
    }
    
    kinglo.first = (char)(kinglo.first + 1);
    return 0;
}

int moveL(pair<char, int> &kinglo, pair<char, int> &stonelo)
{
    if(kinglo.first == 'A'){
        return 0;
    }
    
    if(((char)(kinglo.first - 1) == stonelo.first) && (kinglo.second == stonelo.second)){
        if(stonelo.first == 'A'){
            return 0;
        }
        stonelo.first = (char)(stonelo.first - 1);
    }
    
    kinglo.first = (char)(kinglo.first - 1);
    return 0;
}

int moveB(pair<char, int> &kinglo, pair<char, int> &stonelo)
{
    if(kinglo.second == 1){
        return false;
    }
    
    if((kinglo.first == stonelo.first) && ((kinglo.second - 1) == stonelo.second)){
        if(stonelo.second == 1){
            return 0;
        }
        stonelo.second -= 1;
    }
    
    kinglo.second -= 1;
    return true;
}

int moveT(pair<char, int> &kinglo, pair<char, int> &stonelo)
{
    if(kinglo.second == 8){
        return 0;
    }
    
    if((kinglo.first == stonelo.first) && ((kinglo.second + 1) == stonelo.second)){
        if(stonelo.second == 8){
            return 0;
        }
        stonelo.second += 1;
    }
    
    kinglo.second += 1;
    return 0;
}

int moveRT(pair<char, int> &kinglo, pair<char, int> &stonelo)
{
    if(kinglo.first == 'H' || kinglo.second == 8){
        return 0;
    }
    
    if(((char)(kinglo.first + 1) == stonelo.first) && ((kinglo.second + 1) == stonelo.second)){
        if(stonelo.first == 'H' || stonelo.second == 8){
            return 0;
        }
        stonelo.first = (char)(stonelo.first + 1);
        stonelo.second += 1;
    }
    
    kinglo.first = (char)(kinglo.first + 1);
    kinglo.second += 1;
    return 0;
}

int moveLT(pair<char, int> &kinglo, pair<char, int> &stonelo)
{
    if(kinglo.first == 'A' || kinglo.second == 8){
        return 0;
    }
    
    if(((char)(kinglo.first - 1) == stonelo.first) && ((kinglo.second + 1) == stonelo.second)){
        if(stonelo.first == 'A' || stonelo.second == 8){
            return 0;
        }
        stonelo.first = (char)(stonelo.first - 1);
        stonelo.second += 1;
    }
    
    kinglo.first = (char)(kinglo.first - 1);
    kinglo.second += 1;
    return 0;
}

int moveRB(pair<char, int> &kinglo, pair<char, int> &stonelo)
{
    if(kinglo.first == 'H' || kinglo.second == 1){
        return 0;
    }
    
    if(((char)(kinglo.first + 1) == stonelo.first) && ((kinglo.second - 1) == stonelo.second)){
        if(stonelo.first == 'H' || stonelo.second == 1){
            return 0;
        }
        stonelo.first = (char)(stonelo.first + 1);
        stonelo.second -= 1;
    }
    
    kinglo.first = (char)(kinglo.first + 1);
    kinglo.second -= 1;
    return 0;
}

int moveLB(pair<char, int> &kinglo, pair<char, int> &stonelo)
{
    if(kinglo.first == 'A' || kinglo.second == 1){
        return 0;
    }
    
    if(((char)(kinglo.first - 1)) == stonelo.first && ((kinglo.second - 1) == stonelo.second)){
        if(stonelo.first == 'A' || stonelo.second == 1){
            return 0;
        }
        stonelo.first = (char)(stonelo.first - 1);
        stonelo.second -= 1;
    }
    
    kinglo.first = (char)(kinglo.first - 1);
    kinglo.second -= 1;
    return 0;
}


int main()
{
    pair<char, int> kinglo, stonelo;
    string op;
    int n;
    
    cin >> kinglo.first >> kinglo.second;
    cin >> stonelo.first >> stonelo.second;
    cin >> n;
    
    while(n--)
    {
        cin >> op;
        
        if(op == "R"){
            moveR(kinglo, stonelo);
        }
        else if(op == "L"){
            moveL(kinglo, stonelo);
        }
        else if(op == "B"){
            moveB(kinglo, stonelo);
        }
        else if(op == "T"){
            moveT(kinglo, stonelo);
        }
        else if(op == "RT"){
            moveRT(kinglo, stonelo);
        }
        else if(op == "LT"){
            moveLT(kinglo, stonelo);
        }
        else if(op == "RB"){
            moveRB(kinglo, stonelo);
        }
        else{
            moveLB(kinglo, stonelo);
        }
    }
    
    cout << kinglo.first << kinglo.second << "\n";
    cout << stonelo.first << stonelo.second << "\n";
    
    return 0;
}