//0-1�������⶯̬�滮
#include <iostream> 
using namespace std; 
#define MAX_NUM 10  //��Ʒ��������
#define MAX_CAPACITY 20 //������������
int m[MAX_NUM][MAX_CAPACITY];

void Knapsack(int v[],int w[],int c,int n)
{
	int jMax = min(w[n]-1,c); //����ʣ���������޷�Χ[0~w[n]-1]
	for(int j=0; j<=jMax;j++)
		m[n][j]=0;
	for(int j=w[n]; j<=c; j++) //���Ʒ�Χ[w[n]~c]
		m[n][j] = v[n];

	for(int i=n-1; i>1; i--)
	{
		jMax = min(w[i]-1,c);
		for(int j=0; j<=jMax; j++)
		{
			m[i][j] = m[i+1][j]; 
		}
		for(int j=w[i]; j<=c; j++) 
		{
			m[i][j] = max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
		}
	}
	m[1][c] = m[2][c]; //��������ֵ,����ֵ��m[1][c]����
	if(c>=w[1])
	{
		m[1][c] = max(m[1][c],m[2][c-w[1]]+v[1]);
	}
}

//x[]����洢������,0��ʾ��װ�뱳����1��ʾװ�뱳��
void Traceback(int w[],int c,int n,int x[])
{
	for(int i=1; i<n; i++)
	{
		if(m[i][c] == m[i+1][c])
		{
			x[i]=0;
		}
		else
		{
			x[i]=1;
			c-=w[i];
		}
	}
	x[n]=(m[n][c])?1:0;
}

int main()
{
	int w[10],v[10];
	int x[10];
	int n,C;
	cout<<"������Ʒ�������� ";
	cin>>n;
	cout<<"���뱳���������� ";
	cin>>C;
	cout<<"����������Ʒ�������� ";
	for(int i=1;i<=n;i++)
		cin>>w[i];
	cout<<"����������Ʒ�ļ�ֵ�� ";
	for(int i=1;i<=n;i++)
		cin>>v[i];
	Knapsack(v,w,C,n);
	Traceback(w,C,n,x);
	cout<<"���Ž�����Ϊ�� ";
	for(int i=1;i<=n;i++)
		cout<<x[i]<<" ";
	cout<<endl<<"����ֵΪ�� "<<m[1][C]<<endl;
	return 0;
}
