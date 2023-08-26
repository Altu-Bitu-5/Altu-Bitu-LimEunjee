#include<iostream>
#include<cmath>

using namespace std;

int nochange(int day, int weight, int basic, int I, int A)
{
	for (int i = 0; i < day; i++)
		weight += (I - (basic + A));

	if (weight <= 0)
		cout << "Danger Diet\n";
	else
		cout << weight << " " << basic << "\n";

	return 0;
}

int yeschange(int day, int weight, int basic, int I, int A, int T)
{
	int basic_orgin = basic;

	for (int i = 0; i < day; i++)
	{
		weight += (I - (basic + A));

		if (abs(I - (basic + A)) > T)
			basic += floor((I - (basic + A)) / 2.0);
	}

	if (weight <= 0 || basic <= 0)
		cout << "Danger Diet\n";
	else
	{
		cout << weight << " " << basic << " ";
		if ((basic_orgin - basic) > 0)
			cout << "YOYO";
		else
			cout << "NO";
	}

	return 0;
}

int main()
{
	int weight, basic, T, D, I, A;
	cin >> weight >> basic >> T;
	cin >> D >> I >> A;

	nochange(D, weight, basic, I, A);
	yeschange(D, weight, basic, I, A, T);

	return 0;
}
