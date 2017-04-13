#include<iostream>
using namespace std;
#define NUM 20
int L[NUM][NUM]; //��ά����L��¼����������г���
int b[NUM][NUM]; //��ά����b[i][j]��¼L[i][j]������һ��������Ľ�õ��ģ����ڹ���LCS
void LCSLength(int m,int n,const char x[],const char y[])
{
	int i,j;
	for(i=0;i<=m;i++) L[i][0]=0;
	for(j=0;j<=n;j++) L[0][j]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(x[i]==y[j])
			{
				L[i][j]=L[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(L[i-1][j]>=L[i][j-1])
			{
				L[i][j]=L[i-1][j];
				b[i][j]=2;
			}
			else
			{
				L[i][j]=L[i][j-1];
				b[i][j]=3;
			}
		}
}
void LCS(int i,int j,char x[])
{
	if(i==0||j==0)
		return;
	if(b[i][j]==1)
	{
		LCS(i-1,j-1,x);
		cout<<x[i]<<" ";
	}
	else if(b[i][j]==2)
		LCS(i-1,j,x);
	else 
		LCS(i,j-1,x);
}
int main()
{
	const int X_LENGTH = 7; //�ַ���X�ĳ���
	const int Y_LENGTH = 6; //�ַ���Y�ĳ���
	char x[]={'0','A','B','C','B','D','A','B'}; //ע���ַ������±�1��ʼ
	char y[]={'0','B','D','C','A','B','A'};
	cout<<"�ַ���XΪ:"<<endl;
	for(int i=1;i<=X_LENGTH;i++)
		cout<<x[i]<<" ";
	cout<<"\n�ַ���YΪ:"<<endl;
	for(int i=1;i<=Y_LENGTH;i++)
		cout<<y[i]<<" ";
	cout<<"\n�����������Ϊ:"<<endl;
	LCSLength(7,6,x,y);
	LCS(7,6,x);
	cout<<endl;
	return 0;
}
