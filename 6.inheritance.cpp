//OOP PROGRAM NO. 6 MULTIPLE INHERITANCE
#include<iostream>
using namespace std;

class prof //parent class
{
	protected:
		char exp[20];
		char field[20];
	public:	
		void getdata()
		{
			cout<<"\t\tPROFESSIONAL FIELD INFO";
			cout<<"\nenter the field of study : ";
			cin>>field;
			cout<<"enter year of exp : ";
			cin>>exp;
		}	
};

class acad	//parent class
{
	protected:
		char yop[20];
		char marks[20];
	public:	
		void getdata()
		{
			cout<<"\t\tACADEMIC FIELD INFO";
			cout<<"\nenter the year of passing : ";
			cin>>yop;
			cout<<"enter marks : ";
			cin>>marks;
		}	
		
	
};

class pers	//parent class
{
	protected:
		char nm[20];
		char bg[20];
		char boy[20];
	public:	
		void getdata()
		{
			cout<<"\t\tPERSONAL FIELD INFO";
			cout<<"\nenter the name : ";
			cin>>nm;
			cout<<"enter blood group : ";
			cin>>bg;
			cout<<"enter birth date: ";
			cin>>boy;
		}	
};

class biodata : public prof , public acad , public pers //child class
{
	public:
		void display()
		{	
			cout<<"\n\t\tBIODATA";
			
			cout<<"\nPERSONAL";
			cout<<"\n\tname: "<<nm;
			cout<<"\n\tblood group: "<<bg;
			cout<<"\n\tbirth date: "<<boy;
			cout<<"\nPROFESSIONAL";
			cout<<"\n\tfield of study: "<<field;
			cout<<"\n\texperience: "<<exp;
			cout<<"\nACADEMIC";
			cout<<"\n\tyear of passing: "<<yop;
			cout<<"\n\tmarks: "<<marks;
			cout<<"\n********************************************"<<endl;
		}
};


main()
{
	int n,i;
	biodata b[10];
	cout<<"\nenter the number of employee - ";
	cin>>n;
	for(i=1;i<=n;i++)
	{
	cout<<"\t\tEMPLOYEE "<<i<<"\n";
	b[i].prof::getdata();	//IMP :: to call parent class function 
	b[i].acad::getdata();
	b[i].pers::getdata();
	cout<<"\n********************************************"<<endl;
	}
	cout<<"******************************************"<<endl;
	for(i=1;i<=n;i++)
	{
	cout<<"\t\tEMPLOYEE "<<i;
	b[i].display();
	}
}
