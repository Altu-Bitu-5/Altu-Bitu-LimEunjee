#include <iostream>
#include <algorithm>

using namespace std;

int calcdenomi(int dn1, int nt1, int dn2, int nt2, int lcm)
{
    int count1 = lcm / nt1;
    int count2 = lcm / nt2;
    int sum = (count1 * dn1) + (count2 * dn2);
    
    return sum;
}

int findgcd(int nt1, int nt2)
{
    while(nt2){
        nt1 %= nt2;
        swap(nt1, nt2);
    }
    return nt1;
}

int main()
{
    // 입력
    int dn1, dn2, nt1, nt2;
    cin >> dn1 >> nt1 >> dn2 >> nt2;
    
    // 연산
    int gcd = findgcd(max(nt1, nt2), min(nt1, nt2));
    int lcm = nt1 * nt2 / gcd;
    int denominator = calcdenomi(dn1, nt1, dn2, nt2, lcm);
    
    int fraction_gcd = findgcd(denominator, lcm);
    denominator /= fraction_gcd;
    lcm /= fraction_gcd;
    
    // 출력
    cout << denominator << " " << lcm << "\n";
    return 0;
}