//0-1�������⶯̬�滮
#include<iostream>
using namespace std;
#define MAX_NUM 10 //��Ʒ��������
#define MAX_CAPACITY 20 //������������
int c[MAX_NUM][MAX_CAPACITY];

void Knapsack(int w[],int v[],int n,int C)
{
	for(int i=0;i<=C;i++)
		c[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=0;
		for(int j=1;j<=C;j++)
		{
			if(w[i]<=j)
			{
				if(v[i]+c[i-1][j-w[i]] > c[i-1][j])
					c[i][j] = v[i]+c[i-1][j-w[i]];
				else c[i][j] = c[i-1][j];
			}
			else c[i][j]= c[i-1][j];
		}
	}
}

//x[]����洢������,0��ʾ��װ�뱳����1��ʾװ�뱳��
void Traceback(int w[],int n,int C,int x[])
{
	for(int k=n;k>=2;k--)
	{
		if(c[k][C]==c[k-1][C])
			x[k]=0;
		else
		{
			x[k]=1;
			C=C-w[k];
		}
	}
	x[1]=c[1][C]?1:0;
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
	Knapsack(w,v,n,C);
	Traceback(w,n,C,x);
	cout<<"���Ž�����Ϊ�� ";
	for(int i=1;i<=n;i++)
		cout<<x[i]<<" ";
	cout<<endl<<"����ֵΪ�� "<<c[n][C]<<endl;
	return 0;
}