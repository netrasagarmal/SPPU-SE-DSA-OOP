//job queue job specification
#include<iostream>
#include<conio.h>
#include<string.h>
#define N 5
using namespace std;

class osqueue
{
	private:
		int q[N];
		string info[N];
		int front , rear;
		int p;	
	public:
		osqueue()
		{
			front = -1;
			rear  = -1;
		}
		
		void insertjob()
		{

			int n;
			if(rear == N-1)
			{
				cout<<"queue full\n";
				return;
			}
			else
			{
				cout<<"enter the job no : ";
				cin>>n;

				if(front==-1)
				{
					q[++rear]=n;
					++front;
				}
				else
				{
					q[++rear]=n;
				}
			}
			
		}
		
		void deletejob()
		{
			if(rear==-1&&front==-1)
			{
				cout<<"queue is empty\n";
				return;
			}			
			if(front == rear+1)
			{
				cout<<"All jobs deleted\n";
				return;
			}
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}			
			q[front++];
			cout<<"job deleted"<<endl;
		}
		
		void display()
		{
			int i;
			p=0;
			if(rear==-1||front==-1)
			{
				cout<<"queue is empty\n";
				return;
			}
			for(i=front;i<=rear;i++)
			{
				cout<<"Job no : "<<q[i]<<endl;
			}
		}
};

main()
{
	osqueue q1;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n1.INSERT JOB ";		
		cout<<"\n2.DELETE JOB";
		cout<<"\n3.DISPLAY";
		cout<<"\n4.EXIT";
			
	 	cout<<"\n\nEnter Choice : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
				q1.insertjob();	
			break;
			
			case 2:
				q1.deletejob();
			break;
			
			case 3:
				q1.display();
			break;		
				
			case 4:
				op=0;
			break;	
		}
	}		
}
