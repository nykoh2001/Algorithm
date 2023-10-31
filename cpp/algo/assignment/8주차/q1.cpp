#include <iostream>

using namespace std;

#define _min(x, y, z) min(x, min(y, z));

int **D = nullptr;

int EditDist(int n, string X, int m, string Y, int ins, int del, int chg)
{
  // n : X의 길이, m : Y의 길이, ins : 삽입비용, del : 삭제비용, chg : 변경비용
  D[0][0] = 0;
  int c;

  for (int i = 1; i < n + 1; i++)
    D[i][0] = D[i - 1][0] + del; // 첫 열의 초기화
  for (int j = 1; j < m + 1; j++)
    D[0][j] = D[0][j - 1] + ins; // 첫 행의 초기화

  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < m + 1; j++)
    {
      c = (X[i - 1] == Y[j - 1]) ? 0 : chg;
      D[i][j] = _min(D[i - 1][j] + del, D[i][j - 1] + ins, D[i - 1][j - 1] + c);
    }
  }
  return D[n][m];
}

int main()
{
  string x, y;
  cout << "초기 문자열을 입력하시오: ";
  cin >> x;
  cout << "목표 문자열을 입력하시오: ";
  cin >> y;
  cout << endl;

  int ins = 1, del = 1, chg = 2;
  int n = x.length();
  int m = y.length();

  D = new int *[n + 1];
  for (int i = 0; i < n + 1; i++)
  {
    D[i] = new int[m + 1];
  }

  int result = EditDist(n, x, m, y, ins, del, chg);

  cout << "편집거리 테이블" << endl;
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < m + 1; j++)
    {
      cout << D[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < n + 1; i++)
  {
    delete[] D[i];
  }
  delete[] D;

  cout << "-----------------------------" << endl;
  cout << "최소 편집 비용: " << result << endl;
}