#include <iostream>
#include <string>
using namespace std;
int main()
{
	string p,k,c;
	cout << "Enter the plaintext:" << endl;
	getline(cin,p);
	cout << "Enter the key:" << endl;
	getline(cin,k);
	int p_size,k_size;
	p_size=p.length();
	k_size=k.length();
	int p1[p_size],k1[k_size],i;
	for(i=0;i<p_size;i++)
	{
		p1[i]=int(p[i])-97;
	}
	for(i=0;i<k_size;i++)
	{
		k1[i]=int(k[i])-97;
	}
	int c1[p_size];
	for(i=0;i<p_size;i++)
	{
		c1[i]=(p1[i]+k1[i%k_size])%26;
		c[i]=char(c1[i]+65);
	}
	for(i=0;i<p_size;i++)
	{
		cout<< c[i];
	}
	cout << endl;
	return 0;
}
