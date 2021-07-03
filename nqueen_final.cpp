//NQueens problem using backtracking

#include<stdio.h>
#include<cmath>
void NQueens(int k, int n, int x[]);
int place(int k, int l, int x[]);
void print(int n, int x[]);

int  main()
{
	 int n,x[100];
    
    printf("\nEnter the no. of Queens: ");
    scanf("%d",&n);
    
    NQueens(1,n,x);
    
}


//Using backtracking,this procedure prints all possible placements of N Queens
//on an N * N chessboard so that they are bonattacking.
//Invoked by NQueens(1,n)
void NQueens(int k, int n, int x[])      	//n is the total no. of queens and k=storing the position of queen placed
{
	int i,j,l;
	 
		for(l=1; l<=n; l++)
		{ 
	     	if(place(k,l,x))     
	     	{                          		//true
	   	    	x[k] = l;
	   	    	if(k == n)              	//All the N-Queens are place at proper position
	   	    	 	print(n, x);            //display the result 
	   	    	else
	   	     		 NQueens(k + 1, n, x);  //Recursive call
			}
		}
}


//Returns true if a Queen can be placed in Kth row and Ith column.Otherwise it return False
//x[] is a global array whose first (k-1) valuse have been set
//Abs[r] returns the absolute valure of r.

//place() is only checking the legality
int place(int k, int l, int x[])
{
	int i;
	
	 for(i=1; i<=k-1; i++)
	 {
	    									//Two in the same column or in the same diagonal
	     //if value of previous q and current q same then return 0
		 if((x[i]==l) || (abs(x[i]-l)==abs(i-k)))
	          return 0;						//true so we are returning 0
	 }
	          
	     return 1;
}


void print(int n,int x[])
{
	int i,j,c;
 	printf("\n \nSolution- %d: ",++c);
 	printf("\n\n");
	for(i=1; i<=n; i++)
	    printf("\t %d",i);
	  	for(i=1; i<=n; i++)
	  	{
	     	printf("\n\n%d",i);
	    	for(j=1;j<=n;j++)
	    	{
	   	    	if(x[i]==j)
	   	           printf("\tQ");   		//queen at i nd j position
	   	    	else
	   	           printf("\t-");   		//empty slot
			}
		}
	printf("\n...................................\n");
}
