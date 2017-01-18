#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,j,coli,rowi,tr,tc,temp,temp1;
	cout<<"Enter size of matrix";
	cin>>n;
	int a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	bool visited[n][n]={false};
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n-1;j++)
		{
			if(visited[i][j]==false)
			{
				rowi=i;
				coli=j;
				visited[rowi][coli]=true;
				tr=coli;
				tc=n-1-rowi;
				//cout<<"tr="<<tr<<"\ntc="<<tc;
				temp=a[tr][tc];
				a[tr][tc]=a[rowi][coli];
				coli=tc;
				rowi=tr;
				while(rowi!=i || coli!=j)
				{
					visited[rowi][coli]=true;
					tr=coli;
					tc=n-1-rowi;
					//cout<<"\ntr="<<tr<<"\ntc="<<tc;
					temp1=a[tr][tc];
					a[tr][tc]=temp;
					temp=temp1;
					rowi=tr;
					coli=tc;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
	}
	return 0;
}
