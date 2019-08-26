 #include<iostream>
 //#include<stdlib.h>
using namespace std;
int minimum_cost(int matrix[20],int t)
{
	int x,small;
	if(t==1)
	return matrix[0];
	else
	{
		small=matrix[0];
		for(x=1;x<t;x++)
		{
			if(matrix[x]<small)
				small=matrix[x];
		}
		return small;
	}
}
int main()
{
	int i,t,j,l,k,limit,f;
	int matrix[30],multiplier[10][15]={0},columns[15],rows[15],temp[15];
	cout<<"\nEnter Total number of matrix  :\t";
	cin>>limit;
	for(i=0;i<limit;i++)
	{
		cout<<"\nEnter Number of Rows of matrix"<<i+1<<":\t";
		cin>>rows[i];
		cout<<"Enter Number of Columns of matrix"<<i+1<<":\t"; 
		cin>>columns[i];		
	}
	cout<<"\n\n\n";
	for(i=0;i<limit;i++)
		{
		temp[i]=rows[i];
		cout<<i;
	}
		cout<<i;
		temp[i]=columns[i-1];
	for(l=2;l<=limit;l++)
	{
		for(j=l,i=1;j<=limit;i++,j++)
		{
			t=0;
			for(k=i;k<j;k++)
			{
				matrix[t]=(multiplier[i][k] + multiplier[k+1][j]) + (temp[i-1]*temp[k]*temp[j]);
				t++;
			}
			multiplier[i][j]=minimum_cost(matrix,t);
		}
	}
	cout<<"\nMinimum Scalar Multiplication : \t "<<multiplier[1][limit];
	return 0;
}
