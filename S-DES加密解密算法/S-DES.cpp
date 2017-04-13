#include<iostream>
using namespace std;
int plaintext[8]; //����
int ciphertext[8]; //����
int key[10]; //��ʼ��10-bit��Կ
int k1[8], k2[8]; //���ɵ�����Կ
int s0[4][4] = {1,0,3,2, 3,2,1,0, 0,2,1,3, 3,1,3,2}; //s0����
int s1[4][4] = {0,1,2,3, 2,0,1,3, 3,0,1,0, 2,1,0,3}; //s1����
void shift(int *p, int bits); //ѭ������
void create_subkey(int *key); //����Կ����
void fk(int* input, int* k, int* output); //���Ϻ���fk
void encryption(int* m); //���ܺ���
void decryption(int* cipher); //���ܺ���

void shift(int *p, int bits)
{
	int temp[5];
	for(int i=0; i<5; i++)
	{
		temp[i] = p[(i+bits)%5];
	}
	for(int j=0; j<5; j++)
	{
		p[j] = temp[j];
	}
}
void create_subkey(int *key)
{
	int p10[10];
	int LK[5], RK[5];
	//p10�û�
	p10[0]=key[2];p10[1]=key[4];p10[2]=key[1];p10[3]=key[6];p10[4]=key[3];
	p10[5]=key[9];p10[6]=key[0];p10[7]=key[8];p10[8]=key[7];p10[9]=key[5];
	for(int i=0; i<5; i++)
	{
		LK[i] = p10[i];
		RK[i] = p10[i+5];
	}
	//ѭ����λ1bit
	shift(LK, 1);
	shift(RK, 1);
	//��������Կk1
	k1[0]=RK[0];k1[1]=LK[2];k1[2]=RK[1];k1[3]=LK[3];
	k1[4]=RK[2];k1[5]=LK[4];k1[6]=RK[4];k1[7]=RK[3];
	//ѭ����λ2bit
	shift(LK, 2);
	shift(RK, 2);
	//��������Կk2
	k2[0]=RK[0];k2[1]=LK[2];k2[2]=RK[1];k2[3]=LK[3];
	k2[4]=RK[2];k2[5]=LK[4];k2[6]=RK[4];k2[7]=RK[3];
	cout<<"���ɵ�����Կ�ֱ�Ϊ��"<<endl;
	cout<<"k1=";
	for(int i=0; i<8; i++)
	{
		cout<<k1[i];
	}
	cout<<endl<<"k2=";
	for(int i=0; i<8; i++)
	{
		cout<<k2[i];
	}
	cout<<endl;
}
void fk(int* input, int* k, int* output)
{
	int L[4], R[4];
	int L1[4], R1[8];
	int line0, line1, row0, row1;
	for(int i=0; i<4; i++)
	{
		L[i] = input[i];
		R[i] = input[i+4];
	}
	//��R��E/P�û�
	R1[0]=R[3];R1[1]=R[0];R1[2]=R[1];R1[3]=R[2];
	R1[4]=R[1];R1[5]=R[2];R1[6]=R[3];R1[7]=R[0];
	//������Կ���
	for(int i=0; i<8; i++)
	{
		R1[i] = (R1[i]+k[i])%2;
	}
	//S��������
	row0 = R1[0]*2 + R1[3]*1;
	line0 = R1[1]*2 + R1[2]*1;
	row1 = R1[4]*2 + R1[7]*1;
	line1 = R1[5]*2 + R1[6]*1;
	R1[0] = s0[row0][line0]/2;
	R1[1] = s0[row0][line0]%2;
	R1[2] = s1[row1][line1]/2;
	R1[3] = s1[row1][line1]%2;
	//p4�û�
	int p4[4];
	p4[0] = R1[1];
	p4[1] = R1[3];
	p4[2] = R1[0];
	p4[3] = R1[2];
	for(int i=0; i<4; i++)
	{
		R1[i] = p4[i];
	}
	for(int i=0; i<4; i++)
	{
		L1[i] = (L[i]+R1[i])%2;
	}
	//�õ����
	for(int i=0; i<4; i++)
	{
		output[i] = L1[i];
		output[i+4] = R[i];
	}
}
void encryption(int *m){
	int m1[8];
	int output1[8];
	int input2[8];
	int output2[8];
	int result1[8];
	//IP�û�
	m1[0]=m[1];m1[1]=m[5];m1[2]=m[2];m1[3]=m[0];
	m1[4]=m[3];m1[5]=m[7];m1[6]=m[4];m1[7]=m[6];
	//fk1��������
	fk(m1,k1,output1);
	//SW����
	for(int i=0; i<8; i++)
	{
		input2[i] = output1[(i+4)%8];
	}
	//fk2��������
	fk(input2,k2,output2);
	//IP���û�
	result1[0]=output2[3];result1[1]=output2[0];
	result1[2]=output2[2];result1[3]=output2[4];
	result1[4]=output2[6];result1[5]=output2[1];
	result1[6]=output2[7];result1[7]=output2[5];

	cout<<"���ܺ�����Ϊ��"<<endl;
	for(int i=0; i<8; i++)
		cout<<result1[i];
	cout<<endl;
}

void decryption(int *cipher){
	int c1[8];
	int output1[8];
	int input2[8];
	int output2[8];
	int result2[8];
	//IP�û�
	c1[0]=cipher[1];c1[1]=cipher[5];
	c1[2]=cipher[2];c1[3]=cipher[0];
	c1[4]=cipher[3];c1[5]=cipher[7];
	c1[6]=cipher[4];c1[7]=cipher[6];
	//fk2��������
	fk(c1,k2,output1);
	//SW����
	for(int i=0;i<8;i++)
	{
		input2[i] = output1[(i+4)%8];
	}
	//fk1����
	fk(input2,k1,output2);
	//IP���û�
	result2[0]=output2[3];result2[1]=output2[0];
	result2[2]=output2[2];result2[3]=output2[4];
	result2[4]=output2[6];result2[5]=output2[1];
	result2[6]=output2[7];result2[7]=output2[5];

	cout<<"���ܺ�����Ϊ��"<<endl;
	for(int i=0;i<8;i++)
		cout<<result2[i];
	cout<<endl;
}
int main()
{
	bool select = true;
	while(select)
	{
		cout<<"****************��S-DES�㷨��*******************"<<endl;
		cout<<"ѡ��-> ��1������  ��2������\n->";
		char op;
		char ch;
		char* data = new char[11];
		cin>>op;
		switch (op)
		{
		case '1':
			cout<<"����10-bit����Կ->";
			cin>>data;
			for(int i=0; i<10; i++)
			{
				key[i] = data[i]-48;
			}
			cout<<"����8-bit������->";
			cin>>data;
			for(int i=0; i<8; i++)
			{
				plaintext[i] = data[i]-48;
			}
			create_subkey(key);
			encryption(plaintext);
			cout<<"�˳�����Y/N��";
			cin>>ch;
			if(ch == 'Y' || ch == 'y')
				select = false;
			break;
		case '2':
			cout<<"����10-bit����Կ->";
			cin>>data;
			for(int i=0; i<10; i++)
			{
				key[i] = data[i]-48;	
			}
			cout<<"����8-bit������->";
			cin>>data;
			for(int i=0; i<8; i++)
			{
				ciphertext[i] = data[i]-48;		
			}
			create_subkey(key);
			decryption(ciphertext);
			cout<<"�˳�����Y/N��";
			cin>>ch;
			if(ch == 'Y' || ch == 'y')
				select = false;
			break;
		default:
			cout<<"�˳�����Y/N��";
			cin>>ch;
			if(ch == 'Y' || ch == 'y')
				select = false;
			break;
		}
	}
}