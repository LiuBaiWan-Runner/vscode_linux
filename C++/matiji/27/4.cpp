#include<iostream>
#include<cmath>
#define mod 0x1f1f1f1f;
using namespace std;


int cal(int **det,int n)//det-行列式，n:行列式的阶数
{
	int detVal = 0;//行列式的值
	
	if(n == 1)//递归终止条件 
	return det[0][0]; 
	
	int **tempdet = new int *[n-1];//用来存储余相应的余子式
	 for(int i=0;i<n-1;i++)
	  tempdet[i] = new int[n-1];
	for(int i=0;i<n;i++)//第一重循环，行列式按第一行展开 
	{
		for(int j=0;j<n-1;j++)
		for(int k=0;k<n-1;k++)
		{
			if(k <i)
			tempdet[j][k]=det[j+1][k] ;
			else
			tempdet[j][k]=det[j+1][k+1];
		}
		detVal += det[0][i] * pow(-1.0,i) * cal(tempdet,n-1);
	
	 }
	 detVal += mod;
	 detVal %= mod;
	 return detVal;
} 
int main()
{
	int m, n;
    cin >> m;//输入矩阵的个数
    for(int i = 0; i < m; i++){
		cin >> n;//输入矩阵阶数
		int **det = new int *[n];//需要动态内存 
		for(int i=0;i<n;i++)
       		det[i] = new int[n];
		
		for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			cin >> det[i][j];
/*
		for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			cout << det[i][j] << ' ';
			}
			cout << endl;
		}
*/
		cout << cal(det,n) << endl;
	}
	
}
