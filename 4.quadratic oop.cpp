//4
#include<iostream>
#include<math.h>
using namespace std;
class quad
{
private:
	int a,b,c;
public:	
//-------------------------------------------------------------------
	quad()
	{
		a=0;
		b=0;
		c=0;
	}
//-------------------------------------------------------------------	
	quad(int x,int y, int z)
	{
		a=x;
		b=y;
		c=z;	
	}
//-------------------------------------------------------------------	
	quad operator + (quad d)
	{
		quad temp;
		temp.a=a+d.a;
		temp.b=b+d.b;
		temp.c=c+d.c;
		return(temp);
	}
//-------------------------------------------------------------------	
	void compute()
	{
		int x,ans=0;
		cout<<"\nEnter the value of x - ";
		cin>>x;
		ans = (a*x*x) + (b*x) + (c); 
		cout<<"\nThe ans is - "<<ans;
	}
//-------------------------------------------------------------------	
	void soln()			
	{
		float x1=0,x2=0,z=0,d=0;
		z=(b*b)-(4*a*c);
		d=sqrt(z);
		x1 =((-b)+(d))/(2*a);
		x2=((-b)-(d))/(2*a);
		cout<<"\nThe two roots are - \nx1="<<x1<<"\nx2="<<x2;
	}
//-------------------------------------------------------------------
	friend ostream &operator << (ostream&write,quad&t);
	friend istream &operator >> (istream&read,quad&m);
};
//-------------------------------------------------------------------
ostream &operator << (ostream&write,quad&t)
{
	write<<t.a<<"x^2 + "<<t.b<<"x + "<<t.c<<"\n";
}
//-------------------------------------------------------------------
istream &operator >> (istream&read,quad&m)
{
	cout<<"\nEnter values of a,b,c : ";
	read>>m.a>>m.b>>m.c;
}
//-------------------------------------------------------------------
main()
{
	quad q1;
	cout<<q1; //default constructor values print
	quad q2(1,2,3);
	cout<<q2; //parameterize constructor values print 
	
	quad q3,q4,q5(0,0,0);
	int n,k;
	do
	{
		cout<<"\nEnter 1.ENTER 2.DISPLAY 3.ADD  4.COMPUTE 5.TWO SOLUTIONS - ";
		cin>>n;
		switch(n)
		{
			case 1:
				cin>>q3>>q4;
			break;
			
			case 2:
				cout<<q3<<q4;
			break;
			
			case 3:
				q5=q3+q4;
				cout<<q5;
			break;
				
			case 4:
				q3.compute();
			break;
			
			case 5:
				q3.soln();
			break;	
		}
		cout<<"\nEnter 1=continue 2=exit - ";
		cin>>k;
	}while(k!=2);
}
