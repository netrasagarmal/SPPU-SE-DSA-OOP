//15 ticket A=available B=booked
#include<iostream>
#define N 10
#define S 7
using namespace std;

class row
{
	private:
		int seatno;
		char booking;
		row*next;
		row*back;
	public:
		friend class cinema;	
};

class cinema
{
	private:
		row*root[N];	//N define as 10
		row*curr;
		row*prev;
	public:	
//----------------------------------------------------------------------	
	cinema()
	{
		int i,j;
			
		for(i=0;i<N;i++)	//dont run till <= then i loop will run from 0 to 10 ie 11 row 
		{
			root[i]=NULL;	//set all 1 to 10 rows root ptr as NULL	
		}
//***********LOGIC FOR CREATION*************			
		for(i=0;i<N;i++)
		{
			curr=NULL;	//IMP IMP
			prev=NULL;
			for(j=0;j<S;j++)
			{
				curr=new row();
				curr->next=NULL;
				curr->back=NULL;
				curr->seatno=(j+1);		//if j is print it will show from 0 so j+1 it will show 1
				curr->booking='A';
		
				if(root[i]==NULL)
				{
					root[i]=curr;
					prev=curr;						
				}
				
				else
				{
					prev->next=curr;
					curr->back=prev;
					curr->next=root[i];//imp
					prev=curr;
				}
			}
		}
//***RANDOM ATLAST DO THIS LOGIC TO DISPLAY SOME SEAT B***
		for(i=0;i<N;i++)
		{	
			curr=root[i];
			for(j=0;j<S;j++)
			{
				if(i==j)
				{
					curr->booking='B';
				}
				else if(j==(S-1))
				{
					curr->booking='B';
				}
				else if(i<=(N-1))
				{
					curr->booking='B';
				}
			}
		}
		
	}
		
//-----------------------------------------------------------------------			
	void display()
	{
		int i,j;
		cout<<"\t\t\t\t   MOVIE : INFINITY WAR\n";
		cout<<"\t\t\t___________________________________________";
				cout<<endl<<"\t\t\t|\t\t|PLATINUM|\t\t   |";
		for(i=0;i<N;i++)
		{
			curr=root[i];		//1st row print from 1 to 7 then goes to second row
			cout<<"\n\t\t\t| "<<i+1<<"ROW\t";
		//	cout<<"\t\t\t|";
			for(j=0;j<S;j++)
			{
				cout<<curr->seatno<<":"<<curr->booking<<"  ";				
				curr=curr->next;
			}
			cout<<"|";
			if(i==3)
				cout<<endl<<"\t\t\t|\t\t  |GOLD|\t\t   |";
			if(i==6)
				cout<<endl<<"\t\t\t|\t\t  |SILVER|\t\t   |";
			cout<<"\n\t\t\t|\t\t\t\t\t   |";
		}
		cout<<"\n\t\t\t|__________________________________________|\n";
		cout<<"\t\t\t\t\t\tA=Available  B=Booked";
		cout<<"\n\t\t\tPLATINUM : RS 180\n\t\t\tGOLD     : RS 140\n\t\t\tSILVER   : RS 100\n";	
	}
//---------------------------------------------------------------------
	bool countAseat(int r,int n,int s_no)	//bool is same as int but it stores either true or false
									//to check 1st that many seats are available or not
	{
		int cnt=0,j;  //intially set count to zero
		curr=root[r];	//directly goto the row which is enter as start checking from there
		s_no--;
		for(j=s_no;j<S;j++)
		{
			if(curr->booking=='A')
			{
				cnt++;
			}
		curr=curr->next;	
		}
	//	cout<<"count : "<<cnt<<endl;
		if(cnt>=n)	 //if available seats more than or equal to enter then function will return true 
			return true;
		return false;	
	}
//---------------------------------------------------------------------
	void bookmyshow()
	{
		int r,n,j,s_no,price;
		while(1)		//it will run till correct row and seats are entered
		{
			cout<<"enter row , number of seats and seat no : ";
			cin>>r>>n>>s_no;
			
			if(r>10 || r<1) //row greater than 10 0r smaller than 1 invalid
				cout<<"***INVALID ROW***"<<endl;
			
			else if(n>4 || n<1)		//max only 4 seats allowed
				cout<<"***MAX SEATS ALLOWED TO BOOK ARE 4***"<<endl;
			
			else
			{				
				r=r-1; 			//as real rows are from 0 to 1 so r--if u say row 1 its row 1 so..
				s_no=s_no-1;
				break;		//it will break loop when correct row and n things are enter
			}
		}	
		price=n;
		
		if (countAseat(r,n,s_no)==false)	//if that many seats not available
		{
			cout<<"***REQUIRED ROW SEATS NOT AVAILABLE***"<<endl;
			return;
		}
	//	cout<<"seat no : "<<s_no;
		curr=root[r];
		for(j=0;j<s_no;j++)
			curr=curr->next;
		for(;j<S;j++)
		{
			if(curr->booking=='A'&&n>0)
			{
					curr->booking='B';
					n--;
			}
			curr=curr->next;	
		}
		int cost=0;
		if(r>=0&&r<4)
		{
			cost=price*180;
		}
		else if(r>3&&r<7)
		{
			cost=price*140;
		}
		else if(r>6&&r<9)
		{
			cost=price*100;
		}
		cout<<"\nTOTAL PAYMENT : "<<cost;
		cout<<"\n***TICKETS BOOKED***"<<endl;		
	}
	
//---------------------------------------------------------------------
//*******************
	bool countBseat(int r,int n,int s_no)	
	{
		int cnt=0,j;  
		curr=root[r];
		s_no--;
		for(j=s_no;j<S;j++)
		{
			if(curr->booking=='B')
			{
				cnt++;
			}
		curr=curr->next;	
		}
	//	cout<<"count : "<<cnt<<endl;
		if(cnt>=n)	 //if available seats more than or equal to enter then function will return true 
			return true;
		return false;	
	}
//---------------------------------------------------------------------
	void cancelmyshow()
	{
		int r,n,j,s_no;
		while(1)		//it will run till correct row and seats are entered
		{
			cout<<"enter row , number of seats and seat no : ";
			cin>>r>>n>>s_no;
			
			if(r>10 || r<1) //row greater than 10 0r smaller than 1 invalid
				cout<<"***INVALID ROW***"<<endl;
			
			else if(n>4 || n<1)		//max only 4 seats allowed
				cout<<"***MAX SEATS ALLOWED TO CANCEL ARE 4***"<<endl;
			
			else
			{				
				r=r-1; 			//as real rows are from 0 to 1 so r--if u say row 1 its row 1 so..
				s_no=s_no-1;
				break;		//it will break loop when correct row and n things are enter
			}
		}	
		
		
		if (countBseat(r,n,s_no)==false)	//if that many seats not available
		{
			cout<<"***REQUIRED ROW SEATS NOT AVAILABLE***"<<endl;
			return;
		}
	//	cout<<"seat no : "<<s_no;
		curr=root[r];
		for(j=0;j<s_no;j++)
			curr=curr->next;
		for(;j<S;j++)
		{
			if(curr->booking=='B'&&n>0)
			{
					curr->booking='A';
					n--;
			}
			curr=curr->next;	
		}
		cout<<"***TICKETS CANCEL***"<<endl;		
	}


};

main()
{
	cinema c1;
	int op=-1;

	while(op!=0)
	{
		cout<<"\n1.DISPLAY BOOKINGS ";
		
		cout<<"\n2.BOOK TICKETS";
		
		cout<<"\n3.CANCEL TICKETS";
		
		cout<<"\n4.EXIT";
			
	 	cout<<"\n\nenter choice ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
				c1.display();	
			break;
			
			case 2:
				c1.bookmyshow();	
			break;
			
			case 3:
				c1.cancelmyshow();
			break;		
				
			case 4:
				op=0;
			break;	
	 	}
	}
}
