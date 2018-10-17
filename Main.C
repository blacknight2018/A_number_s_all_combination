#include <STDIO.H>
//思路:
/*
1.吧目标数字分解成单个数字 通过排列组合的思想组合出所有可能
2.将排出来的数字 和 原来的数字作差 
*/
void swap(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void sort(int *p,int num)
{
	int i,j;
	int m=0;
    while(m!=num-1)
	{
		m=0;
		for (i=1;i<=num-1;i++)
		{
			if(p[i-1]>p[i])
			{
				swap(&p[i-1],&p[i]);
			}
			else
			{
				m++;
			}
		}
	}
}
//获取一个数有几位
int getNum(int m)
{
   int n =0;
   while(m!=0)
   {
	   m/=10;
	   n++;
   }
   return n;
}
void div(int *p,int m,int number)
{
	int k = 0;
	while(m--)
	{
		p[k++] = number%10;
		number/=10;
	}
}
int spow(int x,int y)
{
	int k=1;
	while(y--)
	{
		k=k*x;
	}
	return k;
}
//深度优先搜索？
int n_count = 0;
int *result;

int digui(int *p,int n,int max,int step)
{

	int k = 0;
	if(n==max+1)
	{
	 
	//	printf("%d\n",step);
		result[n_count++] = step;
		return 0;
	}

	for (k=1;k<=max;k++)
	{
		if(p[k-1]!=-1)
		{
			int m = p[k-1];
			//printf("%d",p[k-1]);
			p[k-1] = -1;
			digui(p,n+1,max, (spow(10,n-1)*m )+step);//1*10^0 + 2*10^1+3*10^2 类推
			p[k-1] = m;
		}
		
	}
}
int getN(int num)//求一个数的N阶
{
	int k=1;
	int j = 1;
	for (;k<=num;k++)
	{
		j*=k;
	}
	return j;
}
int main()
{
	//一个数字拆开后组合的所有可能数等于 位数的N阶
	int i[40] = {0};
	int num = 12345;
	int k;
	int ncount = 0;
	int less=0;
	int mix=0x7FFFFFFF;
	int mixindex=0;
	ncount = getNum(num);//统计所有组合的可能
	//动态生成一个数组保存结果
	
    result =(int *) malloc(sizeof(int) * getN(ncount));
	 
	//拆开后进行排列组合
    div(i,getNum(num),num);
	sort(i,ncount);
    digui(i,1,ncount,0);
	printf("共有%d种可能\n",n_count);

	for(k=0;k<n_count;k++)
	{
		
		//一个个判断与目标的差 取得最小值
		less = result[k] - num;
		printf("第%d个=%d与目标差距=%d\n",k+1,result[k],less);
		if(less<mix && result[k]!=num)
		{
			mix=less;
			mixindex = k+1;
		}
 
	}
	printf("第%d个与目标%d的差距最小\n",mixindex,num);
	return 0;
}
/*
完结 

用的是最笨的办法

end at 2018-10-18
*/
