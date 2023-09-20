#include <iostream>
#include <time.h>

using namespace std;
using itemType = int;

int _compare = 0;
int _move = 0;

void shellSort(itemType a[], int n)
{
  int i, j, h;
  itemType v;
  h = 1;
  do
  {
    h = 3 * h + 1;
    _compare++;
  } while (h < n);
  do
  {
    h = h / 3;
    for (i = h; i <= n; i++)
    {
      v = a[i];
      j = i;
      while (a[j - h] > v)
      {
        _compare++;
        a[j] = a[j - h];
        _move++;
        j -= h;
        _compare++;
        if (j <= h - 1)
          break;
      }
      _compare++;
      a[j] = v;
    }
    _compare++;
  } while (h > 1);
}

void sort(itemType **a, int N, itemType *B)
{
  int i, j;
  itemType v_0;
  itemType v_1;
  for (i = 2; i < N; i++)
  {
    v_0 = a[i][0];
    v_1 = a[i][1];
    j = i;
    while (j > 1 && a[j - 1][0] > v_0)
    {
      a[j][0] = a[j - 1][0];
      a[j][1] = a[j - 1][1];
      j--;
    }
    a[j][0] = v_0;
    a[j][1] = v_1;
  }
  for (int k = 0; k < N; k++)
  {
    B[k] = a[k][1];
  }
}

int main()
{
  int N;
  cin >> N;
  itemType *A = new itemType[N + 1];
  itemType *B = new itemType[N + 1];
  A[0] = -999999;
  B[0] = -999999;

  itemType **a = new itemType *[N];
  srand((unsigned)time(NULL)); // 현재시간을 이용해 난수발생기 rand()의 초기값을 재설정
  for (int i = 0; i < N; i++)
  {
    a[i] = new int[2];
    a[i][0] = (1 + rand() % N); // 1~n 사이의 숫자 n개를 랜덤하게 생성
    a[i][1] = i + 1;
  } // 난수가 만들어질 때마다 1씩 증가시켜가며 각 난수의 고유 인덱스를 생성
  sort(a, N, B);

  for (int i = 0; i < N; i++)
    delete[] a[i]; // a관련 메모리의 활용이 끝난 경우 이중 구조 메모리 해제
  delete[] a;

  for (int i = 1; i <= N; i++)
  {
    A[i] = N - i + 1;
  }

  shellSort(A, N);

  cout << "sorted data A: (20개까지 출력)";
  for (int i = 1; i <= 20; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
  cout << "A 비교 횟수: " << _compare << ", A 자료이동 연산 횟수: " << _move << endl;

  _compare = 0;
  _move = 0;

  shellSort(B, N);

  cout << endl
       << "sorted data B: (20개까지 출력)";
  for (int i = 1; i <= 20; i++)
  {
    cout << B[i] << " ";
  }
  cout << endl;

  cout << "B 비교 횟수: " << _compare << ", B 자료이동 연산 횟수: " << _move << endl;

  delete[] A;
  delete[] B;
}
