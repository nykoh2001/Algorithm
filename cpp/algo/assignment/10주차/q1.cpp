#include <iostream>
#include <string>

using namespace std;

void initSP(char *p);

int *SP = new int(5); // SP에 대한 메모리는 p의 크기만큼 동적 할당 해야한다.
const int q = 33554393;
const int d = 26;

void brutesearch(char *p, char *a)
{ // p : Pattern String, a : Text String
  int _compare = 0, start_idx;

  int i, j;
  int m = (int)strlen(p), n = (int)strlen(a);

  cout << "Brute force: ";

  for (i = 0; i <= n - m; i++)
  {
    for (j = 0; j < m; j++)
    {
      ++_compare;
      if (a[i + j] != p[j])
        break;
    }
    start_idx = i;
    if (j == m)
    { // 결과값 출력 }
      cout << start_idx << " ";
    }
  }
  cout << _compare << endl;
}
void kmpsearch(char *p, char *a)
{
  int _compare = 0, start_idx;
  int i, j, m = strlen(p), n = strlen(a);
  initSP(p);

  cout << "KMP: ";
  for (i = 0, j = -1; i <= n - 1; i++)
  {
    while ((j >= 0) && ++_compare && (p[j + 1] != a[i]))
    {
      j = SP[j];
    }
    if (p[j + 1] == a[i])
      j++;
    if (j == m - 1)
    {
      // 결과값 출력
      j = SP[j];
      cout << i - m + 1 << " ";
    }
  }
  cout << _compare << endl;
}
void initSP(char *p)
{
  int i, j, m = (int)strlen(p);
  SP[0] = -1;
  for (i = 1, j = -1; i <= m - 1; i++)
  {
    while ((j >= 0) && (p[j + 1] != p[i]))
      j = SP[j];
    if (p[j + 1] == p[i])
      j++;
    SP[i] = j;
  }
}

void rksearch(char *p, char *a)
{
  int _compare = 0, start_idx;
  int i, j, dM = 1, h1 = 0, h2 = 0, flag;
  int m = strlen(p), n = strlen(a);
  cout << "Rabin-Karp: ";
  for (i = 1; i < m; i++)
    dM = (d * dM) % q;

  for (i = 0; i < m; i++)
  {
    h1 = (h1 * d + int(p[i] - 'A')) % q;
    h2 = (h2 * d + int(a[i] - 'A')) % q;
  }
  for (i = 0; i < n - m + 1; i++)
  {

    if (++_compare && h1 == h2)
    {
      flag = 1;
      for (j = 0; j < m; j++)
      {
        if (++_compare && a[i + j] != p[j])
        {
          flag = 0;
          break;
        }
      }
      if (flag) // 결과값 출력
      {
        cout << i << " ";
      }
    }

    if (i < n - m)
    {

      h2 = (h2 - int(a[i] - 'A') * dM);
      h2 = (h2 * d + int(a[i + m] - 'A')) % q;
    }
  }
  cout << _compare << endl;
}

int main()
{
  char *T = "SONG LYRICS. TWINKLE TWINKLE LITTLE STAR.";
  char *P = "TWINKLE";

  brutesearch(P, T);
  kmpsearch(P, T);
  rksearch(P, T);
}