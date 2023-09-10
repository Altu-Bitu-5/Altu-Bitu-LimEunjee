#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true)
    {
        stack<char> st;
        string str;
        getline(cin, str);

        if (str[0] == '.')
            break;

        int check = 0;
        for (int i = 0; i < str.length()-1; i++)
        {
            char flag = str[i];

            if (flag == '(' || flag == '[')
                st.push(flag);
            if (flag == ')')
            {
                if (!st.empty() && st.top() == '(') st.pop();
                else
                {
                    check = 1;
                    break;
                }
            }
            if (flag == ']')
            {
                if (!st.empty() && st.top() == '[') st.pop();
                else
                {
                    check = 1;
                    break;
                }
            }
        }
        if (st.empty() && check == 0)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
