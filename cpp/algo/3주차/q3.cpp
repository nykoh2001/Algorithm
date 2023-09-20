#include <iostream>
#include <time.h>

using namespace std;
using itemType = int;

int _compare = 0;
int _move = 0;

int Bubble(int sorted, itemType *a, int n)
{
  int temp;
  _compare++;
  if (*(a - 1) > *a)
  {
    _move += 3;
    temp = *(a - 1);
    *(a - 1) = *a;
    *a = temp;
    sorted = false;
  }
  return sorted;
}

void bubbleSort(itemType a[], int n)
{
  int i, Sorted;
  Sorted = false;
  while (!Sorted)
  {
    Sorted = true;
    for (i = 1; i < n; i++)
      Sorted = Bubble(Sorted, &a[i], n);
  }
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

  bubbleSort(A, N);

  cout << "sorted data A: (20개까지 출력)";
  for (int i = 1; i <= 20; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
  cout << "A 비교 횟수: " << _compare << ", A 자료이동 연산 횟수: " << _move << endl;

  _compare = 0;
  _move = 0;

  bubbleSort(B, N);

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
