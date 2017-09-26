# DRG - Data Random Generator

## Usage

For C++, you should include the `drg.h` file: 

```c++
#include "drg.h"
```

## Units

### `rand.h`

```c++
int rand_int(int l, int r);
long long rand_ll(long long l, long long r);
float rand_float(float l, float r);
double rand_double(double l,double r);
void rand_ll_pair(long long l,long long r,long long &a,long long &b);
void rand_double_pair(double l,double r,double &a,double &b);
bool rand_bool();
char rand_num_char();
char rand_lower_char();
char rand_upper_char();
char rand_alpha_char();
```

### `io.h`

```c++
char* in_filename(const char* filename,int testcase);
char* out_filename(const char* filename,int testcase);
void io_init(const char* filename,int testcase);
void io_gen(const char* stdname);
```

### `algo.h`

```c++
void rand_tree(int n);
void rand_weighted_tree(int n,long long w1,long long w2);
void rand_graph(int n,int m);
void rand_weighted_graph(int n,int m,long long w1,long long w2);
```
