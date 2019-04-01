/**************************************************************
	File name: 6053.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 4/1/2019, 7:51:32 PM
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(long long i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(long long i=(a),end_##i=(b);i>=end_##i;i--)
long long read()
{
	long long r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const long long N=4000010,mod=1000000007;
long long n,s,v[N],p[N],c,w[N],s0[N],s1[N],i1[N],i2[N],m,t[N];
long long calc(long long a,long long k)
{
	if(a<=1||p[k]>n)
		return 0;
	long long x=a<=s?i1[a]:i2[n/a],r;
	r=((s1[x]-s0[x])-(w[k-1]-(k-1)))+(k==1?2:0);
	r=(r%mod+mod)%mod;
	fr(i,k,m)
		if(p[i]*p[i]<=a)
		{
			for(long long c=1,pc=p[i];pc*p[i]<=a;c++,pc*=p[i])
				r=(r+(p[i]^c)*calc(a/pc,i+1)+(p[i]^(c+1)))%mod;
		}
		else 
			break;
//	printf("%lld %lld %lld\n",a,k,r);
	return r;
}
int main()
{
	n=read();
	s=sqrt(n);
	fr(i,2,s)
	{
		if(!v[i])
		{
			p[++m]=i;
			w[m]=w[m-1]+i;
		}
		fr(j,1,m)
			if(i*p[j]<=s)
			{
				v[i*p[j]]=1;
				if(i%p[j]==0)
					break;
			}
			else
				break;
	}
	for(long long i=1,j;i<=n;i=j+1)
	{
		j=n/i;
		c++;
		t[c]=j;
		s0[c]=(j-1)%mod;
		s1[c]=j%mod*((j+1)%mod)%mod;
		s1[c]=s1[c]%2==0?s1[c]/2:(s1[c]+mod)/2;
		s1[c]=(s1[c]+mod-1)%mod;
		if(j<=s)
			i1[j]=c;
		else
			i2[n/j]=c;
		j=n/j;
	}
	fr(i,1,m)
		fr(j,1,c)
		{
			if(p[i]*p[i]>t[j])
				break;
			long long x=t[j]/p[i]<=s?i1[t[j]/p[i]]:i2[n/(t[j]/p[i])];
			s0[j]=s0[j]-s0[x]+(i-1);
			s0[j]=(s0[j]<0?s0[j]+mod:s0[j]);
			s0[j]=(s0[j]>mod?s0[j]-mod:s0[j]);
			s1[j]=s1[j]-p[i]*((s1[x]-w[i-1])%mod)%mod;
			s1[j]=(s1[j]<0?s1[j]+mod:s1[j]);
		}
//	fr(i,1,c)
//		printf("%lld %lld %lld\n",t[i],s0[i],s1[i]);
	printf("%lld\n",calc(n,1)+1);
	return 0;
}