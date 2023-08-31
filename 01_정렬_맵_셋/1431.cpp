#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int numbersum(string serial)
{
	int sum = 0;

	for (int i = 0; i < serial.length(); i++)
		if (isdigit(serial[i]))
			sum += serial[i] - '0';

	return sum;
}

bool cmp(string serial1, string serial2)
{
	if (serial1.length() != serial2.length()){
		return serial1.length() < serial2.length();
	}


	if (numbersum(serial1) != numbersum(serial2)){
		return numbersum(serial1) < numbersum(serial2);
	}

	else{
		return serial1 < serial2;
	}
	
}

int main()
{
	int N;
	cin >> N;

	vector<string> serial(N);
	for (int i = 0; i < N; i++)
		cin >> serial[i];

	sort(serial.begin(), serial.end(), cmp);

	for (int i = 0; i < N; i++)
		cout << serial[i] << "\n";

	return 0;
}