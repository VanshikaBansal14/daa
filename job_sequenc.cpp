#include<stdio.h>
#define MAX 20

int Job_Sequencing(float p[], int d[], int J[], int n,int id[],float *total_p);

int main()
{
	float p[MAX];
	int d[MAX],J[MAX]={0},id[MAX];							//Initialising the array J[] to zero
	float total_p=0.0f,t;
	int n,i,j,tn,k;
	
		
	printf("Enter the no. of objects:");
	scanf("%d",&n);
	
	for(i=1;i<=n;++i)
	{
		id[i]=i;
		
		printf("\nDetails of %d element:\n",i);
		printf("\nEnter the profit of object no.%d: ",i);
		scanf("%f",&p[i]);
		
		printf("Enter the deadline of object no.%d: ",i);
		scanf("%d",&d[i]);
		printf("\n....................................\n");
	}
	
	for(i=0;i<n-1;i++)								//sort using bubble sort technique
	{
		for(j=1;j<=(n-i-1);j++)
		{
			if(p[j]<p[j+1])							//calculating profit/weight
			{
				
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
				
				tn=d[j];
				d[j]=d[j+1];
				d[j+1]=tn;
				
				tn=id[j];
				id[j]=id[j+1];
				id[j+1]=tn;
			}
		}
	}
	k=Job_Sequencing(p,d,J,n,id,&total_p);
	
	printf("\n\nTotal profit: %f ",total_p);
	printf("\nThe sequence of jobs: ");
	for(i=1;i<=k;++i)
		printf("%d  ",J[i]);
}


//Greedy algorithm for sequencing unit time jobs with deadlines and profits
// d[i] >=1, 1<=i<=n are the deadlines, n>=1
//the jobs are ordered such that p[i]>=p[2]>=.....>=p[n]
//J[i] is the ith job in the optimal solution 1<=i<=k
//at termination d[J[i]] <=d[J[i+1]],  1<=i<=k

int Job_Sequencing(float p[], int d[], int J[], int n,int id[],float *total_p)
{
	int k,q,i,r;
	d[0]=J[0]=0;									//Initialiise; use of a fictious job 0(necessary)
	J[1]=id[1];											//Include job 1
	k=1;
	*total_p=*total_p +p[1];
	
	for(i=2;i<=n;i++)								//Consider jobs in decreasing order of p[i]
	{
		r=k;										//Find position for i and check feasibility of insertion
		while((d[J[r]]>d[i]) && (d[J[r]] !=r))		//Where in J this job has to be inserted
			r=r-1;
		
		if((d[J[r]]<= d[i]) && (d[i]>r))			//If job i is to be inserte in J
		{											//Insert into J[]
			for(q=k;q>=(r+1);--q)					//Move elements one position up in J
				J[q+1]=J[q];
				
			J[r+1]=id[i];
			k=k+1;
			*total_p=*total_p +p[i];				//Calculating the total profit
		}
	}
	return k;
}
