#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;

class info
{
	private:
			char name[20];
			char roll_no[10];
			char email_id[30];
	public:
			friend class data;		
};

class data
{
	private:
			char file_name[10];
			info ob;//only one obj imp
	public:
//-------------------------------------------------------------------	
	data()
	{
		cout<<"Enter file name : ";
		cin>>file_name;
	}
//-------------------------------------------------------------------
	void createfile()
	{
		ofstream f;
		f.open(file_name,ios::out | ios::app | ios::binary);
		//why | xor
		//if binary not specified it will be a text file
		if(!f)
		{
			cout<<"\n***error opening***";
			return;
		}
		cout<<"\n***enter name & to end file***\n\n";
		
		while(1)
		{
			cout<<"NAME : ";
			cin>>ob.name;
				if(strcmp(ob.name,"&")==0)
				break;
			cout<<"ROLL NO. : ";
			cin>>ob.roll_no;
			cout<<"EMAIL ID : ";
			cin>>ob.email_id;
			
			f.write((char*)&ob,sizeof(ob));//can use f<< instead of it
			cout<<"\n";
		}
		
		f.close();
	}
//-------------------------------------------------------------------	
	void display()
	{
		ifstream f;
		f.open(file_name,ios::in | ios::binary);
		if(!f)
		{
			cout<<"\n***error opening***";
			return;
		}
		
		
		f.read((char*)&ob,sizeof(ob));
		
		while(!f.eof())//!f.eof()
		{
			cout<<"NAME : "<<ob.name<<"  ROLL NO : "<<ob.roll_no<<"  EMAIL ID : "<<ob.email_id<<endl;
			f.read((char*)&ob,sizeof(ob));
		}		
		f.close();	
		}
//-------------------------------------------------------------------				
};

main()
{
	data d1;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n1.CREATE FILE";
		
		cout<<"\n2.DISPLAY";
	
		cout<<"\n3.EXIT";
			
	 	cout<<"\n\nenter choice : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
	 				d1.createfile();
			break; 	
			
			case 2:
					d1.display();
			break;
				
			case 3:
					op=0;
			break;		
	 	}
	}	
}
