//OOP PROGRAM NO.5 STUDENT DATABASE DELETION INCOMPLETE
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class student
{
	private:
		int rno;
		char nm[20];
		char clas[20];
		char division;
		char dob[20];
		char bg[20];
		char tno[20];
		char drivinglicno[20];
		char email[20];
		bool status;
	public:
		student()
		{
			rno=00;
			division=00;
			strcpy(nm,"");
			strcpy(clas,"");
			strcpy(dob,"");
			strcpy(bg,"");
			strcpy(tno,"");
			strcpy(drivinglicno,"");
			strcpy(email,"");
		}
		friend class db;
};

class db
{
	private:
		student s[10];
		int j=0; //imp set intially  j=0
	public:
//-------------------------------------------------------------------			
	db()
	{
	}
//-------------------------------------------------------------------	
	void adddata()
	{			
		cout<<"\nenter roll no : ";
		cin>>s[j].rno; 	//s[0].rollno
		cout<<"\nenter name : ";
		cin>>s[j].nm;
		cout<<"\nenter class : ";
		cin>>s[j].clas;
		cout<<"\nenter division : ";
		cin>>s[j].division;
		cout<<"\nenter date of birth : ";
		cin>>s[j].dob;
		cout<<"\nenter blood group : ";
		cin>>s[j].bg;
		cout<<"\nenter telephone no. : ";
		cin>>s[j].tno;
		cout<<"\nenter driving license no. : ";
		cin>>s[j].drivinglicno;	
		cout<<"\nenter email : ";
		cin>>s[j].email;
																
		s[j].status=true;	//default print status true so it will print all
		j++; 	//imp
	}
//-------------------------------------------------------------------	
	void display()
	{
		int i;
		for(i=0;i<j;i++)
		{
			if(s[i].status==true)	//STATUS==FALSE;
			{				
			cout<<"\nroll no is : "<<s[i].rno;
			cout<<"\nname is : "<<s[i].nm;
			cout<<"\nenter class : "<<s[i].clas;
			cout<<"\nenter division : "<<s[i].division;
			cout<<"\nenter date of birth : "<<s[i].dob;
			cout<<"\nenter blood group : "<<s[i].bg;
			cout<<"\nenter telephone no. : "<<s[i].tno;
			cout<<"\nenter driving license no. : "<<s[i].drivinglicno;
			cout<<"\nenter email : "<<s[i].email;
			cout<<"\n--------------------------------------";
			}
		}
	}
//-------------------------------------------------------------------	
	void search()
	{
		int x,i;
		cout<<"\nenter the roll no to search - ";
		cin>>x;
		for(i=0;i<j;i++)
		{
			if(x==s[i].rno)
			{
				cout<<"\nroll no is - "<<s[i].rno;
				cout<<"\nname is - "<<s[i].nm;
				cout<<"\nenter class : "<<s[i].clas;
				cout<<"\nenter division : "<<s[i].division;
				cout<<"\nenter date of birth : "<<s[i].dob;
				cout<<"\nenter blood group : "<<s[i].bg;
				cout<<"\nenter telephone no. : "<<s[i].tno;
				cout<<"\nenter driving license no. : "<<s[i].drivinglicno;
				cout<<"\nenter email : "<<s[i].email;
				cout<<"\n--------------";
				return ;// if not return it will print "NUMBER NOT FOUND"
			}		
		}
		cout<<x<<" no. not found";
	}
//-------------------------------------------------------------------	
	void delete1()
	{
		int x,i;
		cout<<"\nenter the roll no to delete - ";
		cin>>x;
		for(i=0;i<j;i++)
		{
			if(x==s[i].rno)
			{
				s[i].status=false;				
				return;
			}			
		}
		cout<<x<<" no. not found";
	}
//-------------------------------------------------------------------	
	void modify()
	{
		int x,i;
		cout<<"\nenter the roll no to modify - ";
		cin>>x;
		for(i=0;i<j;i++)
		{
			if(x==s[i].rno)
			{						
				cout<<"\nenter class : ";
				cin>>s[i].clas;
				cout<<"\nenter division : ";
				cin>>s[i].division;
				cout<<"\nenter telephone no. : ";
				cin>>s[i].tno;
				cout<<"\nenter email : ";
				cin>>s[i].email;					
				cout<<"\n--------------";
				return;
			}
		}
		cout<<x<<" no. not found";	
	}
//-------------------------------------------------------------------
};


main()
{
	db d1;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n1.Add Data";
		
		cout<<"\n2.Displsy Data";
		
		cout<<"\n3.Search";
		
		cout<<"\n4.Delete";
		
		cout<<"\n5.Modify";
		
		cout<<"\n6.Exit";
			
	 	cout<<"\n\nEnter Choice : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{

	 		case 1:
	 			d1.adddata();
			break; 	
			
			case 2:
				d1.display();
			break;
			
			case 3:
				d1.search();
			break;	
			
			case 4:
				d1.delete1();
			break;	
				
			case 5:
			 	d1.modify();
			break;

	 		case 6:
	 			op=0;
	 		break;
	 						 		
	 	}
	}
}
