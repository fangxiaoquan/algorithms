//0-1�������⶯̬�滮
#include<iostream>
using namespace std;

//һλ����dp[]��ʾ״̬ת�Ʒ���
int Knapsack(int dp[],int w[],int v[],int n,int C)
{
	for(int i=0;i<=C;i++)
		dp[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=C;j>=w[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	return dp[C];
}

int main()
{
	int dp[20],w[11],v[11]; //�����Ʒ����Ϊ10
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
	cout<<"װ�뱳��������ֵΪ�� "<<Knapsack(dp,w,v,n,C)<<endl;
	return 0;
}