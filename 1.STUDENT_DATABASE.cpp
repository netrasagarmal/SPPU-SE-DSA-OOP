#include<iostream>
#define N 5
using namespace std;

class student
{
	private:
		float a[N];
		int i,j,k;
	public:
	student()
	{
		for(i=0;i<N;i++)
		{
			cout<<"Enter marks of "<<i+1<<" student : ";
			cin>>a[i];
		}
	}
//-------------------------------------------------------------------------------
	void average_score()
	{
		float avg=0;	
		int C=N;
		for(i=0;i<N;i++)
		{
			if(a[i] == -1)
			{
				C--;
				i++;					
			}
			avg = avg + a[i];			
		}
		avg = avg/C;
		cout<<"AVERAGE = "<<avg;
	}
//-------------------------------------------------------------------------------	
	void highest_lowest()
	{
		float ht=0;
		float lw=a[0];	//or select a[o]
		for(i=0;i<N;i++)
		{	
			if(a[i] == -1)
			{
				i++;					
			}
			if(a[i]>ht)
			{
				ht=a[i];
			}
			if(a[i]<lw)
			{
				lw=a[i];
			}
		}
		cout<<"HIGHEST MARK : "<<ht<<endl;
		cout<<"LOWEST MARK : "<<lw<<endl;
	}
//-------------------------------------------------------------------------------
	void most_score()
	{
		float most;
		int curr_cnt=0;
		int prev_cnt=0;
		float most_score;
		for(i=0;i<N;i++)
		{
			if(a[i] == -1)
			{
				i++;					
			}
			curr_cnt=0;
			most=a[i];
			for(j=0;j<N;j++)
			{
				if(most == a[j])
					curr_cnt++;
			}
			if(curr_cnt > prev_cnt)
			{
				most_score = a[i];
			}
			prev_cnt = curr_cnt;//imps
		}		
	//	cout<<curr_cnt<<"   "<<prev_cnt;
		cout<<"MOST MARKS SCORE : "<<most_score<<endl;
	}
//-------------------------------------------------------------------------------
	void absent_students()
	{
		int cnt;
		for(i=0;i<N;i++)
		{
			if(a[i] == -1)
				cnt++;
		}
		cout<<"NUMBER OF STUDENT ABSENT : "<<cnt<<endl;
	}
//-------------------------------------------------------------------------------
	void display()
	{
		for(i=0;i<N;i++)
		{
		cout<<"Marks of "<<i+1<<" student : "<<a[i]<<endl;		
		}
	}
};
//-------------------------------------------------------------------------------
main()
{
	student s;
	int op=-1;

	while(op!=0)
	{
		cout<<"\n1.AVERAGE SCORE";
		
		cout<<"\n2.HIGHEST AND LOWEST SCORE";
		
		cout<<"\n3.MARKS SCORED BY MOST STUDENT";
		
		cout<<"\n4.ABSENT STUDENTS";
		
		cout<<"\n5.DISPLAY MARKS";
		
		cout<<"\n6.EXIT";
			
	 	cout<<"\n\nENTER CHOICE : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
				s.average_score();	
			break;
			
			case 2:
				s.highest_lowest();	
			break;
			
			case 3:
				s.most_score();
			break;		

			case 4:
				s.absent_students();
			break;
				
			case 5:
				s.display();
			break;

			case 6:
				op=0;
			break;	
	 	}
	}
}
