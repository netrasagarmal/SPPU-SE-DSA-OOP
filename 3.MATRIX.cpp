#include<iostream>
using namespace std;

class matrix
{
	private:
		int a1[3][3];
		int b1[3][3];
		int add1[3][3];
		int sub[3][3];
		int mul[3][3];
		int trans1[3][3];
		int trans2[3][3];
		int i,j,k;
	public:
	void enter()
	{
		cout<<"\nEnter matrix 1\n";
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<endl<<"Enter element ("<<i<<")("<<j<<") : ";
				cin>>a1[i][j];
			}
		}

		cout<<"\nEnter matrix 2\n";
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<endl<<"Enter element ("<<i<<")("<<j<<") : ";
				cin>>b1[i][j];
			}
		}		
	}
//-------------------------------------------------------------------		
	void display()
	{
		cout<<"\nMATRIX 1\n";
		for(i=0;i<3;i++)
		{
			cout<<"\n";
			for(j=0;j<3;j++)
			{
				cout<<a1[i][j]<<"  ";
			}
		}

		cout<<"\n\nMATRIX 2\n";
		for(i=0;i<3;i++)
		{
			cout<<"\n";
			for(j=0;j<3;j++)
			{
				cout<<b1[i][j]<<"  ";
			}
		}		
	}
//-------------------------------------------------------------------		
	void upper_traingular()
	{
		int cnt=0,u_cnt=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(i == j)
				{
					if(a1[i][j]==0)
						u_cnt++;
				}
				if(i>j)
				{
					if(a1[i][j]==0)
						cnt++;
				}
				if(j>i)
				{
					if(a1[i][j]==0)
						u_cnt++;
				}
			}
		}
		if(cnt==3 && u_cnt==0)
			cout<<"MATRIX 1 IS UPPER TRAINGULAR\n";
		else
			cout<<"MATRIX 1 IS NOT UPPER TRAINGULAR\n";
	//***MATRIX 2
		cnt=0;
		u_cnt=0;		
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(i == j)
				{
					if(b1[i][j]==0)
						u_cnt++;
				}
				if(i>j)
				{
					if(b1[i][j]==0)
						cnt++;
				}
				if(j>i)
				{
					if(b1[i][j]==0)
						u_cnt++;
				}
			}
		}
		if(cnt==3 && u_cnt==0)
			cout<<"MATRIX 2 IS UPPER TRAINGULAR";
		else
			cout<<"MATRIX 2 IS NOT UPPER TRAINGULAR";
	}
//-------------------------------------------------------------------		
	void sum_diagonal()
	{
		int sum1=0,sum2=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(i==j)
					sum1=sum1+a1[i][j];
			}
		}
		cout<<"\nDiagonal Sum of matrix 1 : "<<sum1;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(i==j)
					sum2=sum2+b1[i][j];
			}
		}
		cout<<"\nDiagonal Sum of matrix 2 : "<<sum2;
	}
//-------------------------------------------------------------------		
	void transpose()
	{
		int temp;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				trans1[j][i]=a1[i][j];//rem
			}
		}
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				trans2[j][i]=b1[i][j];
			}
		}
		//displaying

		cout<<"\nMARIX 1   =    TRANSPOSE 1      MARIX 2    =    TRANSPOSE 2\n";
		for(i=0;i<3;i++)
		{
			cout<<"\n";
			for(j=0;j<3;j++)
			{
				cout<<a1[i][j]<<"  ";
			}
			cout<<"\t";
			for(j=0;j<3;j++)
			{
				cout<<trans1[i][j]<<"  ";
			}
			cout<<"\t";
			for(j=0;j<3;j++)
			{
				cout<<b1[i][j]<<"  ";
			}
			cout<<"\t";
			for(j=0;j<3;j++)
			{
				cout<<trans2[i][j]<<"  ";
			}			
		}
	}
//-------------------------------------------------------------------		
	void add()
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				add1[i][j]=a1[i][j]+b1[i][j];
			}
		}
		//displaying

		cout<<"\nMARIX 1   +    MATRIX 2    =    ADDITION\n";
		for(i=0;i<3;i++)
		{
			cout<<"\n";
			for(j=0;j<3;j++)
			{
				cout<<a1[i][j]<<"  ";
			}
			cout<<"\t";
			for(j=0;j<3;j++)
			{
				cout<<b1[i][j]<<"  ";
			}
			cout<<"\t";
			for(j=0;j<3;j++)
			{
				cout<<add1[i][j]<<"  ";
			}
		}
	}
//-------------------------------------------------------------------		
	void subtract()
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				sub[i][j]=a1[i][j]-b1[i][j];
			}
		}
		//displaying

		cout<<"\nMARIX 1   +    MATRIX 2   =    SUBTRACTION\n";
		for(i=0;i<3;i++)
		{
			cout<<"\n";
			for(j=0;j<3;j++)
			{
				cout<<a1[i][j]<<"  ";
			}
			cout<<"\t";
			for(j=0;j<3;j++)
			{
				cout<<b1[i][j]<<"  ";
			}
			cout<<"\t";
			for(j=0;j<3;j++)
			{
				cout<<sub[i][j]<<"  ";
			}
		}		
	}
//-------------------------------------------------------------------		
	void multiply()
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				mul[i][j]=0;//RRRRRRRRRRRRREEEEEEEEEEEEEMMMMMMMMEEEMMMBBBER
				for(k=0;k<3;k++)
				{
					mul[i][j] = mul[i][j] + a1[i][k] * b1[k][j];//imp b[k][j]
				}
			}
		}
		//displaying
		cout<<"\nMARIX 1   *    MATRIX 2   =    MULTIPICATION\n";
		for(i=0;i<3;i++)
		{
			cout<<"\n";
			for(j=0;j<3;j++)
			{
				cout<<a1[i][j]<<"  ";
			}
			cout<<"\t";
			for(j=0;j<3;j++)
			{
				cout<<b1[i][j]<<"  ";
			}
			cout<<"\t";
			for(j=0;j<3;j++)
			{
				cout<<mul[i][j]<<"  ";
			}
		}
	}
//-------------------------------------------------------------------
};

main()
{
	matrix m;
	int op=-1;
	while(op!=0)
	{
		cout<<"\n\n*******MENU*******";
		cout<<"\n1:Enter matrix 1 and 2";
		cout<<"\n2:Display matrix 1 and 2";
		cout<<"\n3:Check matrix upper traingular or not";//class
		cout<<"\n4:Sum of diagonal elements";
		cout<<"\n5:Transpose of matrix";
		cout<<"\n6:Addition of matrix 1 and 2";
		cout<<"\n7:Subtraction of matrix 1 and 2";
		cout<<"\n8:Multiplication of matrix 1 and 2";
		cout<<"\n9:Exit";
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>op;
		cout<<"******************\n";
		switch(op)
		{
			case 1:
				m.enter();
			break;
			
			case 2:
				m.display();
			break;			

			case 3:
				m.upper_traingular();
			break;

			case 4:
				m.sum_diagonal();
			break;
			
			case 5:
				m.transpose();
			break;
			
			case 6:
				m.add();
			break;

			case 7:
				m.subtract();
			break;

			case 8:
				m.multiply();
			break;
			
			case 9:
				op=0;
			break;	
		}
	}
}
