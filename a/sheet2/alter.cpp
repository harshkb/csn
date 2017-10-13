#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main( int argc , char *argv[]) {
	int temp;
	string data, poly;
	cin >> data >> poly;
	int a =atoi(argv[1]);
	temp=(int)data[a-1]-'0';
	temp=1-temp;
	data[a-1]=char(temp+'0');
	cout<<data<<endl<<poly<<endl;
	return 0;
}
	
	
