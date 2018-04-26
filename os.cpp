#include<bits/stdc++.h>
using namespace std;
struct process
{
	int pid;
	int bt;
};
bool comparison(process a , process b)
{
	return (a.bt < b.bt);
}
void findWaitingTime(process p[] , int n , int wt[])
{
	wt[0]=0;
	for(int i=1; i<n;i++)
	wt[i]=p[i-1].bt + wt[i-1];
}
void findTurnAroundTime(process p[] , int n , int wt[] , int tat[] )
{
	for(int i=0; i<n;i++)
	tat[i]=p[i].bt + wt[i];
}
void findavgTime(process p[],int n)
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	findWaitingTime(p,n,wt);
	findTurnAroundTime(p,n,wt,tat);
	cout<<"\n Processes"<<"Burst time"<<"Waiting time"<<"Turn Around time \n";
	for(int i=0; i<n;i++)
	{
		total_tat = total_tat + tat[i];
		total_wt = total_wt + wt[i];
		cout<<" "<<p[i].pid << "\t\t"<<p[i].bt<<"\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
		
		}
		
	cout<<"Average waiting time=" <<(float)total_wt/(float)n;
	cout<<"\n Average turn around time="<<(float)total_tat/(float)n;
		
}

int main()
{
	process p[]={ {1,20} , {2,36},{3,19} ,{4,42} };
	int n= sizeof p / sizeof p[0];
	sort(p , p+n , comparison);
	cout<<"order in which process gets executed \n";
	for(int i=0; i<n;i++)
	cout<<p[i].pid<<" ";
	findavgTime(p,n);
	return 0;
}

