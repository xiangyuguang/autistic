#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[8] = {2,3,8,1,6,4,7,9};
int b[8] = {8,65,4,2,8,7,9,1};
int c[8] = {8,9,6,7,5,4,3,2};
int t[10] = {0};//Ͱ��ʹ������ 

void bubblesort()//��ԣ�� 
{
	int t;
	for (int i=0;i<8-1;i++)
	{
		for (int j=0;j<8-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t = a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
} 

void quicksort(int low,int high)//���� 
{
	int l = low;
	int h = high;
	int t;
	int mid = b[(low+high)/2]; //ȡ�м��� 
	while(l<=h)
	{
		while(b[l]<mid)	// 
		l++;
		while(b[h]>mid)
		h--;
		if(l<=h)
		{
			t = b[l];
			b[l] = b[h];
			b[h] = t;
			l++;
			h--;
		}	
	}
	if(l<high)
	quicksort(l,high);//��� 
	if(low<h)
	quicksort(low,h);//�ұ� 
	
}

void print(int q[])
{
	for (int i=0;i<8;i++)
	{
		cout << q[i] << " ";
	}
	cout << endl; 
}

//int c[8] = {8,9,6,7,5,4,3,2};
void bucketsort()//����� 
{
	for (int i=0;i<8;i++)
	{
		t[c[i]]++;
	}
	for (int i=0;i<10;i++)
	{
		if(t[i])
		cout << i << " ";
	}
} 

int main()
{
	memset(t,0,sizeof(t));
	//ð������a���� 
	bubblesort();
	print(a);
	//��������b���� 
	quicksort(0,8-1);
	print(b);
	//Ͱ������c����
	bucketsort();
//	print(c);
	
	return 0;
} 
