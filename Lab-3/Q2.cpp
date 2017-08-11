/*input
192.168.99.1
*/

#include <iostream>
using namespace std;

string convert(string temp)
{
int val=0;
int mul=1;
int i=temp.length()-1;
	while(i>=0)
	{
		val=val+((int)(temp[i]-'0')*mul); 
		i--;
		mul=mul*10;
	}
	string ans="";
	int te =val/16;
	int tr=val%16;
	if(te>9)
	{
		ans = ans+(char)(te+55);
	}
	else
	{
		ans =ans+ (char)((int)('0')+te);
	}

	if(tr>9)
	{
		ans = ans+(char)(tr+55);
	}
	else
	{
		ans =ans+(char)((int)('0')+tr);
	}

	return ans;
}

int main()
{
	string ip;
	cin>>ip;
	int i=0;
	string a="";
	string con="";
	int count =0;
	while(i<ip.length())
	{
		if(ip[i]=='.')
		{

			string b =convert(a);
			a="";

			con=con+b;
			count++;
			if(count ==2)
			{
				con=con+':';
			}
		}
		else
		a=a+ip[i];
	i++;
	}
	con=con+convert(a);

	cout<<con<<endl;
}