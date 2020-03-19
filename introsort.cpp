#include "introsort.h"
#include <math.h>
void zamiana (int *a, int *b)
{
	int w=*a;
	*a=*b;
	*b=w;
}
bool czy_posortowane(int T[], int r){
	for(int i=0; i<r; i++)
	{
		if (T[i] > T[i+1])
		{
			return false;
		}
	}
	return true;
}
void wstaw (int T[], int n ) 
{
	for (int i=1;i<n;i++) 
	{
		int j, pom = T[i];
		for (j=i;j>=1 && T[j - 1]>pom; j-- )
		{
			T[j] = T[j - 1];
		}
		T[j] = pom;
	}
}
int podziel ( int T[], int p, int r)
{
	int os, srodek = (p+r)/2; 
	if(T[p]>T[srodek])
	{
		os=p;
	}
	else 
	{
		os=srodek;
	}
	if(T[os]>T[r])
	{
		os = r;
 	}
	zamiana(&T[os], &T[p]);
	os = p; 
	while (p<r)
	{
		if (T[p]<=T[r])
		{
			zamiana( &T[os++], &T[p] );
		}
		++p;
	} 
	zamiana(&T[os], &T[r]);
	return os;
}
void kopiec(int T[], int p, int r ){
	int pom = T[p];
	while (p<=r/2) 
	{
		int k=2*p;
		while(k<r && T[k]<T[k+1])
		{
			++k;
		}
		if(pom >=T[k])
		{	
			break;
		}
		T[p]=T[k];
		p=k;
	}
	T[p] = pom;
}

void sort_kopiec(int T[], int p, int r )
{
	for(int i =(r-1)/2;i>=p;i--)
	{
		kopiec(T,i,r-1);
	}
	for(int i=r-1;i>p;i--)
	{
		zamiana( &T[i], &T[p]);
		kopiec(T,p,i-1);
	}
}

void introsort_1(int T[], int p, int r, int g){
  while(r-p>0) 
  {
		if(g=0)
		{
			sort_kopiec(&T[p],p,r-p+1);
		}
		else 
		{
			int os;
			if (czy_posortowane(T, r))
			{
				break;
			}
			os=podziel(T,p,r);
			introsort_1(T,os+1,r,g-1);
			r=os-1;
		}
	}
}
 
void introsort(int T[], int n){
	introsort_1 ( T, 0, n-1, (int(2*log(double(n)))));
	wstaw(T, n);
}
 


 

