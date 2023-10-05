#include <iostream>
// #include "create_b.h"
#define INF 2147483647

using namespace std;

using itemType = int;

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

int *return_B(int N)
{
  itemType *B = new itemType[N];

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
  return B;
}

inline void swap(itemType a[], int i, int j, int *_move)
{
  itemType t = a[i];
  a[i] = a[j];
  a[j] = t;
  (*_move) += 3;
}
int partition(itemType a[], int l, int r, int *_compare, int *_move)
{
  int i, j;
  itemType v;
  if (r > l)
  {
    (*_move)++;
    v = a[l];
    i = l;
    j = r + 1;
    for (;;)
    {
      while (++(*_compare) && a[++i] < v)
        ;
      while (++(*_compare) && a[--j] > v)
        ;
      if (i >= j)
        break;
      swap(a, i, j, _move);
    }
    swap(a, j, l, _move);
  }
  return j;
}

void quicksort(itemType a[], int l, int r, int *_compare, int *_move)
{
  int j;
  if (r > l)
  {
    j = partition(a, l, r, _compare, _move);
    quicksort(a, l, j - 1, _compare, _move);
    quicksort(a, j + 1, r, _compare, _move);
  }
}

int main()
{
  int N;
  cin >> N;
  itemType *A = new itemType[N + 1];

  for (int i = 0; i <= N; i++)
  {
    A[i] = N - i;
  }
  itemType *B = return_B(N);
  A[N] = INF;
  B[N] = INF;

  int ca = 0, cb = 0, ma = 0, mb = 0;

  int *_compare_a = &ca;
  int *_move_a = &ma;

  int *_compare_b = &cb;
  int *_move_b = &mb;

  quicksort(A, 0, N, _compare_a, _move_a);

  cout << "Sorted Data A: ";
  for (int i = 0; i < 20; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;

  quicksort(B, 0, N, _compare_b, _move_b);

  cout << "Sorted Data B: ";
  for (int i = 0; i < 20; i++)
  {
    cout << B[i] << " ";
  }
  cout << endl;

  cout << "Compare Cnt A : " << *_compare_a << ", Move Cnt A : " << *_move_a << endl;
  cout << "Compare Cnt B : " << *_compare_b << ", Move Cnt B : " << *_move_b << endl;
}