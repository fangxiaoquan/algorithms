#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//����������||X-Y||
double VectorMax(double *x, double *y,  int n)
{
	double max = x[0] - y[0];
	for (int i = 0; i < n; i++)
	{
		if (abs(x[i] - y[i]) > max)
		{
			max = abs(x[i] - y[i]);
		}
	}
	return max;
}
//Jacobi���������
void Jacobi(double **A, double *B, int n, double*&result)
{
	double *X = new double[n];
	double *Y = new double[n];
	for (int i = 0; i < n; i++)
	{
		X[i] = 0;
		Y[i] = 0;
	}
	int k = 1;  //��¼��������
	const int M = 100;  //����������
	const double e = 1e-6;  //��ľ���
	
	while (k < M)
	{
		cout << k << "\t";
		for (int i = 0; i < n; i++)
		{
			double sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					sum = sum + A[i][j] * X[j];
				}
			}
			Y[i] = (B[i] - sum) / A[i][i];
			cout << left << setw(8) << Y[i] << " ";
		}
		cout << endl;
		if (VectorMax(X, Y, n) <= e)
		{
			for (int i = 0; i < n;i++)
			{
				result[i] = Y[i];
			}
			delete[]X;
			delete[]Y;
			return;
		}

		k++;
		for (int i = 0; i < n; i++)
		{
			X[i] = Y[i];
		}
	}

	delete[]X;
	delete[]Y;
	return;
}
int main()
{
	int n;
	cout << "�����뷽����δ֪���ĸ���n��";
	cin >> n;

	double **A = new double*[n];
	for (int i = 0; i < n; i++)
		A[i] = new double[n];
	double *B = new double[n];
	double *result = new double[n];

	cout << "�����뷽�����ϵ������" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	cout << "�����뷽������Ҷ���������" << endl;
	for (int k = 0; k < n; k++)
	{
		cin >> B[k];
	}

	cout << "��Jacobi��������ⷽ����ĵ�������Ϊ��\nk\t";
	for (int i = 1; i <= n; i++)
	{
		cout << "x" << i << "\t ";
	}
	cout << endl;

	Jacobi(A, B, n, result);  //����Jacobi����������
	cout << "������Ľ�Ϊ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "x" << i + 1 << "=" << result[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		delete[]A[i];
	}
	delete[] A;
	delete[] B;
	delete[] result;
	return 0;
}