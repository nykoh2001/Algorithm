#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int *SP; // SP에 대한 메모리는 p의 크기만큼 동적 할당 해야한다.
void initSP(string p);
int index(char c);

int *skip; // SP와 같은 크기로 동적 할당해 주어야함
const int alphabet_count = 26;
int lp[26] = {
    0,
};
void LastPos(string p);
void GoodSuffix(string p);

void BoyerMoore(string p, string a)
{
  cout << "Boyer Moore: ";
  int i, j, m = p.size(), n = a.size();
  int cnt = 0;
  LastPos(p);
  GoodSuffix(p);
  j = 0;
  while (j <= n - m)
  {
    cnt++;
    for (i = m - 1; i >= 0 && p[i] == a[j + i]; i--)
      cnt++;
    if (i == -1)
    {
      // printf(" 패턴위치 : % d ", j);
      cout << j << ", ";
      j = j + skip[-1];
      continue;
    }
    else
    {
      j = j + max(skip[i], i - lp[index(a[j + i])]);
    }
  }

  cout << cnt << '\n';
}

void LastPos(string p)
{
  for (int i = 0; i < alphabet_count; i++)
    lp[i] = -1;
  for (int i = 0; i < p.size(); i++)
    lp[index(p[i])] = i;
}

void GoodSuffix(string p)
{
  int i, k, m = p.size();
  char *r_p = new char[m];
  for (i = 0; i < m; i++)
  {
    r_p[m - i - 1] = p[i];
  }
  initSP(r_p);
  for (i = -1; i <= m - 1; i++)
    skip[i] = m - 1 - SP[m - 1];
  for (k = 0; k <= m - 1; k++)
  {
    i = m - 1 - SP[k] - 1;
    if (skip[i] > k - SP[k])
      skip[i] = k - SP[k];
  }
}

int brutesearch(string p, string a, int cnt = 0)
{ // p : Pattern String, a : Text String
  int i, j, n = p.size(), m = a.size();
  // if (n > m) return;
  for (i = 0; i <= m - n; i++)
  {
    for (j = 0; j < n; j++)
    {
      cnt++;
      if (a[i + j] != p[j])
        break;
    }
    if (j == n)
    { // 결과값 출력
      cout << i << ", ";
    }
  }
  return cnt;
}

int kmpsearch(string p, string a, int cnt = 0)
{
  int i, j, m = p.size(), n = a.size();
  initSP(p);
  for (i = 0, j = -1; i <= n - 1; i++)
  {
    while ((j >= 0) && (p[j + 1] != a[i]))
    {
      j = SP[j];
      cnt++;
    }
    if (p[j + 1] == a[i])
    {
      j++;
      cnt++;
    }
    if (j == m - 1)
    {
      // 결과값 출력
      cout << (i - m + 1) << ", ";
      j = SP[j];
    }
  }
  return cnt;
}

void initSP(string p)
{
  int i, j, m = p.size();
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

int index(char c)
{
  return (int)c - 65;
}

int main()
{
  string pattern, text;
  getline(cin, text);
  getline(cin, pattern);

  SP = new int[pattern.size() + 2400];
  skip = new int[pattern.size() + 2400];
  cout << "Brute Force: " << brutesearch(pattern, text, 0) << '\n';
  cout << "KMP: " << kmpsearch(pattern, text, 0) << '\n';
  BoyerMoore(pattern, text);

  delete[] SP, skip;
  return 0;
}