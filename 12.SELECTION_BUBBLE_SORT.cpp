#include<iostream>
#define N 8
using namespace std; 
class sort
{
	private:
		float p[N];
	public:
//------------------------------------------------------------
		void enter_percentage()
		{
			float no;
			for(int i=0;i<N;i++)
			{
				cout<<"Enter percentage : ";
				cin>>no;
				p[i]=no;
			}
		}
//------------------------------------------------------------		
		void display_percentage()
		{
			for(int i=0;i<N;i++)
			{
				cout<<"Percentage  : "<<p[i]<<endl;
			}
		}
//------------------------------------------------------------		
		void selection_sort()
		{
			int i,j,k;
			float temp;
			for(i=0;i<N;i++)
			{
				k=i;
				for(j=i+1;j<N;j++)
				{
					if(p[j]<p[k])
					{
						k=j;
					}
				}
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
			}
			cout<<"\n\n***SELECTION SORT***\n";
			display_percentage();
		}
//------------------------------------------------------------		
		void bubble_sort()//as bubble rises up smallest element up
		{
			int i,j;
			float temp;
			for(i=0;i<N-1;i++)
			{
				for(j=0;j<N-i-1;j++)
				{
					if(p[j]>p[j+1])
					{
						temp=p[j];
						p[j]=p[j+1];
						p[j+1]=temp;
					}
				}				
			}
			cout<<"\n\n***BUBBLE SORT***\n";
			display_percentage();
		}
//------------------------------------------------------------
	void top_5()
	{
		int j=0;
			for(int i=N-1;j<5;i--)
			{
				cout<<"Percentage  : "<<p[i]<<endl;
				j++;
			}		
	}
//------------------------------------------------------------
};

main()
{
	sort s1;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n1.ENTER PERCENTAGE";
		
		cout<<"\n2.DISPLAY";
		
		cout<<"\n3.SELECTION SORT";
		
		cout<<"\n4.BUBBLE SORT";
		
		cout<<"\n5.TOP FIVE SCORES";
		
		cout<<"\n6.EXIT";
	
	 	cout<<"\n\nENTER CHOICE : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
	 				s1.enter_percentage();
			break; 	
			
			case 2:
					s1.display_percentage();
			break;
			
			case 3:
					s1.selection_sort();
			break;	
			
			case 4:
					s1.bubble_sort();
			break;	

			case 5:
					s1.top_5();
			break;
				
			case 6:
					op=0;
			break;	
	 	}
	}
}
