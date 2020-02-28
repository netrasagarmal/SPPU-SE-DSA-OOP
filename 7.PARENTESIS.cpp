//signs brackets ''
#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class stackp
{
	private:
		char s[50];
		char infix[50];
		int top;
	public:	
		stackp()
		{
			top=-1;
		}
		
		void getdata()
		{
			cout<<"\n";
			fflush(stdin);
			cout<<"enter infix exp : ";
			cin>>infix;
			cout<<"\n";
		}
		
		char pop()
		{
			return(s[top--]);
		}
		
		void evaluate()
		{
			cout<<"\n";
			int i;
			char op;
			top=-1;
			for(i=0;infix[i]!='\0';i++)
			{
				if(infix[i]=='(' || infix[i]=='{' || infix[i]=='[')
				{
					s[++top]=infix[i];
				}
				
				else if(infix[i]==')' || infix[i]=='}' || infix[i]==']')
				{
					op=pop();
					if(op=='('&&infix[i]==')' || op=='{'&&infix[i]=='}' || op=='['&&infix[i]==']')
						continue;
					else
					{
						cout<<"Parenthesis does not match";
						cout<<"\n";
						return;	
					}	
				}
			}
			if(top==-1)
			{
				cout<<"Parenthesis match";
				cout<<"\n";
			}			
			else
			{
				cout<<"Parenthesis does not match";
				cout<<"\n";
			}
			
			cout<<"\n";
		}
		
};

main()
{
	stackp s1;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n\n***VERPISS DICH***"<<endl;
		cout<<"1:ENTER INFIX EXP."<<endl;
		cout<<"2:EVALUATE"<<endl;
		cout<<"3:EXIT"<<endl;
		cout<<"ENTER CHOICE : ";
		cin>>op;
		switch(op)
		{
			case 1:
				s1.getdata();
			break;
			
			case 2:
				s1.evaluate();
			break;
			
			case 3:
				op=0;
			break;	
		}
	}
}
