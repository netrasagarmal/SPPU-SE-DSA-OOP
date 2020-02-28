//14
#include<iostream>
#include<deque>
using namespace std;

class dequed
{
	private:
		deque<int>d1;
		deque<int>::iterator ptr;
	public:
//---------------------------------------------------		
	void add_front()
	{
		int n;
		while(1)
		{
			cout<<"Enter number : ";
			cin>>n;
			
			if(n == 0)
				break;
				
			d1.push_front(n);			
		}
	}
//---------------------------------------------------	
	void add_back()
	{
		int n;
		while(1)
		{
			cout<<"Enter number : ";
			cin>>n;
			
			if(n == 0)
				break;
				
			d1.push_back(n);			
		}		
	}
//---------------------------------------------------	
	void delete_front()
	{
		if(d1.size()==0)
		{
			cout<<"\nQUEUE IS EMPTY!!"<<endl;
			return;
		}
		d1.pop_front();
		cout<<"\nELEMENT DELETED";	
	}
//---------------------------------------------------	
	void delete_back()
	{
		if(d1.size() == 0)
		{
			cout<<"\nQUEUE IS EMPTY!!"<<endl;
			return;
		}
		d1.pop_back();
		cout<<"\nELEMENT DELETED";		
	}
//---------------------------------------------------	
	void display()
	{
		ptr=d1.begin();
	//	cout<<"1st = "<<*ptr<<endl;
		if(d1.size()==0)
		{
			cout<<"\nQUEUE IS EMPTY!!"<<endl;
			return;
		}
		
		for(;ptr!=d1.end();ptr++)
		{
			cout<<"Number : "<<*ptr<<endl;
		}			
	}
//---------------------------------------------------
};


main()
{
	dequed d;
	int op=-1;

	while(op!=0)
	{
		cout<<"\n\n1.ADD FROM FRONT";
		
		cout<<"\n2.ADD FROM BACK";
		
		cout<<"\n3.DELETE FROM FRONT";
		
		cout<<"\n4.DELETE FROM BACK";
		
		cout<<"\n5.DISPLAY";
		
		cout<<"\n6.EXIT";
		
	
	 	cout<<"\n\nENTER CHOICE : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
				d.add_front();			
			break; 	
			
			case 2:
				d.add_back();
			break;
			
			case 3:
				d.delete_front();
			break;	
			
			case 4:
				d.delete_back();
			break;
				
			case 5:
				d.display();
			break;	
				
			case 6:
				op=0;
			break;	
	 	}
	}
}
