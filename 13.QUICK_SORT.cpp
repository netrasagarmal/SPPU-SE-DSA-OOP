//types of recursion pg 5-89 tb
#include<iostream>
#define N 7
using namespace std;

class sorting
{
	public:
		float s[N];
//-------------------------------------------------------
	void enter_percentage()
	{		
		for(int i=0;i<N;i++)
		{
			cout<<"Enter number : ";
			cin>>s[i];			
		}	
	}
//-------------------------------------------------------
	int partition(float s[] , int start , int end)
	{
		int i;
		int pi;
		int pivot;
		float  temp;
		i=start;
		pi=start;
		pivot=end;
		for(i=start;i<=end;i++)
		{
			if(s[i] < s[pivot])
			{
				temp = s[i];
				s[i]=s[pi];
				s[pi]=temp;
				pi++;
			}
		}
		temp=s[pi];
		s[pi]=s[pivot];
		s[pivot]=temp;
		
		return pi;
	}
//-------------------------------------------------------
	void quick_sort(float s[] , int start , int end)
	{
		int pi;
		if(start<=end)//remember if
		{
			pi=partition(s,start,end);
			quick_sort(s,start,pi-1);//direct recursion//types direct indirect tail(goto) tree
			quick_sort(s,pi+1,end);
		}
		//display();
	}
//-------------------------------------------------------
	void display()
	{
		for(int i=0;i<N;i++)
		{
			cout<<"Number : "<<s[i]<<endl;
		}		
	}
//-------------------------------------------------------
	void display_top_5()
	{
		int cnt=0;
		for(int i=N-1;cnt<5;i--)
		{
			cout<<"Number : "<<s[i]<<endl;
			cnt++;
		}		
	}	
//-------------------------------------------------------
};

int main()
{
	sorting s1;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n1.ENTER PERCENTAGE ";		
		cout<<"\n2.QUICK SORT ";		
		cout<<"\n3.DISPLAY TOP 5";		
		cout<<"\n4.EXIT";
			
	 	cout<<"\n\nEnter choice : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		
	 		case 1:
	 			s1.enter_percentage();
			break; 	
			
			case 2:
				s1.quick_sort(s1.s,0,N-1); //error don't pass s1.N
										   //pass array , starting value ,end value
			break;
			
			case 3:
				s1.display();
			break;	
			
			case 4:
				op=0;	
			break;					
	 	}
	}
	return 0;
}
