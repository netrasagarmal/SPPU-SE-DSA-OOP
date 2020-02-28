#include<iostream>
#include<stdio.h>
using namespace std;

class strings
{
	private:
		char s1[30];
		char s2[30];
		char s3[30];
		char s4[30];
		int i,j,k,len;
		char a,b,c;
	public:
		void enter_string()//strlen()
		{
			len=0;
			fflush(stdin);
			cout<<"Enter string  : ";
			gets(s1);
			for(i=0;s1[i]!='\0';i++)
				len++;
			cout<<len;
		}
//----------------------------------------------------------------------
		void display_string()
		{
			cout<<"String  : "<<s1<<endl;
		}
//----------------------------------------------------------------------
		void frequency_char()//strchr()
		{
			int cnt=0;
			cout<<"Enter character to find : ";
			cin>>a;
			for(i=0;s1[i]!='\0';i++)
			{
				if(s1[i] == a)
					cnt++;	
			}	
			cout<<"Character "<<a<<" has occur "<<cnt<<" times"<<endl;
		}
//----------------------------------------------------------------------
		void delete_char()//delchar(string,n,pos)n=no.of char to delete pos=position)
		{
			cout<<"Enter character to delete : ";
			cin>>a;
			for(i=0,j=0;s1[i]!='\0';i++,j++)
			{
				if(s1[i] == a)
					i++;
				s2[j] = s1[i];
			}
			//display
			j++;
			s2[j]='\0';
			cout<<"Deleted string is "<<s2;
		}
//----------------------------------------------------------------------
		void delete_sub()
		{
			int s , l;
			cout<<"Enter start and length of string : ";
			cin>>s>>l;
			for(i=0,j=0;s1[i]!='\0';i++,j++)
			{
				if(i == s)
					break;
				s2[j]=s1[i];
			}
			for(i=s+l;s1[i]!='\0';i++,j++)
			{
				s2[j]=s1[i];
			}
			cout<<"New string : "<<s2;
		}
//----------------------------------------------------------------------
		void replace_sub()//strstr()
		{
			int m;
			char newstr[30];
			char rstr[30];
			char sstr[30];
			int rlen=0;
			int slen=0;
			cout<<"Enter the string to be search : ";
			cin>>sstr;
			cout<<"Enter the replace string : ";
			cin>>rstr;
			for(i=0;rstr[i]!='\0';i++,rlen++){
			}
			for(i=0;sstr[i]!='\0';i++,slen++){
			}
			//cout<<"\nslen = "<<slen<<endl<<"rlen = "<<rlen;
			j=0;
			for(i=0;i<len;)//remember len not '\0'
			{
				if(s1[i]==sstr[j])
				{
					i++;
					j++;
					if(j == slen)
					{
						for(k=0;k<i-slen;k++)
						{
							newstr[k]=s1[k];
						}
						for(m=0;m<rlen;m++,k++)
						{
							newstr[k]=rstr[m];
						}
						//
					
						if(k>=i)
						{
							m=i;
							for(;s1[m]!='\0';m++,k++)
							{
								newstr[k]=s1[m];
							}
						}
						else
						{
							m=k;
							for(;s1[i]!='\0';i++,k++)
							{
								newstr[k]=s1[i];
							}
						}	
						//give it here break		
					}		
					newstr[k]='\0';
				//	break;
				}
				else
				{
					i++;
				}
			}
			cout<<endl<<"NEW STRING : "<<newstr;
		}
//----------------------------------------------------------------------
		void palindrome()
		{
			len--;
			for(i=0;s1[i]!='\0';i++,len--)
			{
				if(s1[i]!=s1[len])
				{
					cout<<"String not a Palindrome";
					return;
				}
			}
			cout<<"String is palindrome";
		}
//----------------------------------------------------------------------
};

main()
{
	strings s;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n\n***********MENU***************"<<endl;
		cout<<"1 : ENTER STRING"<<endl;
		cout<<"2 : FREQUENCY OF CHARACTER"<<endl;
		cout<<"3 : DELETE CHARACTER"<<endl;
		cout<<"4 : DELETE SUBSTRING"<<endl;
		cout<<"5 : REPLACE SUBSTRING"<<endl;
		cout<<"6 : CHECK PALINDROME"<<endl;
		cout<<"7 : EXIT"<<endl;
		cout<<"********************************"<<endl;
		cout<<"\nENTER CHOICE : ";
		cin>>op;
		switch(op)
		{
			case 1:
				s.enter_string();
			break;
			
			case 2:
				s.frequency_char();
			break;
				
			case 3:
				s.delete_char();
			break;
		
			case 4:
				s.delete_sub();
			break;
			
			case 5:
				s.replace_sub();
			break;
			
			case 6:
				s.palindrome();
			break;	
			
			case 7:
				op=0;
			break;					
		}
	}
}
