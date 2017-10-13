#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main(){
   
   int transport_size=40, ip_header_size=20, mtu=40;
   string data, ip_header;	   
   cin>>ip_header>>data;
   int count=0;
   int data_byte=min(transport_size,mtu-ip_header_size);
   int offset=0; 
   int pre_off=0;
   int pp_off=0;
   int pre_db = 0;
   int rem=transport_size;
   int flag=1; 

   //cout<<ip_header<<data;
   while(rem>0)
   {
   count++;
   offset=(pre_off+data_byte/8);
  
   
   data_byte=min(rem,mtu-ip_header_size);
   rem=max(0, rem-(mtu-ip_header_size));
   if(!rem)
     flag=0;
   cout<<count<<" "<<"Total Bytes:"<<data_byte+ip_header_size<<" Header Bytes: "<<ip_header_size<<" Data Bytes:"<< data_byte<<" Flag: "<< flag<<" Offset:"<<pre_off<<"\n";


    ip_header[12] = flag + '0';
    stringstream ss;
    ss.str("");
    ss << hex << pre_off;
    ip_header[15] = ss.str()[0];

    cout<<ip_header<<endl;
    //cout<<pre_off<<endl<<pre_db<<endl<<offset<<endl;
    for(int i=2*(pp_off + pre_db); i<2*(pp_off + pre_db + data_byte); i++)
	cout<<data[i];

    cout<<endl;
    pp_off = pre_off;
    pre_off=offset;
    pre_db = data_byte;
    }
    return 0;
}

