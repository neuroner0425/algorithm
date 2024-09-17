#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if ((!(n % 2) && n % 6 != 2) || ((n % 2) && (n - 1) % 6 != 2))
	{
		if ((n % 2)) n--;
		for (int i = 1; i <= n / 2; i++)
			cout << 2 * i << '\n';
		for (int i = 1; i <= n / 2; i++)
			cout << 2 * i - 1 << '\n';
		if ((n % 2)) cout << n + 1 << '\n';
	}
	else if ((!(n % 2) && n / 6 != 0) || ((n % 2) && (n - 1) / 6 != 2))
	{
		if ((n % 2)) n--;
		for (int i = 1; i <= n / 2; i++)
			cout << 1 + (2 * i + n / 2 - 3) % n << '\n';
		for (int i = n / 2; i > 0; i--)
			cout << n - (2 * i + n / 2 - 3) % n << '\n';
		if ((n % 2)) cout << n + 1 << '\n';
	}
}