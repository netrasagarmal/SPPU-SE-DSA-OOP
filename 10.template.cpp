//OOP PROGRAM NO.10 FUNCTION TEMPLATE
#include<iostream>
#include<stdio.h>
using namespace std;

template <typename dt>
void enter(dt n)
{
	int i;
	for(i=0;i<5;i++)
	{
		cout<<"Enter Number : ";
		cin>>n[i];
	}
}

template <typename dt>
void sort(dt n)
{
	int i,j,k;
	float temp;
	for(i=0;i<5;i++)
	{
		k=i;
		for(j=i+1;j<5;j++)
		{
			if(n[j]<n[k])
			{
				k=j;
			}
		}
		temp=n[i];
		n[i]=n[k];
		n[k]=temp;
	}
}

template <typename dt>
void display(dt n)
{
	int i;
	for(i=0;i<5;i++)
	{
		cout<<"Number : "<<n[i]<<endl;		
	}
}

main()
{
	int a[5];
	float b[5];	
	
	enter(a);
	sort(a);
	display(a);
	cout<<"\n\n";
	enter(b);
	sort(b);
	display(b);
}
