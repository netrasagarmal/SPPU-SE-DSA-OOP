#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;

class directory
{
	private:
		char tno[10];
		char nm[30];
		char fname[20]; //according to user directory
	public:	
	
	directory()
	{
		cout<<"Enter the file name : ";
		cin>>fname;
	}
	
	void createfile()
	{
		ofstream fw; //object of class ofstream
		fw.open(fname,ios::out|ios::app); //
		if(!fw) //fw==NULL **%%
		{
			cout<<"Error opening the file"<<endl;
			return;
		}
	//	cout<<"successful";
		while(1)
		{
			fflush(stdin);
			cout<<"\nEnter the name : ";
			gets(nm);
			if(strcmp(nm,"&")==0)
				break;
			cout<<"\nEnter the telephone no. : ";
			cin>>tno;
			
			//cout<<"my name is"<<nm;
			fw<<nm<<"  "<<tno<<endl;
		}
		fw.close();
	}
	
	void display()
	{
		ifstream fi;
		fi.open(fname,ios::in);
		if(!fi)
		{
			cout<<"Error opening the file"<<endl;
			return;			
		}
		
		fi>>nm>>tno;
		
		while(!fi.eof())
		{
			cout<<nm<<"  "<<tno<<"\n"; 	
			fi>>nm>>tno;			
		}
		fi.close();
	}
	
	void update_tell_no()
	{
		int pos;
		char search_name[20];
		char new_tellno[20];
		fstream f;
		ofstream tf;
		tf.open("tmp.txt",ios::out);
		f.open(fname,ios::in);
		if(!f)
		{
			cout<<"Error opening the file"<<endl;
			return;			
		}		
		
		cout<<"Enter name to update tell no : ";
		cin>>search_name;
		
	//	pos=f.tellg();
		f>>nm>>tno;
		while(!f.eof())
		{
		//	cout<<pos<<endl;
			
			if(strcmp(search_name,nm)==0)
			{
				cout<<"enter new telephone no : ";
				cin>>new_tellno;
			//	f.seekp(pos,ios::beg);
				tf<<nm<<"  "<<new_tellno<<endl;				
			}
			else
			{
				tf<<nm<<"  "<<tno<<endl;
			}
		//	pos=f.tellg();
			f>>nm>>tno;
			
		}
		
		cout<<"close";
		f.close();
		tf.close();
		remove(fname);
		rename("tmp.txt",fname);
	}
};

main()
{
	directory d1;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n1.CREATE DIRECTORY";
		
		cout<<"\n2.SEARCH BY NAME";
		
		cout<<"\n3.SEARCH BY TELEPHONE NO";
		
		cout<<"\n4.UPDATE TELEPHONE NO";
		
		cout<<"\n5.EXIT";
			
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
					
			break;	
			
			case 4:
					d1.update_tell_no();
			break;	
				
			case 5:
				op=0;
			break;	
				 	
	
	 	}
	}	
}
