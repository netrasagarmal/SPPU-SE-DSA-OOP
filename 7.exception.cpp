//OOP PROGRAM NO. 7 EXCEPTION HANDLING
//types oral
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class person
{
	private:
		 int age,income;
		 char city[50];
		 bool wheel;
		 
	public: 
	 
	 void accept()
	 {
	 	try
	 	{
	 		cout<<"enter age : ";
	 		cin>>age;
	 		if(age<15 || age>55)
	 			throw ("entered incorrect age");
	 			
	 		cout<<"enter income : ";
			cin>>income;
			if(income<50000 || income>100000)
				throw("entered incorrect income");
			
	 		fflush(stdin);
			cout<<"enter city : ";
			gets(city); //IMP below statement
			//	if(strcmp(city,"pune")==1 || strcmp(city,"mumbai")==1 || strcmp(city,"chennai")==1 || strcmp(city,"banglore")==1)
				if(strcmp(city,"pune")!=0 && strcmp(city,"mumbai")!=0 && strcmp(city,"chennai")!=0 && strcmp(city,"bangalore")!=0)						
					throw("entered incorrect city");
				
			cout<<"if you have 4-wheeler enter 1 if not 0 : ";
			cin>>wheel;
			if(wheel==0)
				throw("employee needs a 4-wheeler");
				
			cout<<"******TRANSACTION COMPLETED******";				
		}
		
		catch(const char *s) //const=read only can't modify
		{
			cout<<"exception generated"<<endl;
			cout<<"\t"<<s<<endl;
			cout<<"******TRANSACTION FAILED******"<<endl;
		}
	 }
};

main()
{
	person p1;
	p1.accept();
}
