#include<iostream>
#include<cmath>
using namespace std;
//�жϵ�t���ʺ�ǰ��λ���Ƿ���t֮ǰ�Ļʺ�λ�ó�ͻ
bool Placed(int x[],int t)
{
	for(int i=1;i<t;i++)
		if((x[i] == x[t])||abs(t-i) == abs(x[t]-x[i]))
		{ return false;}
	return true;
}
//n�ʺ�����ݹ��㷨
void nQueenRecursion(int x[],int t,int n)
{
	if(t>n)
	{
		for(int i=1;i<=n;i++)
			cout<<x[i]<<" ";
		cout<<endl;
	}
	else{
		for(int i=1;i<=n;i++)
		{
			x[t]=i;
			if(Placed(x,t))
			{
				nQueenRecursion(x,t+1,n);
			}
		}
	}
}
//n�ʺ���������㷨
void nQueenIterationn(int x[],int n)
{
	int t=1;
	for(int i=1;i<=n;i++)
		x[i]=0;
	while(t>=1)
	{
		while(x[t]<n)
		{
			x[t]=x[t]+1;
			if(Placed(x,t))
			{
				t=t+1;
				if(t>n)
				{
					for(int i=1;i<=n;i++)
						cout<<x[i]<<" ";
					cout<<endl;
					t=t-1;
				}
			}
		}
		x[t]=0;
		t=t-1;
	}
}

int main()
{
	const int MAX_NUM=11;
	int x[MAX_NUM];
	int n;
	cout<<"������n�ʺ������nֵ��n<=10����";
	cin>>n;
	cout<<"(1)�ݹ������⣺"<<endl;
	nQueenRecursion(x,1,n);
	cout<<"(2)����������⣺"<<endl;
	nQueenIterationn(x,n);
}