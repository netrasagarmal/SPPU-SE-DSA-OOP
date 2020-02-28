#include<iostream>
using namespace std;

class calculator
{
	private:
		int a,b,c;
		char sign;
	public:
	
	calculator()
	{
		a=0;
		b=0;
		c=0;	
	}	
	
	void enter()
	{
		cout<<"enter a & b : ";
		cin>>a>>b;
	}
	
	void accept()
	{
		cout<<"enter operation to perform  : ";
		cin>>sign;
			switch(sign) //MULTIWAY BRANCH STATEMENT
			{
				case '+':
					c=a+b;
				break;
	
				case '-':
					c=a-b;
				break;
				
				case '*':
					c=a*b;
				break;
				
				case '/':
					c=a/b;
				break;			
			}
		cout<<"\nANS="<<c;	
	}
};

main()
{
	int op=-1;
	while(op!=0)
	{
		calculator c1;
		c1.enter();
		c1.accept();
		cout<<"\nenter 1 to continue 0 to exit : ";
		cin>>op;
	}	
}
