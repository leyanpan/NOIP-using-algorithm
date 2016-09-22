#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void get_fail(const char * sch, int * fail)
{
  int len = strlen(sch);
  int q, k;
  fail[0] = 0;
  for(q = 1, k = 0;q < len;q++)
  {
    while(k > 0 && sch[q] != sch[k])
      k = fail[k - 1];
    if(sch[q] == sch[k])
      k ++;
    fail[q] = k;
  }
}

int Find(const char * str, const char * sch)
{
  int fail[100];
  int len = strlen(sch), lens = strlen(str);
  get_fail(sch, fail);
  int i, q;
  for(i = 0, q = 0; i < lens;i++)
  {
    while(q > 0 && sch[q] != str[i])
      q = fail[q - 1];
    if(sch[q] == str[i])
      q ++;
    if(q == len)
      return i - q + 1;
  }
  return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  char str[100], sch[100];
  int next[100];
  cin >> sch >> str;
  cout << Find(str, sch);
  return 0;
}
