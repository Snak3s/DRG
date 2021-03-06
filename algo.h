#include <cstdio>
#include "rand.h"

int _ufs_get(int u,int f[])
{
	return f[u]-u?f[u]=_ufs_get(f[u],f):u;
}

void rand_tree(int n)
{
	int f[n+5];
	for (int i=1;i<=n;i++)
		f[i]=i;
	int tot=0;
	while (tot<n-1)
	{
		int i=rand_int(1,n);
		int j=rand_int(1,n);
		if (_ufs_get(i,f)!=_ufs_get(j,f))
		{
			f[_ufs_get(i,f)]=j;
			tot++;
			printf("%d %d\n",i,j);
		}
	}
}

void rand_weighted_tree(int n,long long w1,long long w2)
{
	int f[n+5];
	for (int i=1;i<=n;i++)
		f[i]=i;
	int tot=0;
	while (tot<n-1)
	{
		int i=rand_int(1,n);
		int j=rand_int(1,n);
		if (_ufs_get(i,f)!=_ufs_get(j,f))
		{
			f[_ufs_get(i,f)]=j;
			tot++;
			printf("%d %d %lld\n",i,j,rand_ll(w1,w2));
		}
	}
}

void rand_graph(int n,int m)
{
	if (m>=n)
	{
		rand_tree(n);
		m-=n-1;
	}
	int tot=0;
	while (tot<m)
	{
		int i=rand_int(1,n);
		int j=rand_int(1,n);
		if (i!=j)
		{
			printf("%d %d\n",i,j);
			tot++;
		}
	}
}

void rand_weighted_graph(int n,int m,long long w1,long long w2)
{
	if (m>=n)
	{
		rand_weighted_tree(n,w1,w2);
		m-=n-1;
	}
	int tot=0;
	while (tot<m)
	{
		int i=rand_int(1,n);
		int j=rand_int(1,n);
		if (i!=j)
		{
			printf("%d %d %lld\n",i,j,rand_ll(w1,w2));
			tot++;
		}
	}
}
