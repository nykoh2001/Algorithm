#include <iostream>
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

void merge(itemType a[], int l, int mid, int r, int *_compare, int *_move, itemType *sorted)
{
  int i, j, k, n;
  i = l;
  j = mid + 1;
  k = l;
  while (i <= mid && j <= r)
  {
    (*_compare)++;
    if (a[i] <= a[j])
    {
      sorted[k++] = a[i++];
      (*_move)++;
    }
    else
    {
      sorted[k++] = a[j++];
      (*_move)++;
    }
  }
  if (i > mid)
    for (n = j; n <= r; n++)
    {
      sorted[k++] = a[n];
      (*_move)++;
    }
  else
    for (n = i; n <= mid; n++)
    {
      sorted[k++] = a[n];
      (*_move)++;
    }
  for (n = l; n <= r; n++)
  {
    a[n] = sorted[n];
    (*_move)++;
  }
}
void mergesort(itemType a[], int l, int r, int *_compare, int *_move, itemType *sorted)
{
  int mid;
  if (l < r)
  {
    mid = (l + r) / 2;
    mergesort(a, l, mid, _compare, _move, sorted);
    mergesort(a, mid + 1, r, _compare, _move, sorted);
    merge(a, l, mid, r, _compare, _move, sorted);
  }
}

int main()
{
  int N;
  cin >> N;

  itemType *sorted_A = new itemType[N];
  itemType *sorted_B = new itemType[N];
  itemType *A = new itemType[N];

  for (int i = 0; i <= N; i++)
  {
    A[i] = N - i;
  }
  itemType *B = return_B(N);

  int ca = 0, cb = 0, ma = 0, mb = 0;

  int *_compare_a = &ca;
  int *_move_a = &ma;

  int *_compare_b = &cb;
  int *_move_b = &mb;

  mergesort(A, 0, N - 1, _compare_a, _move_a, sorted_A);

  cout << "Sorted Data A: ";
  for (int i = 0; i < 20; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;

  mergesort(B, 0, N - 1, _compare_b, _move_b, sorted_B);

  cout << "Sorted Data B: ";
  for (int i = 0; i < 20; i++)
  {
    cout << B[i] << " ";
  }
  cout << endl;

  cout << "Compare Cnt A : " << *_compare_a << ", Move Cnt A : " << *_move_a << endl;
  cout << "Compare Cnt B : " << *_compare_b << ", Move Cnt B : " << *_move_b << endl;
}