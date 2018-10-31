#include<string>
#include"combo.h"
using namespace std;
char a,b,c,d;
string guess_sequence(int N)
{
	string s;
	if(press("AB"))
	{
		if(press("A"))
		{
			a='A';b='B';c='X',d='Y';
		}
		else
		{
			a='B';b='A';c='X',d='Y';
		}
	}
	else
	{
		if(press("X"))
		{
			a='X';b='B';c='A',d='Y';
		}
		else
		{
			a='Y';b='A';c='B',d='X';
		}
	}
	s=a;
	if(N==1)return s;
	for(int i=2;i<N;i++)
	{
		int k=press(s+b+b+s+b+c+s+b+d+s+c);
		if(k==i+1)s+=b;
		else if(k==i)s+=c;
		else s+=d;
	}
	if(press(s+b)==N)s+=b;
	else if(press(s+c)==N)s+=c;
	else s+=d;
	return s;
}