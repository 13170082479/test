
#include<stdafx.h>
#include<iostream>
#include<ctime>
using namespace std;
#define N 100
double a[N];

//�������������±꣬�����Ӧ������Ԫ����Ϊ�ȽϹؼ���
int random(int m, int n)
{
	//��ϵͳʱ����Ϊ�������
	srand((unsigned)time(NULL));
	return m + rand() % (n - m + 1);
}
//һ�˿�������
int qartition(double *a, int begin, int end)
{
	double x = a[end];
	int i = begin - 1, j = begin;
	while (j < end)
	{
		if (a[j] <= x)
		{
			i++;
			double temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
		j++;
	}
	double temp = a[end];
	a[end] = a[i + 1];
	a[i + 1] = temp;
	return i + 1;
}

//һ���������������

int random_qartition(double *a, int begin, int end)
{
	int k = random(begin, end);
	//cout<<"random k="<<k<<endl;
	double temp = a[k];
	a[k] = a[end];
	a[end] = temp;
	return qartition(a, begin, end);
}
//�����ѡ���iСԪ��
double random_K_select(double *a, int begin, int end, int i)
{
	if (begin > end)
		return 65535;
	else if (begin == end)
		return a[begin];
	else
	{
		int k = random_qartition(a, begin, end);
		if (i - 1 == k)
			return a[k];
		else if (i - 1 < k)
			return random_K_select(a, begin, k - 1, i);
		else return random_K_select(a, k + 1, end, i);
	}
}


int main()
{
	memset(a, 0.0, sizeof(a));
	int n;
	cout << "��������ЩԪ�صĸ�����" << endl;
	cin >> n;
	cout << "��������ЩԪ�أ�" << endl;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "��������Ҫ��ѯ�ĵ�KСԪ�ص�Kֵ(��-1����)��" << endl;
	int k;
	//double key;
	cin >> k;
	while (k != -1)
	{
		if (k > n)
		{
			cout << "û�����Ԫ�أ���Ϊ�����kֵ���ܴ���n��" << n << "������������kֵ" << endl;
			cin >> k;
			continue;
		}
		//key = random_K_select(a,0,n-1,k);
		cout << "�� " << k << " СԪ���ǣ�" << endl;
		cout << random_K_select(a, 0, n - 1, k) << endl;
		cin >> k;
	}
	system("pause");
	return 0;
}


