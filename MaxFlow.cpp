#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

int Capacity[1000][1000];
int Max_Flow = 0;

int N, R, S, D;
#define Re(n) for(int i = 0;i < n;i++)

void Input()
{
  ios::sync_with_stdio(false);
  cin >> N >> R >> S >> D;
  int s, d, c;
  Re(R)
  {
    cin >> s >> d >> c;
    Capacity[s][d] = c;
  }
}

bool Get_Path();

void Solve()
{
  while(Get_Path());
}

#define INF 0xF000000

bool Get_Path()
{
  int Path[1000];
  int f[1000];
  memset(f, 0, sizeof(f));
  memset(Path, 0, sizeof(Path));
  f[S] = INF;
  queue<int> Q;
  Q.push(S);
  while(!Q.empty() && !f[D])
  {
    int V = Q.front();
    Q.pop();
    for(int i = 0;i < N;i++)
      if(Capacity[V][i] && f[i] == 0)
      {
	Path[i] = V;
	f[i] = min(f[V], Capacity[V][i]);
	Q.push(i);
      }
  }
  int Cp = D;
  while(Cp != S)
  {
    Capacity[Cp][Path[Cp]] += f[D];
    Capacity[Path[Cp]][Cp] -= f[D];
    Cp = Path[Cp];
  }
  Max_Flow += f[D];

  return f[D] != 0;
}

void Output()
{
  cout << Max_Flow;
}

int main()
{
  Input();
  Solve();
  Output();
  return 0;
}
