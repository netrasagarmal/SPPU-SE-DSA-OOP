#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
//REMEMBER ONLY ONE CLASS pg 3-31
class book
{
	private:
		char author_name[20];
		char title[20];
		int price;
		bool status=true;
	public:
		book()
		{
			strcpy(this->author_name,"");
			strcpy(this->title,"");
			this->price=0;
		}
		void add_book()
		{
			cout<<"\nenter title : ";
			cin>>this->title;
			
			cout<<"enter author name : ";
			cin>>this->author_name;
			
			cout<<"enter price : ";
			cin>>this->price;
			
			cout<<"\n";			
		}
		
		void display_database()
		{
			cout<<"Title : "<<this->title<<endl;
			cout<<"Author : "<<this->author_name<<endl;
			cout<<"Price : "<<this->price<<endl;
			cout<<"\n******\n";
		}
		
		bool buy_book(char search_title[],int quantity) //IMP
		{
			bool found=false;
			if(strcmp(this->title,search_title)==0)
			{
				int cnt=0;
				cnt=quantity*this->price;
				cout<<"total price : "<<cnt;
				found=true;
				
				return found;
			}	
			return found;				
		}
		
		int delete_database(char delete_title[])
		{
			if(strcmp(this->title,delete_title)==0)
			{
				return 0;
			}
			return 1;
		}
};


main()
{
	int N;
	cout<<"\nEnter no. of book data to be enter : ";
	cin>>N;
	book b[N];
	char search_title[20];
	int quantity;
	char delete_title[20];
	int op=-1;
	int i,del[N],j;
	while(op!=0)
	{
		cout<<"\n1.ADD A BOOK";
		
		cout<<"\n2.DISPLAY DATABASE";

		cout<<"\n3.BUY A BOOK";
		
		cout<<"\n4.DELETE A BOOK";

		cout<<"\n5.EXIT";
			
	 	cout<<"\n\nENTER CHOICE : ";
	 	cin>>op;
	 	
	 	switch(op)
	 	{
	 		case 1:
	 				for( i=0;i<N;i++)
	 				{
	 				b[i].add_book();
					}
			break; 	
			
			case 2:
					for(i=0,j=0;i<N;i++,j++)
	 				{
	 					if(del[j]==0)
	 						break;
					b[i].display_database();
					}
			break;

			case 3:
				cout<<"enter the title of book to buy & quantity  : ";
				cin>>search_title>>quantity;
				for(i=0;i<N;i++)
 				{				
					if(b[i].buy_book(search_title,quantity))
						break;
				}
				if(i==N)
					cout<<"Book not available";
			break;
				
			case 4:
					cout<<"Enter title of book to delete : ";
					cin>>delete_title;
					for( i=0,j=0;i<N;i++,j++)
	 				{
						del[j]=b[i].delete_database(delete_title);
					}
			break;	
			
			case 5:
					op=0;
			break;	
	 	}
	}	
}
