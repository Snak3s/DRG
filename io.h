#include <cstdio>
#include <cstdlib>
#include <cstring>

char __dest[1024];
char __filename[1024];
int __testcase;

char* in_filename(const char* filename,int testcase)
{
	char tcdest[256];
	sprintf(tcdest,"%d",testcase);
	strcpy(__dest,filename);
	strcat(__dest,tcdest);
	strcat(__dest,".in");
	return __dest;
}

char* out_filename(const char* filename,int testcase)
{
	char tcdest[256];
	sprintf(tcdest,"%d",testcase);
	strcpy(__dest,filename);
	strcat(__dest,tcdest);
	strcat(__dest,".out");
	return __dest;
}

void io_init(const char* filename,int testcase)
{
	strcpy(__filename,filename);
	__testcase=testcase;
	freopen(in_filename(filename,testcase),"w",stdout);
}

void io_gen(const char* stdname)
{
	fclose(stdout);
	char tcdest[1024];
	strcpy(tcdest," < ");
	strcat(tcdest,in_filename(__filename,__testcase));
	strcat(tcdest," > ");
	strcat(tcdest,out_filename(__filename,__testcase));
	strcpy(__dest,stdname);
	strcat(__dest,tcdest);
	system(__dest);
}
