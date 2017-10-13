#include <iostream>
using namespace std;
 
int val(char a){
	if(a == 'A'){return 10;}
	if(a == 'B'){return 11;}
	if(a == 'C'){return 12;}
	if(a == 'D'){return 13;}
	if(a == 'E'){return 14;}
	if(a == 'F'){return 15;}
}
 
int main() {
 
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++){cin>>s[i];}
	int h;cin>>h;
	long sum = 0,checkSum = 0;
	int m = 1;
	for(int i=0;i<n;i++){
		int tempSum = 0;
			m = 1;
			for(int j=3;j>=0;j--){
				if(s[i][j] == 'A' || s[i][j] == 'B' || s[i][j] == 'C' || s[i][j] == 'D' || s[i][j] == 'E' || s[i][j] == 'F'){
					int x = val(s[i][j]);
					tempSum += x*m;
				}else{
					int x = int(s[i][j]) - 48;
					tempSum += x*m;
				}
				m *= 16;
			}
			if(h-1!=i){sum += tempSum;}
			else{checkSum = tempSum;}
	}
	int Sum = sum;
	cout<<"total sum "<<sum<<endl;
	cout<<"checkSum val "<<checkSum<<endl;
	cout<<"binary representation of sum "<<endl;
	int g = sum;
	while(g!=0){
		cout<<g%2;
		g = g/2;
	}cout<<endl;
	m = 1;
	long dup = sum,rem,count = 0;
	while(dup != 0){
		rem = dup%16;
		dup = dup/16;
		m *= 16;
		count++;
	}
	m = m/16;
	sum = sum - rem*m + rem;
	cout<<"sum after "<<sum<<endl;
	cout<<"binary representation of sum after adding most significant bits"<<endl;
	g = sum;
	while(g!=0){
		cout<<g%2;
		g = g/2;
	}cout<<endl;
 
	dup = sum;rem;m = 1;
	int oneC = 0;
	count = 0;
	while(dup != 0){
		rem = dup%2;
		dup = dup/2;
		int x = 1^rem;
		oneC += m*x;
		m *= 2;
		count++;
	}
	while(count%4!=0){
		oneC += m*1;
		m *= 2;
		count++;
	}
 
	cout<<"1's complement sum "<<oneC<<endl;
	//if(oneC == checkSum){cout<<"checkSum calculated"<<endl;}
	// to verify..
	Sum = Sum + checkSum;
 
	m = 1;
	dup = Sum;
	count = 0;
	while(dup != 0){
		rem = dup%16;
		dup = dup/16;
		m *= 16;
		count++;
	}
	m = m/16;
	Sum = Sum - rem*m + rem;
	cout<<Sum<<endl;
	if(Sum == 65535){
		cout<<"No Error"<<endl;
	}else cout<<"Error"<<endl;
 
	return 0;
}