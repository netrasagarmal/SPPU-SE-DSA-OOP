//13
#include<iostream>
#include<list>
using namespace std;

class linklist
{
	private:
		list<int>s1;	//creating object of list of type int for stack
		list<int>::iterator ptr; //IMP input iterator as used to read from containers

		list<int>q;
		list<int>::iterator ptr2;
	public:
//----------------------------------------------------------------		
	void push_stack()
	{
		int n;
		cout<<"size before : "<<s1.size()<<"\n\n";//IMP
		while(1)
		{
			cout<<"Enter number : ";
			cin>>n;
			
			if(n == 0)
				break;
				
			s1.push_back(n);
		}
		cout<<"\nsize after : "<<s1.size();
	}
//----------------------------------------------------------------		
	void display_stack()
	{
		ptr=s1.end();	//it points for eg. to /0
		ptr--;	//therefore decrement by 1
		if(s1.size()==0) //IMP
		{
			cout<<"\nSTACK IS EMPTY!!"<<endl;
			return;
		}
		
		for(;ptr!=s1.begin();ptr--)
		{
			cout<<"Number : "<<*ptr<<endl;
		}
		cout<<"Number : "<<*ptr<<endl;
	}
//-------------------------------------------------------------		
	void pop_stack()
	{
		
		if(s1.size()==0)
		{
			cout<<"\nSTACK IS EMPTY!!"<<endl;
			return;
		}
		s1.pop_back();
		cout<<"\nELEMENT DELETED";	
	}

//****************************************************************
	void insert_queue()
	{
		int n;
		cout<<"size before : "<<q.size()<<"\n\n";
		while(1)
		{
			cout<<"Enter number : ";
			cin>>n;
			if(n == 0)
				break;
			q.push_back(n); //
		}
		cout<<"\nsize after : "<<q.size();
	}
//---------------------------------------------------------------
	void display_queue()
	{
		if(q.size()==0)
		{
			cout<<"\nQUEUE IS EMPTY!!"<<endl;
			return;
		}
		
		ptr2=q.begin();
	//	cout<<"1st = "<<*ptr2<<endl;
		for(;ptr2!=q.end();ptr2++)
		{
			cout<<"Number : "<<*ptr2<<endl;
		}		
	}	
//---------------------------------------------------------------
	void delete_queue()
	{
		if(q.size()==0)
		{
			cout<<"\nQUEUE IS EMPTY!!"<<endl;
			return;
		}
		q.pop_front();
		cout<<"\nELEMENT DELETED";	
	}
//----------------------------------------------------------------
};


main()
{
	linklist l;
	int op=-1;

	while(op!=0)
	{
		cout<<"\n\n1.PUSH TO STACK";
		
		cout<<"\n2.DISPLAY STACK";
		
		cout<<"\n3.POP FROM STACK";
		
		cout<<"\n4.INSERT IN QUEUE";
		
		cout<<"\n5.DISPLAY IN QUEUE";
		
		cout<<"\n6.DELETE FROM QUEUE";
		
		cout<<"\n7.EXIT";
		
	
	 	cout<<"\n\nENTER CHOICE : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
					l.push_stack();				
			break; 	
			
			case 2:
					l.display_stack();
			break;
			
			case 3:
					l.pop_stack();
			break;	
			
			case 4:
					l.insert_queue();
			break;
				
			case 5:
					l.display_queue();
			break;	

			case 6:
					l.delete_queue();
			break;
				
			case 7:
					op=0;
			break;	
	 	}
	}
}
