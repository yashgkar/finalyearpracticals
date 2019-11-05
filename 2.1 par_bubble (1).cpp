Title:-Bubble_sort
#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;
void bubble(int *, int);
void swap(int &, int &);
void bubble(int *a, int n)
{
	for(  int i = 0;  i < n;  i++ )
	 {       
		int first = i % 2;      

		#pragma omp parallel for shared(a,first)
		for(  int j = first;  j < n-1;  j += 2  )
		  {       
			if(  a[ j ]  >  a[ j+1 ]  )
			 {       
  				swap(  a[ j ],  a[ j+1 ]  );
			 }}}}
void swap(int &a, int &b)
{
int test;
test=a;
a=b;
b=test;
}
int main()
{
	int *a,n;
	cout<<"\n enter total no of elements=>";
	cin>>n;
	a=new int[n];
	cout<<"\n enter elements=>";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bubble(a,n);
	cout<<"\n sorted array is=>";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
return 0;
}
/*OUTPUT*/
lenovo@lenovo-Lenovo-G50-80:~$ g++ -fopenmp 2.1\ par_bubble.cpp 
lenovo@lenovo-Lenovo-G50-80:~$ export OMP_NUM_THREADS=4
lenovo@lenovo-Lenovo-G50-80:~$ ./a.out
 enter total no of elements=>5
 enter elements=>21
15
18
11
10
 sorted array is=>10
11
15
18
21

