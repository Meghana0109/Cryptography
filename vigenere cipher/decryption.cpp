#include <iostream>
#include <string>
using namespace std;
int main()
{
	string p,k,c;
	cout << "Enter the ciphertext: " << endl;
	getline(cin,c);
	cout << "Enter the keyword: " << endl;
	getline(cin,k);
	int c_size,k_size;
	c_size = c.length();
	k_size = k.length();
	int c1[c_size],k1[k_size],i;
	for(i=0;i<c_size;i++)
		c1[i] = int(c[i])-65;
	for(i=0;i<k_size;i++)
		k1[i] = int(k[i]) - 97;
	int p1[c_size];
	for(i=0;i<c_size;i++)
	{
		p1[i] = (26+c1[i]-k1[i%k_size])%26;
		p[i] = char(p1[i]+97);
	}	
	cout << "The plaintext is:" ;
	for(i=0;i<c_size;i++)
	{
		cout << p[i];
	}
	cout << endl;

}
