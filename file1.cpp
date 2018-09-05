#include<iostream>
#include<conio.h>
using namespace std;
int add();
int list();
int print();
void mergesort(int[],int,int);
void merge(int[],int,int);
int count=0;
string name[100],branch[100];
int age[100],year[100],sem[100],psem[100];
int main()
{
	cout<<"Welcome user"<<endl;
	print();
		return 0;
}
int add()
{
	cout<<"Enter the details"<<endl;
	cout<<"Enter the name"<<endl;
	cin>>name[count];
	cout<<"\n";
	cout<<"Enter the age"<<endl;
	cin>>age[count];
	cout<<"\n";
	cout<<"Enter the branch"<<endl;
	cin>>branch[count];
	cout<<"\n";
	cout<<"Enter the year"<<endl;
	cin>>year[count];
	cout<<"\n";
	cout<<"Enter the semester"<<endl;
	cin>>sem[count];
	cout<<"\n";
	cout<<"Enter the previous semester score"<<endl;
	cin>>psem[count];
	cout<<"\n";
	count++;
	print();
	return 0;
}
int list()
{
	char n;
	cout<<"Rank\tName\tAge\tBranch\tYear\tSemester\tPrevious Semester Score"<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<i+1<<"\t"<<name[i]<<"\t"<<age[i]<<"\t"<<branch[i]<<"\t"<<year[i]<<"\t"<<sem[i]<<"\t\t\t"<<psem[i]<<endl;
	}
	cout<<"Do you want to filter by score(Y/N)?"<<endl;
	cin>>n;
	if(n=='y'||n=='Y')
	{
		int l=0,h=count-1;
		mergesort(psem,l,h);
		list();
		print();
	}
	if(n=='n'||n=='N')
	{
		print();
	}

	return 0;
}
int print()
{
	cout<<"Select the function to perform"<<endl;
		cout<<"1.Add Details"<<endl;
		cout<<"2.List Details"<<endl;
		cout<<"3.Exit Application"<<endl;
		int c;
		cin>>c;
			if(c==1)
			{
				add();
			}
			else
				if(c==2)
				{
					list();
				}
				else
					if(c==3)
					{
						exit(0);
					}
					else
					{
						cout<<"Enter valid input"<<endl;
						print();
					}

		return 0;
}
void mergesort(int a[],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		merge(a,l,h);
	}

}
void merge(int a[],int l,int h)
{
	int mid=(l+h)/2;
	int p=l,q=mid+1;
	int t[l+h-1];
	string t1[l+h-1],t2[l+h-1];
	int t3[l+h-1],t4[l+h-1],t5[l+h-1];
	int k=0;
	while(p<=mid&&q<=h)
	{
		if(a[p]<a[q])
		{
			t[k++]=a[p++];

		}
		else
			t[k++]=a[q++];

	}
	while(p<=mid)
	{
		t[k++]=a[p++];

	}
	while(q<=h)
	{
		t[k++]=a[q++];
	}
	for(int i=l;i<=h;i++)
	{
		a[i]=t[i];

	}
}
