#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>//imp
using namespace std;

class info
{
	private:
		char name[20];
		char telephone_no[10];
	public:
		friend class directory;		
};

class directory
{
	private:
		char file_name[10];
		info ob;	//IMP
	public:
//------------------------------------------------------------------------------	
	directory()
	{
		cout<<"Enter file name : ";
		cin>>file_name;
	}
//-------------------------------------------------------------------------------		
	void create_file()
	{
		ofstream f;
		f.open(file_name,ios::out|ios::app|ios::binary);
		//if binary not specified it will be a text file
		
		if(!f)
		{
			cout<<"\n***error opening the file***";
			return;
		}
		
		cout<<"\n***enter name & to end file***\n\n";
		
		while(1)
		{
			cout<<"NAME : ";
			cin>>ob.name;
				if(strcmp(ob.name,"&")==0)
				break;
			cout<<"TELEPHONE NO. : ";
			cin>>ob.telephone_no;
			
			f.write((char*)&ob,sizeof(ob));		//Find Alternative
			cout<<"\n";
		}		
		f.close();
	}
//-----------------------------------------------------------------------------	
	void display_file()
	{
		ifstream f;
		f.open(file_name,ios::in|ios::binary);
	
		if(!f)
		{
			cout<<"\n***error opening the file***";
			return;
		}
		char search_name[20];
	
		f.read((char*)&ob,sizeof(ob));
		
		while(!f.eof())
		{
			cout<<"NAME : "<<ob.name<<"  TELEPHONE NO : "<<ob.telephone_no<<endl;
			f.read((char*)&ob,sizeof(ob));
		}
		
		f.close();
	
		}	
//------------------------------------------------------------------------------		
		void search_by_name()
		{
			char search_name[20];
			ifstream f;
			f.open(file_name,ios::in|ios::binary);
			
			if(!f)
			{
				cout<<"\n***error opening the file***";
				return;
			}
			
			cout<<"enter the name to be search : ";
			cin>>search_name;
			
			f.read((char*)&ob,sizeof(ob));
			
			while(!f.eof())
			{
				if(strcmp(search_name,ob.name)==0)
				{
					cout<<"NAME : "<<ob.name<<"  TELEPHONE NO. : "<<ob.telephone_no<<"\n";
					f.close();
					return;
				}
				f.read((char*)&ob,sizeof(ob));
			}
			
			cout<<"Name not found"<<endl;
			
			f.close();
		}	
//-------------------------------------------------------------------------------		
		void search_by_telephone_no()
		{
			char search_telephone[20];
			ifstream f;
			f.open(file_name,ios::in|ios::binary);
			
			if(!f)
			{
				cout<<"\n***error opening the file***";
				return;
			}
			
			cout<<"enter the telephone no. to be search : ";
			cin>>search_telephone;
			
			f.read((char*)&ob,sizeof(ob));
			
			while(!f.eof())
			{
				if(strcmp(search_telephone,ob.telephone_no)==0)
				{
					cout<<"NAME : "<<ob.name<<"  TELEPHONE NO. : "<<ob.telephone_no<<"\n";
					f.close();
					return;
				}
				f.read((char*)&ob,sizeof(ob));
			}
			
			cout<<"telephone no. not found"<<endl;
			
			f.close();			
		}
//-------------------------------------------------------------------------------		
		void  update_telephone_no()
		{
			char search_name[20];
			char new_tell_no[20];
			
			fstream f;
			f.open(file_name,ios::in);
			
			ofstream fo;
			fo.open("temp.txt",ios::out);
			
			if(!f)
			{
				cout<<"Error opening the file"<<endl;
				return;			
			}	
			
			cout<<"enter name to search : ";
			cin>>search_name;	
			
			f.read((char*)&ob,sizeof(ob));
			while(!f.eof())
			{
				if(strcmp(search_name,ob.name)==0)
				{
					cout<<"enter new telephone no : ";
					cin>>ob.telephone_no;
					fo.write((char*)&ob,sizeof(ob));				
				}		
				
				else
				{
					fo.write((char*)&ob,sizeof(ob));
				}
				f.read((char*)&ob,sizeof(ob));		
			}	
			
					
			f.close();
			fo.close();
			remove(file_name);
			rename("temp.txt",file_name);
		}
//-------------------------------------------------------------------------------
};

main()
{
	directory d1;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n1.CREATE FILE";
		
		cout<<"\n2.DISPLAY";
	
		cout<<"\n3.SEARCH BY NAME";
		
		cout<<"\n4.SEARCH BY TELEPHONE NO.";
		
		cout<<"\n5.UPDATE TELEPHONE NO.";
		
		cout<<"\n6.EXIT";
			
	 	cout<<"\n\nenter choice : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
	 				d1.create_file();
			break; 	
			
			case 2:
					d1.display_file();
			break;
			
			case 3:
					d1.search_by_name();
			break;
			
			case 4:
					d1.search_by_telephone_no();
			break;	
				
			case 5:
					d1.update_telephone_no();
			break;
				
			case 6:
					op=0;
			break;					 	
	 	}
	}	
}
