//18 singly linklist
#include<iostream>
using namespace std;   

class node
{
	private:	
		int no;
		node*next;
	public:
		friend class list;
};

class list
{
	node*root;
	node*curr;
	node*prev;
	node*temp;
	node*proot;
	node*nroot;
	node*sroot;
	node*r;
	public:
//-------------------------------------------------------
	list()
	{
		root=NULL; //node*root!=NULL as address of ptr can't be NULL therefore root=NULL similarly for all.
		curr=NULL;
		prev=NULL;
		temp=NULL;
		proot=NULL;
		nroot=NULL;
		sroot=NULL;	
		r=NULL;
	}	
//---------------------------------------------------------
	void createlist()	//1st func
	{
			while(1)
			{
				curr=new node;	//create blank node 
				cout<<"enter no : ";
				cin>>curr->no;
					if(curr->no==0)
					break;
	
				
				curr->next=NULL;
					if(root==NULL)
					{
						root=curr;
						prev=curr;
					}
					else
					{
							prev->next=curr;
							prev=curr;
					}
			}
	}
//-------------------------------------------------------	
	void display(node *r)	//common display function
	{
	
	
		cout<<"\n";
		while(r!=NULL)
		{
			cout<<r->no<<"   ";
			r=r->next; //100=100->120 ie r=120
		}
		cout<<"NULL";
	}
//-------------------------------------------------------
	node* getroot()		
	{
		return root;	/*we can't pass directly root in switch case as root is not declared in main 
						 function so written root with help of another function */
	}
//------------------------------------------------------	
	void delneg()	//delete negative node function
	{
		curr=root;	//set each ptr to root 
		prev=root;
		temp=root;
		cout<<"\n";
		while(curr!=NULL)
		{
			if(curr->no<0)		//if -ve no. then will enter
			{
				if(curr==root)	//if first no. -ve increment root tonext node
				{
					root=curr->next;
					prev=root;//don't just forward using next change
					curr=root;
				}
				else
				{
				prev->next=curr->next;	//else connect the node by skipping -ve node
				temp=curr->next;	//store next node address temp 
				delete curr;	//delete curr
				curr=temp;	//will assign the next node address
				}
			}
			else
			{				
				prev=curr;
				curr=curr->next; //only for poitive no.s for negative 1st only curr increments				
			}
		}
		display(root);	//it will go to display function and print eachnode except -ve ones 
	}	
//-------------------------------------------------------
	void splitlist(int t)
	{
	//	cout<<"nakul "<<t<<endl;
		r=root;//don't disturb root pointer
	//	cout<<r;
		if(t==0)//if not merging problem
			nroot=NULL;
		if(t==1)
			proot=NULL;	
	
		while(r!=NULL)
		{
			if(t==0) 	//negative link list creation
			{
				if(r->no < 0)//if not less then directly increment r=r->next;
				{
					curr=new node;
					curr->no=r->no;
				//	cout<<endl<<curr->no;
					curr->next=NULL;
					if(nroot==NULL)
					{
						nroot=curr;
						prev=curr;	
					}	
					else
					{
					//	cout<<"HEllo else ";
						prev->next=curr;
						prev=curr;
					}
				}
		
			}
			
			if(t==1)	//positive linklist creation
			{
				if(r->no > 0)
				{
					curr=new node;
					curr->no=r->no;
					curr->next=NULL;
					if(proot==NULL)
					{
						proot=curr;
						prev=curr;
					}
					else
					{
						prev->next=curr;
						prev=curr;
					}
					
				}
			}
					
			r=r->next;	//very very imp	
		}
	//	cout<<"End"<<endl;
		if(t==0)
		{
			display(nroot);		//it will pass nroot to display and -ve linkl list will be displayed
		}
		
		if(t==1)
		{
			display(proot);		//it will pass proot to display and +ve linkl list will be displayed
		}
	}	
//---------------------------------------------------
	int countnode(node *s)
	{
		int count=0;
		while(s!=NULL)
		{
			count++;
			s=s->next;	
		}	
		return count;
	}
//---------------------------------------------------
	void sort(node*r,int cnt)	//Bubble sort algorithm cch
	{
		int i,j,tmp;
		node*t;
		t=r;
		for(i=1;i<cnt;i++)
		{
			r=t;			//most IMP
			for(j=1;j<cnt;j++)
			{
				if(r->no > (r->next)->no)		//-5>-2
				{
					tmp=r->no;
					r->no=(r->next)->no;
					(r->next)->no=tmp;
				}
				r=r->next;
			}		
		}	
	}
//---------------------------------------------------
	void merge()
	{
		int ncount;
		int pcount;
		node*r1;	//negative nos
		r1=nroot;
		node*r2;	//positive nos
		r2=proot;
		ncount=countnode(nroot);
	//	cout<<"\nNEGATIVE COUNT : "<<ncount;
		pcount=countnode(proot);
	//	cout<<"\nPOSITIVE COUNT : "<<pcount;	
		sort(r1,ncount);
		sort(r2,pcount);
		
		while(r1!=NULL)
		{
			curr=new node;	
			curr->no=r1->no;			
			curr->next=NULL;
				if(sroot==NULL)
				{
					sroot=curr;
					prev=curr;
				}
				else
				{
					prev->next=curr;
					prev=curr;
				}	
			r1=r1->next;		
		}	
		
	
		while(r2!=NULL)
		{
			curr=new node;	
			curr->no=r2->no	;		
			curr->next=NULL;
				if(sroot==NULL)
				{
					sroot=curr;
					prev=curr;
				}
				else
				{
					prev->next=curr;
					prev=curr;
				}			
			r2=r2->next;
		}		
		cout<<"\nMerge list is : ";
		display(sroot);
	}
};

main()
{
	list l1;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n1.create list ";
		
		cout<<"\n2.displsy list ";
		
		cout<<"\n3.delete -ve no.s";
		
		cout<<"\n4.+ve & -ve linklist";
		
		cout<<"\n5.merge";
		
		cout<<"\n6.exit";
		
	
	 	cout<<"\n\nenter choice ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
	 			l1.createlist();
			break; 	
			
			case 2:
				l1.display(l1.getroot());
			break;
			
			case 3:
				l1.delneg();			
			break;	
			
			case 4:
				l1.splitlist(0);			//negative linklist split
				l1.splitlist(1);			//positive linklist split
			break;
				
			case 5:
				l1.merge();
			break;	
				
			case 6:
				op=0;
			break;	
	 	}
	}
}
