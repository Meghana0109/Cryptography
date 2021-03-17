#include <iostream>
using namespace std;
int main()
{
	int xPlaintext; 
	cout << "Enter the plaintext:" << endl;
	cin >> xPlaintext;    //Taking the plaintext as input
	int n=0,p;            //Introducing n to calculate the number of bits in plaintext 
	p=xPlaintext;         //p to locally store plaintext
	while(p!=0)
	{
		n=n+1;       //Increasing n by 1 with each digit/bit in the plaintext
		p=p/10;      
	}
	int x[n],j;         //introducing an array which stores 0/1 bits of the plaintext individually
	p=xPlaintext;
	for(j=0;j<n;j++)
	{
		x[n-1-j]=p%10;   //storing digits of the plaintext one by one from the last into the array as the input plaintext is already a binary vector
		p=p/10; 
	}
	int b[n];               //Introducing an array of size same as no of bits in plaintext to store object weights
	cout << "Enter the object weights: " << endl;
	for(j=0;j<n;j++)
	{
		cout << "b" << j+1 << "= " ;
		cin >> b[j];
	}
	int c=0;                            //introducing the sum variable which calculates the sum            
	for(j=0;j<n;j++)
	{
		c=c+b[j]*x[j];                 //updating the value of sum with the result of object weight multiplied by corresponding plaintext bit 
	}                                      //Formula: S=x*b=Σ xi*bi
	cout << "Ciphertext is : " << c << endl;
	return 0;
}
