//oral questions on best and worst case complexity
/*n=no. of comparison
sequential/linear search = O(n) ,sentinel search=O(n) ,binary search=O(log2n)
,fibonacci search=O(log n)*/
#include<iostream>
#define N 6
using namespace std;
class search
{
	private:
		int s[N];
		int i;
		int n;	
	public:
//----------------------------------------------------------------	
		search()
		{		
			for(i=0;i<N;i++)
			{
				cout<<"Enter no. : ";
				cin>>n;
				s[i]=n;
			}
			cout<<"\n***ALL NUMBERS ENTER***";
		}
//----------------------------------------------------------------			
		void linear_search()
		{
			int search_no=0;
			cout<<"\nEnter no. to search : ";
			cin>>search_no;
			for(i=0;i<N;i++)
			{
				if(search_no == s[i])
				{
					cout<<"NUMBER FOUND";
					return;
				}	
			}
			cout<<"Number not found";
		}
//----------------------------------------------------------------			
		void sentinel_search()
		{
			int search_no;
			int last;
			last = s[N-1];
			cout<<"\nEnter number to be found : ";
			cin>>search_no;
			s[N-1]=search_no;
			for(i=0;s[i]!=search_no;i++)
			{
			}
			s[N-1]=last;
			if(i<N-1 || last==search_no)
				cout<<"\nNumber found";
			else
				cout<<"Number not found";
		}
//----------------------------------------------------------------			
		void binary_search()//fastest search
		{
			int i,j,k,temp;
			int search_no=0;
			for(i=0;i<N;i++)
			{
				k=i;
				for(j=i+1;j<N;j++)
				{
					if(s[j]<s[k])
					{
						k=j;
					}
				}
				temp=s[i];
				s[i]=s[k];
				s[k]=temp;
			}
			//selection sort completed			
			cout<<"\nEnter no. to search : ";
			cin>>search_no;	
			int start=0,end=N-1,mid;
			while(start<=end)
			{
				mid=(start+end)/2;
				
				if(s[mid] == search_no)
				{
					cout<<"NUMBER FOUND";
					return;
				}
				if(s[mid] > search_no)
				{
					end = mid-1;
				}
				if(s[mid] < search_no)
				{
					start=mid+1;
				}
			}
			cout<<"\nNUMBER NOT FOUND";		
		}
//----------------------------------------------------------------		
		void display_nos()
		{
			for(i=0;i<N;i++)
			{
				cout<<"Number : "<<s[i]<<endl;
			}
			cout<<"\n***ALL DISPLAYED***\n";
		}
//----------------------------------------------------------------			
		void fibonacci_search()//not done yet
		{
			int i,j,k,temp;
			int search_no;
			for(i=0;i<N;i++)
			{
				k=i;
				for(j=i+1;j<=5;j++)
				{
					if(s[j]<s[k])
					{
						k=j;
					}
				}
				temp=s[i];
				s[i]=s[k];
				s[k]=temp;
			}
			//selection sort completed									
		}
//----------------------------------------------------------------	
};

main()
{
	search s1;
	int op=-1;	
	while(op!=0)
	{
		cout<<"\n\n1.Linear search";
		
		cout<<"\n2.Sentinel search";
		
		cout<<"\n3.Binary search";
				
		cout<<"\n4.Fibonacci search";
		
		cout<<"\n5.Display";
		
		cout<<"\n6.Exit";	
			
	 	cout<<"\n\nEnter Choice - ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
		 		s1.linear_search();
			break; 	
			
			case 2:
				s1.sentinel_search();
			break;
			
			case 3:
				s1.binary_search();
			break;	
				
			case 4:
				s1.fibonacci_search();
			break;	
	
			case 5:
				s1.display_nos();
			break;	
					
			case 6:
				op=0;
			break;	 	
	
	 	}
	}
}
