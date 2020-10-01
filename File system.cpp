#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
struct Node
	{
		char filename[8];
		char string[8];
		int dd;
		int mm;
		int yy;
		int hour;
		int min;
		int sec;
		int lmdd;
		int lmmm;
		int lmyy;
		int*initialptr;
		double noofblocksinfile;
};
class FAT
{
public:
	
int*bytesinsector=new int;
int*sectorinablock=new int;
int*harddiskcapacity=new int;
int totalblocks,i=0;

FAT()
{
cout<<"Enter hard disk size in MB"<<endl;
cin>>*harddiskcapacity;
*harddiskcapacity=*harddiskcapacity*1000000;
cout<<"Enter no. of sector present in one block"<<endl;
cin>>*sectorinablock;	
cout<<"Enter bytes present in one sector"<<endl;
cin>>*bytesinsector;
totalblocks=*harddiskcapacity/(*bytesinsector**sectorinablock);
delete(bytesinsector);
delete(sectorinablock);
delete(harddiskcapacity);
cout<<totalblocks<<endl;

}
};
main()
{
FAT obj;
int array[obj.totalblocks];
int totalfiletobecreated;
int i,j,k=0,l;
//int *freelist=&array[8];
Node arr[totalfiletobecreated];
char string1[8];
x:cout<<"Enter 1 if you want to create file"<<endl<<"Enter 2 for opening a file";
cin>>i;


switch(i)
{
	case 1:
	{

	cout<<"Enter how many files you want to create"<<endl;
	cin>>totalfiletobecreated;	
	for(i=0;i<totalfiletobecreated;i++)
	{
		cout<<"Enter file name";
		cin>>arr[i].filename;
		cout<<"Enter string ";
		cin>>arr[i].string;
		cout<<"Enter blocks in this file";
		cin>>arr[i].noofblocksinfile;
		arr[i].initialptr=&array[8+k];
		for(j=k;j<arr[i].noofblocksinfile+k;j++)
		{
		array[8+j]=9+j;
			
		}
		array[8+j]=-1;
		k=j++;
		
	}
	goto x;
	
	
	break;		
	}	
	case 2:
	{
	cout<<"Enter name of file you want to open";
	cin>>string1;
	for(l=0;l<totalfiletobecreated;l++)
	{
		if(arr[l].filename==string1)
		{
			cout<<arr[l].string<<endl;
			cout<<"This file is of"<<arr[l].noofblocksinfile<<"blocks"<<endl;
		}
	}
	break;	
	}	
	default: 
	break;	
}

}
