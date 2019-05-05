#include<iostream>
using namespace std;
class Complex
{
	public:
		double cz_rzecz;
		double cz_uroj;
		Complex(double rzecz, double uroj)
		{
			cz_rzecz=rzecz;
			cz_uroj=uroj;
		}
	friend Complex  operator+(const Complex & c1, const Complex & c2);
	friend ostream & operator <<( ostream & out, Complex & c3 );
	friend Complex  operator-(const Complex & c1,const Complex & c2);
};
Complex  operator+(const Complex & c1,const Complex & c2)
	{
		return Complex(c1.cz_rzecz+c2.cz_rzecz,c1.cz_uroj+c2.cz_uroj);
	}
Complex  operator-(const Complex & c1,const Complex & c2)
	{
		return Complex(c1.cz_rzecz-c2.cz_rzecz,c1.cz_uroj-c2.cz_uroj);
	}
Complex  operator*(const Complex & c1,const Complex & c2)
	{
		return Complex(c1.cz_rzecz*c2.cz_rzecz - c1.cz_uroj*c2.cz_uroj,c1.cz_uroj*c2.cz_rzecz+c2.cz_uroj*c1.cz_rzecz);
	}
Complex operator/(const Complex & c1, const Complex & c2 )
	{
		return Complex((c1.cz_rzecz*c2.cz_rzecz - c1.cz_uroj*c2.cz_uroj*(-1))/((c2.cz_rzecz * c2.cz_rzecz)+(c2.cz_uroj * c2.cz_uroj)),(c1.cz_uroj*c2.cz_rzecz-c2.cz_uroj*c1.cz_rzecz)/((c2.cz_rzecz * c2.cz_rzecz)+(c2.cz_uroj * c2.cz_uroj)));
	}
ostream & operator <<( ostream & out, Complex & c3 )
{
	if(c3.cz_uroj <0)
	{
		out << c3.cz_rzecz << "" <<c3.cz_uroj <<"i" << endl;
    	return out;
    }
    else
    {
    	out << c3.cz_rzecz << "+" <<c3.cz_uroj <<"i" << endl;
    	return out;
	}
}
int main(void)
{
	Complex c3 = c1+c2;
	Complex c4 = c1-c2;
	Complex c5 = c1*c2;
	Complex c6 = c1/c2;
	cout<<c3;
	cout<<c4;
	cout<<c5;
	cout<<c6;
}

