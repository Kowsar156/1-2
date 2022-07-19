#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<cstdio>

using namespace std;

class StringMath
{
	char *p;
	public:
		StringMath()
		{
			p = new char [1];
			p[0] = '\0';
		}
		
		StringMath(char *s)
		{
			p = new char [strlen(s)];
			p = s;
		}
		
		int get_size()
		{
			return strlen(p);
		}
		
		StringMath operator=(StringMath A)
		{
			p = new char [A.get_size()];
			p = A.p; 
			return *this;
		}
		
		StringMath operator+(StringMath A)
		{
			StringMath temp;
			char *x;
			temp.p = new char [strlen(this->p)>strlen(A.p)? strlen(this->p)+2:strlen(A.p)+2];
			sprintf(temp.p, "%d", atoi(this->p) + atoi(A.p));
			//temp.p = itoa(atoi(this->p) + atoi(A.p), temp.p, 10);
			delete[] x;
			return temp;
		}
		
		StringMath operator+(int n)
		{
			StringMath temp;
			char *x;
			temp.p = new char [strlen(this->p)>n? strlen(this->p)+2:n+2];
			sprintf(temp.p, "%d", atoi(this->p) + n);
			//temp.p = itoa(atoi(this->p) + n, temp.p, 10);
			delete[] x;
			return temp;
		}
		
		friend StringMath operator+(int n, StringMath A)
		{
			StringMath temp;
			char *x;
			temp.p = new char [strlen(A.p)>n? strlen(A.p)+2:n+2];
			sprintf(temp.p, "%d", atoi(A.p) + n);
			//temp.p = itoa(atoi(A.p) + n, temp.p, 10);
			delete[] x;
			return temp;
		}
		
		bool operator>(int n)
		{
			if(atoi(this->p)>n)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		bool operator>(StringMath A)
		{
			if(atoi(this->p)>atoi(A.p))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		StringMath operator++(int unused)
		{
			int x = atoi(p);
			char *n;
			x++;
			sprintf(this->p, "%d", x);
			//this->p = itoa(x, this->p, 10);
			delete[] n;
			return *this;
		}
		
		void printString()
		{
			cout << p << endl;
		}
		
		~StringMath()
		{
			delete[] p;
		}
};

int main()
{
	StringMath S1;
	StringMath S2("123");
	StringMath S3("757");
	StringMath S4("220");
	StringMath S5;
	int n=345;
	S1=S4;
	cout << "Printing S1: " << endl;
	S1.printString();
	cout << "Printing S4: " << endl;
	S4.printString();
	S1=S2+S3+S4;
	cout << "Printing S1: " << endl;
	S1.printString();
	cout << "Printing S2: " << endl;
	S2.printString();
	cout << "Printing S3: " << endl;
	S3.printString();
	cout << "Printing S4: " << endl;
	S4.printString();
	S5=S4=S3;
	cout << "Printing S5: " << endl;
	S5.printString();
	cout << "Printing S4: " << endl;
	S4.printString();
	cout << "Printing S3: " << endl;
	S3.printString();
	if(S3 > n )
	{
		S5= S3+n;
	}
	cout << "Printing S5: " << endl;
	S5.printString();
	S5= n+S2;
	cout << "Printing S5: " << endl;
	S5.printString();
	if(S5 > S2)
	{
		S5++; //Assume prefix increment
	}
	return 0;
}
