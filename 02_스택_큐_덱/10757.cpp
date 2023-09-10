#include <iostream>
#include <string>
#include <vector>

using namespace std;

int bignumbersum(vector<int> n1, vector<int> n2, int alength, int blength)
{
	int flag = 0;
	vector<int> result;

	if (alength == blength)
	{
		for (int i = alength - 1; i >= 0; i--)
		{
			int sum = n1[i] + n2[i];
			if (flag == 0)
			{
				if (sum >= 10)
				{
					result.push_back(sum - 10);
					flag = 1;
				}
				else
				{
					result.push_back(sum);
					flag = 0;
				}
			}
			else
			{
				if (sum >= 9)
				{
					result.push_back(sum + 1 - 10);
					flag = 1;
				}
				else
				{
					result.push_back(sum + 1);
					flag = 0;
				}
			}
		}

		if (flag == 1)
			cout << 1;

		for (int i = 0; i < alength; i++)
		{
			cout << result.back();
			result.pop_back();
		}
	}

	else
	{
		int longer, shorter;
		vector<int> longvector;
		vector<int> shortvector;
		if (alength - blength > 0) 
		{
			longer = alength;
			longvector = n1;
			shorter = blength;
			shortvector = n2;
		}
		else
		{
			longer = blength;
			longvector = n2;
			shorter = alength;
			shortvector = n1;
		}

		int differ = longer - shorter;
		for (int i = longer - 1; i >= differ; i--)
		{
			int sum = longvector[i] + shortvector[i-differ];
			if (flag == 0)
			{
				if (sum >= 10)
				{
					result.push_back(sum - 10);
					flag = 1;
				}
				else
				{
					result.push_back(sum);
					flag = 0;
				}
			}
			else
			{
				if (sum >= 9)
				{
					result.push_back(sum + 1 - 10);
					flag = 1;
				}
				else
				{
					result.push_back(sum + 1);
					flag = 0;
				}
			}
		}

		for (int i = differ - 1; i >= 0; i--)
		{
			if (flag == 1)
			{
				if (longvector[i] == 9)
				{
					result.push_back(0);
					flag = 1;
				}
				else
				{
					result.push_back(longvector[i]+1);
					flag = 0;
				}
			}
			else
				result.push_back(longvector[differ - 1]);
			differ--;
		}

		if (flag == 1)
			cout << 1;

		for (int i = 0; i < longer; i++)
		{
			cout << result.back();
			result.pop_back();
		}
	}

	return 0;
}

int main()
{
	string A, B;
	cin >> A >> B;
	vector<int> num1, num2;

	for (int i = 0; i < A.length(); i++)
		num1.push_back(A[i]- '0');

	for (int i = 0; i < B.length(); i++)
		num2.push_back(B[i] - '0');

	bignumbersum(num1, num2, A.length(), B.length());

	return 0;
}
