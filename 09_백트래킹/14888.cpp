#include <iostream>
#include <algorithm>

using namespace std;

int n;
int nums[12];
int oper[4];
int max_num = -1000000001;
int min_num = 1000000001;


//최댓값, 최솟값을 갱신한다.
void updateAnswer(int num) {
    // 현재 선택한 숫자 목록
    max_num = max(max_num, num);
    min_num = min(min_num, num);
}

void findMinMax(int add, int sub, int mul, int divi, int cnt, int result)
{
    if (cnt == n)
    {
        // 최댓값, 최솟값 갱신
        updateAnswer(result);
        return;
    }
    
    if(add > 0){
        findMinMax(add-1, sub, mul, divi, cnt+1, result+nums[cnt]);
    }
    if(sub > 0){
        findMinMax(add, sub-1, mul, divi, cnt+1, result-nums[cnt]);
    }
    if(mul > 0){
        findMinMax(add, sub, mul-1, divi, cnt+1, result*nums[cnt]);
    }
    if(divi > 0){
        findMinMax(add, sub, mul, divi-1, cnt+1, result/nums[cnt]);
    }
}

int main()
{
     // 입력
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    // 연산
    findMinMax(oper[0], oper[1], oper[2], oper[3], 1, nums[0]);

    // 출력
    cout << max_num << '\n' << min_num;

    return 0;
}