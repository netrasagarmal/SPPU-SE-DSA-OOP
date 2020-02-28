//19 doubly linklist convert decimal to binary logic missing
#include<iostream>
using namespace std;   

class binnum
{
	private:	
		int bit;
		binnum*next;
		binnum*back;
	public:
	friend class dlist;

};

class dlist
{
	int n;
	binnum*root;
	binnum*curr;
	binnum*prev;
	binnum*end;
	
	public:
//------------------------------------------------------------------------------
	dlist()
	{
		root=NULL; 
		curr=NULL;
		prev=NULL;
		end=NULL;		
	}
//------------------------------------------------------------------------------	
	void readbinarynum()
	{
		int i,j,n,a1[4];
		cout<<"\nEnter decimal no : ";
		cin>>n;
		for(j=0;j<4;j++)
		{
			a1[j]=0;
		}
		i=0;
		while(n>0)
		{
			a1[i]=n % 2;
			n=n/2;
			i++;
		}
/*
		for(j=3;j>=0;j--)
		{
			cout<<a1[j]<<" ";
		}
*/	
		root=NULL; 
		curr=NULL;
		prev=NULL;
		end=NULL;	
		for(j=3;j>=0;j--)
		{
			curr=new binnum();
			curr->bit=a1[j];
			curr->back=NULL;
			curr->next=NULL;		
			if(root==NULL)
			{
				root=curr;
				prev=curr;
				end=curr;
			}
			else
			{
				prev->next=curr;
				curr->back=prev;
				prev=curr;
				end=curr;
			}
		}		

	}
//------------------------------------------------------------------------------	
	void display()	//no parameters as obj different 
		{
		
			curr=root;
			cout<<"\n";
			while(curr!=NULL)
			{
				cout<<curr->bit<<" ";
				curr=curr->next; //100=100->120 ie curr=120
			}
			
		}
//------------------------------------------------------------------------------	
	void comp1()
		{
			curr=root;//imp
			cout<<"\n";
			while(curr!=NULL)
			{
				if(curr->bit==0)
					curr->bit=1;
				else
					curr->bit=0;	
				
				curr=curr->next; //100=100->120 ie curr=120
			}
		}
//------------------------------------------------------------------------------		
	void comp2()
		{
			int carry=1;
			
			comp1();	//called ones complement 
			curr=end;	//MOST IMP
			while(curr!=NULL)
			{				
				if(carry==1&&curr->bit==1)
				{
					curr->bit=0;	
					carry==1;
				}				
				else if(carry==1&&curr->bit==0)
				{
					curr->bit=1;
					carry=0;
				}
				else if(curr->bit==1&&carry==0)
				{
					curr->bit=1;
					carry=0;
				}
				else
				{
					curr->bit=0;
				}
				
				curr=curr->back;//imp
			}	
		}
//------------------------------------------------------------------------------		
	void createblank(int n)		//n called=4
	{
		int i;
		for(i=0;i<n;i++)
		{
			curr=new binnum();
			curr->back=NULL;
			curr->next=NULL;
			curr->bit=0;	
		
			if(root==NULL)
			{
				root=curr;
				prev=curr;
				end=curr;
			}
			else
			{
				prev->next=curr;
				curr->back=prev;
				prev=curr;
				end=curr;
			}
		}		
	}	
//------------------------------------------------------------------------------	
	dlist operator + (dlist d2)		//d1 directly passed d2 passed by value
	{
		dlist temp;
		binnum*r1;
		binnum*r2;
		binnum*r3;
		
		temp.createblank(4); //n value passed as 4	THIS ONLY IMP
		r1=end; 		//d1
		r2=d2.end;		//d2
		r3=temp.end; 	//d3
		int carry=0;	
		while(r1!=NULL)
		{
			switch(carry)
			{
				case 0:
						if(r1->bit==0&&r2->bit==0)
						{
							r3->bit=0;
							carry=0;
						}
						else if(r1->bit==0&&r2->bit==1)
						{
							r3->bit=1;
							carry=0;
						}
						else if(r1->bit==1&&r2->bit==0)
						{
							r3->bit=1;
							carry=0;
						}
						else if(r1->bit==1&&r2->bit==1)
						{
							r3->bit=0;
							carry=1;
						}	
				break;
					
				case 1:	
						if(r1->bit==0&&r2->bit==0)
						{
							r3->bit=1;
							carry=0;
						}
						else if(r1->bit==0&&r2->bit==1)
						{
							r3->bit=0;
							carry=1;
						}
						else if(r1->bit==1&&r2->bit==0)
						{
							r3->bit=0;
							carry=1;
						}
						else if(r1->bit==1&&r2->bit==1)
						{
							r3->bit=1;
							carry=1;
						}
					break;				
			}
			r1=r1->back;
			r2=r2->back;
			r3=r3->back;	
		}
		return temp;
	} 			
//------------------------------------------------------------------------------
};

main()
{
	
	dlist d1;

	dlist d2;
	
	dlist d3;
	int op=-1;

	while(op!=0)
	{
		cout<<"\n\n1.accept binary no ";
		
		cout<<"\n2.display binary no";
		
		cout<<"\n3.ONEs complement";
		
		cout<<"\n4.TWOs complement";
		
		cout<<"\n5.Add binary no";
		
		cout<<"\n6.exit";
			
	 	cout<<"\n\nenter choice : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
	 			cout<<"\nenter first binary no";
	 			d1.readbinarynum();
	 			cout<<"\nenter second binary no";
	 			d2.readbinarynum();
			break;
			
			case 2:
				cout<<"\nfirst binary no is : ";
				d1.display();
				cout<<"\nsecond binary no is :";
	 			d2.display();
			break;
			
			case 3:
				cout<<"\n1s complement of first no : ";
				d1.comp1();
				d1.display();
				cout<<"\n1s complement of second no : ";
				d2.comp1();
				d2.display();
				//to restore orignal numbers
				d1.comp1();
				d2.comp1();
			break;	
			
			case 4:
				cout<<"\n2s complement of first no : ";
				d1.comp2();
				d1.display();
				cout<<"\n2s complement of second no : ";
				d2.comp2();
				d2.display();	
				//to restore orignal numbers
				d1.comp2();
				d2.comp2();
			break;
				
			case 5:
				cout<<"\naddition of no : ";
				d3=d1+d2;
				d3.display();					
			break;	
				
			case 6:
				op=0;
			break;	
	 	}
	}
}
