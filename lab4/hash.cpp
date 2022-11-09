//开放寻址法
//散列函数包括线性探测、二次探测、双重探测
#include<iostream>
using namespace std;
//除法散列法
int h1(int k,int m)
{
		return k%m; 
}
//乘法散列法
int h2(int k,int m,float A)
{
		float fnum=(float)k;
		float re=((fnum*A)-(int)(fnum*A))*m;
		return (int)re;
}
//全域散列法,p为质数
int h3(int k,int p,int m)
{
	int a,b;
	a=11;
	b=13;
	return ((a*k+b)%p)%m;
}
//线性探查
int LinerProbing(int k,int m,int i)
{
	return (h1(k,m)+i)%m;
}
//二次探查
int QuadraticProbing(int k,int m,int i)
{
	int c1=17,c2=67;
 
	return (h1(k,m)+c1*i+c2*i*i)%m;
}
//双重探查
int DoublefunProbing(int k,int m,int i)
{
	return (h3(k,17,m)+i*h1(k,m))%m;
}
//插入值为k的元素到具有m个槽的T中
int Insert(int *T,int k,int m)
{
	int i=1,j;
	while(1)
	{
		//利用双重探查得出插入位置
		j=DoublefunProbing(k,m,i);
		if(i==m+1)
		{
			break;
		}
		//T[j]==-1表示该槽为空
		if(T[j]==-1)
		{
			T[j]=k;
			return j;
		}
		i++;
	}
	return -1;
}
//删除值为k的元素在具有m个槽的T中
bool Delete(int *T,int k,int m)
{
	int i=1,j;
	while(1)
	{
		j=DoublefunProbing(k,m,i);
		if(i==m+1)
		{
			return 0;
		}
		if(T[j]==-1)
		{
			return 0;
		}
		if(T[j]==k)
		{
			T[j]=-1;
			return 1;
		}
		i++;
	}
}
//搜索值为k的元素在具有m个槽的T中
int Search(int *T,int k,int m)
{
	int i=1,j;
	while(1)
	{
		j=DoublefunProbing(k,m,i);
		if(i==m+1)
		{
			return -1;
		}
		if(T[j]==-1)
		{
			return -1;
		}
		if(T[j]==k)
		{
			return j;
		}
		i++;
	}
}
int main()
{
	int a[10]={4,8,2,6,41,21,53,496,3216,48};
	int T[101]={0};
	int i;
	for(i=0;i<101;i++)
	{
		T[i]=-1;
	}
	for(i=0;i<10;i++)
	{
		Insert(T,a[i],100);
	}
	for(i=1;i<=100;i++)
	{
		if(T[i]!=-1)
		{
			cout<<T[i]<<" ";
		}
	}
	cout<<endl;
	cout<<Search(T,2,100)<<endl;
	Delete(T,2,100);
	cout<<Search(T,2,100)<<endl;
}

// ————————————————
// 版权声明：本文为CSDN博主「liuzhanchen1987」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/liuzhanchen1987/article/details/7799257