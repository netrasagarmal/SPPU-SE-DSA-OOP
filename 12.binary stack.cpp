//12
#include<iostream>
#include<stack>//push,pop,top
using namespace std;

class binary
{
	private:
		stack<int>s1;
		stack<int>s2;
		stack<int>s3;
		int b1[4];	//IMP
		int b2[4];
	public:
		void read()
		{
			int n;
			cout<<"ENTER 1ST BINARY NO."<<endl;
			for(int i=0;i<4;i++)
			{
				cout<<"Enter "<<i+1<<" bit : ";
				cin>>n;
				b1[i]=n;
				s1.push(n);	
			}	
			
			cout<<"\n\nENTER 2ND BINARY NO."<<endl;
			for(int i=0;i<4;i++)
			{
				cout<<"Enter "<<i+1<<" bit : ";
				cin>>n;
				b2[i]=n;
				s2.push(n);	
			}				
		}
		
		void display()
		{
			cout<<"1ST BINARY NO."<<endl;
			for(int i=0;i<4;i++)
			{
				cout<<b1[i];			
			}
			cout<<"\n2ND BINARY NO."<<endl;
			for(int i=0;i<4;i++)
			{
				cout<<b2[i];			
			}
		}
		
		void add()
		{
			int carry=0;
			int j1,j2;
			for(int i=0;i<4;i++)
			{
				j1=s1.top();
				s1.pop();
				j2=s2.top();
				s2.pop();
			//	cout<<"j1="<<j1<<"  j2="<<j2<<"\n";
				switch(carry)
				{
					case 0:
						if(j1==0&&j2==0)
						{
							s3.push(0);
							carry=0;
						}

						if(j1==0&&j2==1)
						{
							s3.push(1);
							carry=0;
						}

						if(j1==1&&j2==0)
						{
							s3.push(1);
							carry=0;
						}

						if(j1==1&&j2==1)
						{
							s3.push(0);
							carry=1;
						}
						
					break;
						
					case 1:	
						if(j1==0&&j2==0)
						{
							s3.push(1);
							carry=0;
						}

						if(j1==0&&j2==1)
						{
							s3.push(0);
							carry=1;
						}

						if(j1==1&&j2==0)
						{
							s3.push(0);
							carry=1;
						}

						if(j1==1&&j2==1)
						{
							s3.push(1);
							carry=1;
						}				
					break;
				}
			}
			cout<<"ADDITTION: ";
			for(int i=0;i<4;i++)
			{
				cout<<s3.top();
				s3.pop();
			}
			cout<<"\n";
		}
};

main()
{
	binary b;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n1.accept binary no ";
		
		cout<<"\n2.display binary no";
		
		cout<<"\n3.Add binary no";
		
		cout<<"\n4.exit";
			
	 	cout<<"\n\nenter choice : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
	 				b.read();
			break;
			
			case 2:
					b.display();
			break;
			
			case 3:
					b.add();
			break;	
			
			case 4:
					op=0;
			break;						
		}
	}
}
