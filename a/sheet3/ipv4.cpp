#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<string>
#include<stdlib.h>
#include<unistd.h>
using namespace std;


char gethex(int a)
{
	if(a>=0&&a<=9) return char((int)('0')+(int)(a));
	return char((int)('a')+(int)(a-10));
}

string v4to6(string v4)
{



	string v6,s[4];
	int a[4]={0,0,0,0};
	//for(int i=0;i<4;i++)
	for(int i=0,j=0;i<v4.size();i++)
	{
		
		if(v4[i]!='.')
			a[j]=a[j]*10+((int)v4[i]-'0');
		else
			j++;
	}
	
	for(int i=0;i<4;i++)
	{
		int x=a[i]/16;
		int y=a[i]%16;
		s[i]= s[i]+gethex(x)+gethex(y);
		//cout<<gethex(x)<<endl;
	}
	v6=s[0]+s[1]+'.'+s[2]+s[3];
	return v6;
}

int main()
{
	

	string v4,v6;
	cin>>v4;
	v6=v4to6(v4);
	cout<<v6<<endl;
	return 0;
}

