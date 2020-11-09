#include <iostream>
#include <cmath>
using namespace std;
double j(const double x);
int main()
{
	double kp, kk, z;
	int n;
	cout << "kp = "; cin >> kp;
	cout << "kk = "; cin >> kk;
	cout << "n = "; cin >> n;
	double dk = (kk - kp) / n;
	double k = kp;
	while (k <= kk)
	{
		z = j(1 + k + j(k)) + pow((j(1 + (k*k))), 2);
		cout << k << " " << z << endl;
		k += dk;
	}
	return 0;
}
double j(const double x)
{
	if (abs(x) >= 1)
		return ((cos(x)+exp(-abs(x)))/(cos(x*x)+1));
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = x * x * x / (((2*i + 1) - 2) * ((2 * i + 1) - 1) * (2 * i + 1));
			a *= R;
			S += a;
		} while (i < 5);
		return S;
	}
}