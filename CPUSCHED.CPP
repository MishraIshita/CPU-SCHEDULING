#include<iostream.h>
#include<conio.h>
void output();
void sortprocess();
void completiontime();
int n,at[100],bt[100],ct[100],wt[100],tat[100],t,twt,ttat;
float avwt,avtat;

void main()
{
 clrscr();
 cout<<"enter no. of process ";
 cin>>n;
 cout<<"enter the AT of processes\n";
 for(int i=0;i<n;i++)

    cin>>at[i];
  cout<<"enter the BT of processes\n";
 for(i=0;i<n;i++)
	cin>>bt[i];

 sortprocess();
 if(at[0]==0)
   ct[0]=bt[0];
 else
  ct[0]=at[0]+bt[0];
completiontime();
output();
 getch();

}
void completiontime()
{
 for(int i=1;i<n;i++)
    ct[i]=ct[i-1]+bt[i];

for( i=0;i<n;i++)
{
 tat[i]=ct[i]-at[i];
 wt[i]=tat[i]-bt[i];


}
twt=0;
ttat=0;
for( i=0;i<n;i++)
{

 twt=twt+wt[i];
 ttat=ttat+tat[i];

}
 cout<<ttat<<'\t'<<twt<<'\n';
avwt=(float)twt/(float)n;
avtat=(float)ttat/(float)n;

}
void sortprocess()
{ int k;
 for(int i=0;i<n;i++)
 {    for(int j=0;j<n;j++)
	  {
	   if(at[j]>at[i])
	       { k=at[j];
		at[j]=at[i];
		at[i]=k;
		k=bt[j];
		bt[j]=bt[i];
		bt[i]=k;
	       }
	  }

 }

}
void output()
{  for(int i=0;i<n;i++)
cout<<at[i]<<'\t'<<bt[i]<<'\t'<<ct[i]<<'\t'<<tat[i]<<'\t'<<wt[i]<<'\n';
cout<<"average WT = "<<avwt<<'\n'<<"average TAT = "<<avtat;
}