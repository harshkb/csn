#include <bits/stdc++.h>
#include <iomanip>
#include <fstream>
using namespace std;


string poly;
string methodname(string a)
{
	string ans =""; 
	for(int i=0;i<a.length();i++ )
	{
	
		char g=abs(a[i]-poly[i])+'0';
		ans=ans+g;
	}
	return ans;

}

int main() {
   
    string datan,poly;
cin>>datan>>poly;
    	  int sum=0;
    
    if(datan[0]=='0')
    {
    	 datan.replace(0,1,"1");
    	
    }
    else
    {
    	 datan.replace(0,1,"0");
    	
    }

    
    
    
      int i=0;
      while(i<datan.length()-poly.length()+1)
    {
    	if(datan[i]=='0')
    	{
    		i++;
    	}
    	else
    	{
    	string wef =methodname(datan.substr(i,poly.length()-1));
    	datan.replace(i,poly.length()-1,wef);
    	i++;
        }
    }

    // cout<<datan<<endl;
    bool flag = true;
    for(int i=0;i<datan.length();i++)
    	{if(datan[i]!='0'){flag = false; break;}
    }
    if(flag ==1)
    	cout<<"true"<<endl;
    else
    	cout<<"false"<<endl;

}

