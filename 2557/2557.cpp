/**************************************************************
	File name: 2557.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 7/15/2018, 12:04:01 PM
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define N 510
int score[11],n,m,k,opt,a[N][N],t[N][N],r[N][N];
int main(int _,char **file)
{
	FILE *in=fopen(file[1],"r"),*out=fopen(file[2],"w"),*ans=fopen(file[3],"r");
	fr(i,1,10)fscanf(ans,"%d",score+i);
	fscanf(in,"%d%d%d%d",&n,&m,&k,&opt);
	fr(i,1,m)
	{
		int u,v;
		fscanf(in,"%d%d",&u,&v);
		a[u][v]=1;
	}
	return 0;
}