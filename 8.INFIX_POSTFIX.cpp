//DSA INFIX TO POSTFIX CONVERSION top=-1at evaluatte >=wt exam strcpy(infix,"")
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class stack
{
	private:
		char ifix[20];
		char pfix[20];
		char s[20];
		int top;
	public:
	
//--------------------------------------------------------------------
	void accept()
	{
		top=-1;			//IMP
		fflush(stdin);
		cout<<"Enter the Infix expression : ";
		cin>>ifix;
	}
//-------------------------------------------------------------------
	char pop()	
	{
		return(s[top--]);
	}	
//-------------------------------------------------------------------		
	int checkpresedence(char op)
	{
		if(op=='(')
			return -1;
		if(op=='+' || op=='-')
			return 0;
		if(op=='*' || op=='/')
			return 1;	
	}
//-------------------------------------------------------------------
	bool checkpriority(char op1,char op2)
	{
		int w1,w2;
		w1=checkpresedence(op1);
		w2=checkpresedence(op2);
		if(w1>=w2)//>= remember
			return true;
		return false;	
	}
//-------------------------------------------------------------------
	void convert()
	{
		int i,j,p=0;
		char op;
		for(i=0;ifix[i]!='\0';i++)
		{
			if(ifix[i]=='(')
			{
				s[++top]=ifix[i];
			}
				
			else if(ifix[i]==')')
			{
				while(1)
				{
					op=pop(); //imp to write outside bracket as (,{,[ gets remove from stack
					if(op!='(')
					{
						pfix[p]=op;
						p++;
					}
					else 
						break;
				}
			}
			else if(ifix[i]=='+'|| ifix[i]=='-'|| ifix[i]=='*'|| ifix[i]=='/')
			{
				while(checkpriority(s[top],ifix[i])&&top!=-1)	//top!=-1 IMP
				{
					op=pop();
					pfix[p]=op;
					p++;	
				}
				s[++top]=ifix[i];		//IMP
			}
			else
			{
				pfix[p]=ifix[i];
				p++;
			}
		}
		
		for(j=top;j>=0;j--)
		{
			pfix[p]=s[j];
			p++;
		}
		pfix[p]='\0';  //IMP
		cout<<endl<<"Expression converted to Postfix"<<endl;
	}
//-----------------------------------------------------------------------	
	void evaluate()
	{
		int p;
		int n1,n2;
		int ans;
		top=-1; 		//IMP
		for(p=0;pfix[p]!='\0';p++)
		{
			if(isdigit(pfix[p]))
			{
				s[++top]=pfix[p];
			}
			else
			{
				n1=pop()-'0';
				n2=pop()-'0';
			//	cout<<n1<<"  "<<n2;
				switch(pfix[p])
				{
					case '+':
						s[++top]=(n2+n1)+'0';
					break;
					
					case '-':
						s[++top]=(n2-n1)+'0';
					break;
					
					case '*':
						s[++top]=(n2*n1)+'0';
					break;
					
					case '/':
						s[++top]=(n2/n1)+'0';
					break;	
				}
			}
		}
		top=0;
		ans=s[top]-'0';
		cout<<"ANS = "<<ans;
		cout<<"\n\n";
	}
//----------------------------------------------------------------------	
	void display()
	{
		fflush(stdin);
		cout<<"the infix expression is : "<<ifix<<endl;
		fflush(stdin);
		cout<<"the postfix expression is : "<<pfix<<endl;
	}
//-----------------------------------------------------------------------		
};

main()
{
	stack s1;
	int op=-1;
	while(op!=0)
	{
		cout<<"***********MENU***********";
		cout<<"\n1.ENTER INFIX EXPRESSION";		
		cout<<"\n2.CONVERT TO  POSTFIX";
		cout<<"\n3.DISPLAY";
		cout<<"\n4.EVALUATE";
		cout<<"\n5.EXIT";		
	 	cout<<"\nEnter Choice : ";
	 	cin>>op;
	 	cout<<"**************************\n";
	 	switch(op)
	 	{
	 		case 1:
		 		s1.accept();
			break; 	
			
			case 2:
				s1.convert();
			break;
			
			case 3:
				s1.display();
			break;	
			
			case 4:
				s1.evaluate();	
			break;
				
			case 5:
				op=0;
			break;	
		}
	}
}
