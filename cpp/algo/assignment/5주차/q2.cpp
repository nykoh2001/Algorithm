#include <iostream>
#include <random>

using namespace std;
using itemType = int;

void sort(itemType **a, int N, itemType *B)
{
  int i, j;
  itemType v_0;
  itemType v_1;
  for (i = 0; i < N; i++)
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
    B[k + 1] = a[k][1];
  }
}

int *return_B(int N)
{
  itemType *B = new itemType[N + 1];

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

void CountSort(itemType *a, itemType *b, itemType *N, int n, int k, int *_compare, int *_move)
{
  int i, j;
  for (i = 1; i <= k; i++)
  {
    N[i] = 0;
    (*_move)++;
  }
  for (i = 1; i <= n; i++)
  {
    N[a[i]] = N[a[i]] + 1;
    (*_move)++;
  }
  for (i = 2; i <= k; i++)
  {
    N[i] = N[i] + N[i - 1];
    (*_move)++;
  }
  for (j = n; j >= 1; j--)
  {
    b[N[a[j]]] = a[j];
    N[a[j]] = N[a[j]] - 1;
    (*_move) += 2;
  }
}

void print(itemType *a, string name, int _cmp, int _move)
{
  cout << "sortedData: " << name << " ";
  for (int i = 1; i <= 20; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  cout << name << "의 비교 횟수 : " << _cmp << endl;
  cout << name << "의 자료 이동 횟수 : " << _move << endl;
}

int main()
{
  srand(time(NULL));
  int N;
  cin >> N;
  int A[N + 1];
  int *B;
  int C[N + 1];

  int N_A[N + 1];
  int N_B[N + 1];
  int B_A[N + 1];
  int B_B[N + 1];
  int B_C[N + 1];

  int _compare_a = 0, _compare_b = 0, _compare_c = 0;
  int _move_a = 0, _move_b = 0, _move_c = 0;
  int *ca, *cb, *cc, *ma, *mb, *mc;
  ca = &_compare_a;
  cb = &_compare_b;
  cc = &_compare_c;
  ma = &_move_a;
  mb = &_move_b;
  mc = &_move_c;

  for (int i = 0; i < N; i++)
  {
    A[i] = N - i;
  }

  B = return_B(N);

  int max_C = 0;
  for (int i = 0; i < N; i++)
  {
    int rand = random() % (N - 15) + 1;
    if (max_C < rand)
      max_C = rand;
    C[i] = rand;
  }
  int N_C[max_C + 1];

  CountSort(A, B_A, N_A, N, N, ca, ma);
  CountSort(B, B_B, N_B, N, N, cb, mb);
  CountSort(C, B_C, N_C, N, max_C, cc, mc);

  print(B_A, "A", _compare_a, _move_a);
  print(B_B, "B", _compare_b, _move_b);
  print(B_C, "C", _compare_c, _move_c);
}