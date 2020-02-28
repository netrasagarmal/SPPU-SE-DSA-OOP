//3 LM10
#include<iostream>
using namespace std;
class complex
{
	private:
		int real;
		int img;
	public:
//-------------------------------------------------------------------
	complex() //default constructor
	{
		real=0;
		img=0;
	}
//-------------------------------------------------------------------
	complex (int r , int i) //parameterize constructor
	{
		real=r;
		img=i;
	}
//-------------------------------------------------------------------	
	complex operator +(complex t) //passed by value // function will store c2 value
									//c2 passed by value c3 calls the function
	{
	 // cout<<real<<"+"<<img<<"i"<<"\n"; it will print 5+5i c2 object
	 complex temp1; 			//because u cant return 2 value this stores the final value
	 temp1.real=real+t.real;
	 temp1.img=img+t.img; 
	 return(temp1);				//return 2 values to c1=c2+c3
	}
//-------------------------------------------------------------------	
/*	complex operator -(complex t)
								
								
	{

	 complex temp1; 			
	 temp1.real=real-t.real;
	 temp1.img=img-t.img; 
	 return(temp1);				
	}
*/	
//-------------------------------------------------------------------	
	complex operator *(complex m) //passed by value // complex m will store c3 value
	{
		complex temp2;
		temp2.real=(real*m.real)-(img*m.img);
		temp2.img=(real*m.img)+(img*m.real);
		return(temp2);
	}
//-------------------------------------------------------------------			
	friend complex operator - (complex&x,complex&y);
	friend ostream &operator<<(ostream&write , complex&t);	//IMP
//-------------------------------------------------------------------
};
//-------------------------------------------------------------------
ostream &operator<<(ostream&write ,complex&t)
{
	write<<"\n"<<t.real<<"+"<<t.img<<"i";
}
//-------------------------------------------------------------------
complex operator - (complex&x,complex&y)
{
	complex temp1; 			
	temp1.real=x.real-y.real;
	temp1.img=x.img-y.img; 
	return(temp1);		
}
//-------------------------------------------------------------------
int main()
{
	
cout<<"\ndefault complex no is";
complex c1;
cout<<c1;

cout<<"\nsecond complex no is ";
complex c2(1,1);
cout<<c2;

cout<<"\nthird complex no is ";
complex c3(1,1);
cout<<c3;

cout<<"\n-----------------------\n";


c1=c2+c3;
cout<<"\naddition - "<<c1;

c1=c2-c3;
cout<<"\nsubtraction - "<<c1;

c1=c2*c3;
cout<<"\nmultiplication - "<<c1;

return(0);
}
