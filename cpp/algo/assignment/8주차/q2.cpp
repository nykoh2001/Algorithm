#include <iostream>

using namespace std;

#define _min(x, y, z) min(x, min(y, z));

int **D = nullptr;
string **path = nullptr;

int EditDist(int n, string X, int m, string Y, int ins, int del, int chg)
{
  // n : X의 길이, m : Y의 길이, ins : 삽입비용, del : 삭제비용, chg : 변경비용
  D[0][0] = 0;
  int c;

  for (int i = 1; i < n + 1; i++)
  {
    D[i][0] = D[i - 1][0] + del; // 첫 열의 초기화
    path[i][0] = path[i - 1][0] + "D ";
  }
  for (int j = 1; j < m + 1; j++)
  {
    D[0][j] = D[0][j - 1] + ins; // 첫 행의 초기화
    path[0][j] = path[0][j - 1] + "I ";
  }

  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < m + 1; j++)
    {
      c = (X[i - 1] == Y[j - 1]) ? 0 : chg;

      int minimum = _min(D[i - 1][j] + del, D[i][j - 1] + ins, D[i - 1][j - 1] + c);
      D[i][j] = minimum;
      if (true
          // i > 1 && j > 1
      )
      {
        if (minimum == D[i - 1][j - 1] + c)
        {
          if (c)
            path[i][j] = path[i - 1][j - 1] + "C ";
          else
            path[i][j] = path[i - 1][j - 1] + "O ";
        }
        else if (minimum == D[i - 1][j] + del)
        {
          path[i][j] = path[i - 1][j] + "D ";
        }
        else if (minimum == D[i][j - 1] + ins)
        {
          path[i][j] = path[i][j - 1] + "I ";
        }
      }
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
  path = new string *[n + 1];
  for (int i = 0; i < n + 1; i++)
  {
    D[i] = new int[m + 1];
    path[i] = new string[m + 1];
  }

  int result = EditDist(n, x, m, y, ins, del, chg);

  cout << "편집거리 테이블" << endl;
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < m + 1; j++)
    {
      // cout << D[i][j] << " ";
      cout << path[i][j] << " ";
    }
    cout << endl;
  }

  cout << "편집거리 테이블" << endl;
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < m + 1; j++)
    {
      cout << D[i][j] << " ";
      // cout << path[i][j] << " ";
    }
    cout << endl;
  }

  cout << "-----------------------------" << endl;
  cout << "최소 비용 경로: " << path[n][m] << endl;

  for (int i = 0; i < n + 1; i++)
  {
    delete[] D[i];
    delete[] path[i];
  }
  delete[] D;
  delete[] path;
}