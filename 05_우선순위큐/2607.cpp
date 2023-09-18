#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool checkSame(priority_queue<char> first, priority_queue<char> second)
{
    int size = first.size();

    while (size--)
    {
        if (first.top() != second.top()) {
            return false;
        }
        first.pop();
        second.pop();
    }
    return true;
}

bool checkSimilar1(priority_queue<char> first, priority_queue<char> second)
{
    int diff_cnt = 0;
    int size = first.size();

    int second_check[26] = { 0 , };
    for (int i = 0; i < size; i++) {
        second_check[second.top() - 'A'] += 1;
        second.pop();
    }

    while (size--)
    {
        second_check[first.top() - 'A'] -= 1;
        if (second_check[first.top() - 'A'] < 0) {
            diff_cnt++;
        }
        if (diff_cnt == 2) {
            return false;
        }
        first.pop();
    }
    return true;
}

bool checkSimilar2(priority_queue<char> first, priority_queue<char> second)
{
    int diff_cnt = 0;

    if (first.size() < second.size()) {
        swap(first, second);
    }

    int size = second.size();
    while (size--)
    {
        if (first.top() == second.top()) {
            first.pop();
            second.pop();
        }
        else {
            diff_cnt++;
            if (diff_cnt == 2) {
                return false;
            }
            first.pop();
        }
    }
    return true;
}


int main()
{
    int n;
    int count = 0;
    string first, word;
    bool flag;
    priority_queue<char> standard;

    cin >> n >> first;
    for (int i = 0; i < first.length(); i++) {
        standard.push(first[i]);
    }

    while (n > 1)
    {
        n--;
        cin >> word;

        priority_queue<char> compare;
        for (int i = 0; i < word.length(); i++) {
            compare.push(word[i]);
        }

        int length1 = first.length();
        int length2 = word.length();

        if (abs(length1 - length2) > 1) {
            continue;
        }

        if (first.length() == word.length()) {
            flag = checkSame(standard, compare);
            
            if (flag == true) {
                count++;
                continue;
            }
            flag = checkSimilar1(standard, compare);
            if (flag == true) {
                count++;
                continue;
            }
        }

        flag = checkSimilar2(standard, compare);
        if (flag == true) {
            count++;
            continue;
        }
    }

    cout << count;
    return 0;
}