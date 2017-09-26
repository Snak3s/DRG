#include <cstdlib>
#include <cmath>
#include <ctime>

#ifndef __DRG_RAND

#define __DRG_RAND

bool __s_rand=0;

void rand_init()
{
	if (__s_rand)
		return;
	srand(time(0));
	__s_rand=1;
}

int rand_int(int l,int r)
{
	if (!__s_rand)
		rand_init();
	unsigned long long v1=rand(),v2=rand();
	unsigned long long k=v1*v2%(r-l+1)+l;
	return (int)k;
}

long long rand_ll(long long l,long long r)
{
	unsigned long long v1=rand_int(1,RAND_MAX),v2=rand_int(1,RAND_MAX);
	unsigned long long k=v1*v2%(r-l+1)+l;
	return (long long)k;
}

float rand_float(float l,float r)
{
	long double v1=rand_ll(1,0x7FFFFFFFFFFFFFFF),v2=rand_ll(1,0x7FFFFFFFFFFFFFFF);
	long double k=v1/v2;
	k=k*(r-l)+l;
	return (float)k;
}

double rand_double(double l,double r)
{
	long double v1=rand_ll(1,0x7FFFFFFFFFFFFFFF),v2=rand_ll(1,0x7FFFFFFFFFFFFFFF);
	long double k=v1/v2;
	k=k*(r-l)+l;
	return (double)k;
}

void rand_ll_pair(long long l,long long r,long long &a,long long &b)
{
	if (r<l)
		return;
	a=rand_ll(l,r);
	b=rand_ll(l,r);
	while (a>b)
	{
		a=rand_ll(l,r);
		b=rand_ll(l,r);
	}
	return;
}

void rand_double_pair(double l,double r,double &a,double &b)
{
	if (r<l)
		return;
	a=rand_double(l,r);
	b=rand_double(l,r);
	while (a>b)
	{
		a=rand_double(l,r);
		b=rand_double(l,r);
	}
	return;
}

bool rand_bool()
{
	return rand_double(0,1)<0.5;
}

char rand_num_char()
{
	return (char)rand_int('0','9');
}

char rand_lower_char()
{
	return (char)rand_int('a','z');
}

char rand_upper_char()
{
	return (char)rand_int('A','Z');
}

char rand_alpha_char()
{
	return rand_bool()?rand_lower_char():rand_upper_char();
}

#endif
