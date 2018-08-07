#include <iostream>
#include <cmath>
using namespace std;

//Newton����ⷽ��
//������ͬ��ֵx0
void CalNewton(double x0, double *fx, int n)
{
	const double e = 1e-5;  //��������
	const int MAX_NUM = 100;  //��������������
	int k = 0;   //��¼��������
	 
	//����f'(x)��ϵ����
	double *f = new double[n];
	for (int i = n-1; i >= 0; i--)
	{
		f[i] = (i + 1)*fx[i + 1];
	}

	double xk = x0;
	double xk1;
	double fx_k;
	double f_k;
	while (k < MAX_NUM)
	{
		fx_k = 0;
		f_k = 0;
		//����f(xk)
		for (int i = n; i >= 0; i--)
		{
			fx_k += fx[i] * pow(xk, i);
		}
		//����f'(xk)
		for (int i = n - 1; i >= 0; i--)
		{
			f_k += f[i] * pow(xk, i);
		}
		//Newton����ʽ
		xk1 = xk - fx_k / f_k;

		cout << k << "\t" << xk << endl;
		if (abs(xk1 - xk) < e)
		{
			cout << k+1 << "\t" << xk1 << endl;
			return;
		}
		k++;
		xk = xk1;
	}
	delete[]f;
	return;
}

int main()
{
	int n;
	double x0;

	cout << "�����뷽�̵���߽״�����";
	cin >> n;

	double *fx = new double[n+1];
	cout << "�����뷽�̵�ϵ���";
	for (int i = n; i >=0; i--)
	{
		cin >> fx[i];
	}
	while (true)
	{
		cout << "�������ֵx0��";
		cin >> x0;
		cout << "k\tx(k)" << endl;
		CalNewton(x0, fx, n);
		char ch;
		cout << "��������Y/N��";
		cin >> ch;
		if (ch == 'N' || ch == 'n')
		{
			break;
		}
	}
	
	delete[]fx;
	return 0;
}