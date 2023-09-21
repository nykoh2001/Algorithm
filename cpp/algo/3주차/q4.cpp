#include <iostream>
#include <time.h>

using namespace std;
using itemType = int;

int insertion(itemType a[], int n)
{
  int i, j, _cost = 0;
  itemType v;
  for (i = 2; i <= n; i++)
  {
    v = a[i];
    _cost = _cost + a[i];
    j = i;
    while (a[j - 1] > v)
    {
      _cost = _cost + a[j - 1];
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
    _cost = _cost + a[i];
  }
  return _cost;
}

int shellSort(itemType a[], int n)
{
  int i, j, h, _cost = 0;
  itemType v;
  h = 1;
  do
  {
    h = 3 * h + 1;
  } while (h < n);
  do
  {
    h = h / 3;
    for (i = h; i <= n; i++)
    {
      v = a[i];
      j = i;
      _cost = _cost + a[i];
      while (a[j - h] > v)
      {
        _cost = _cost + a[j - h];
        a[j] = a[j - h];
        j -= h;
        if (j <= h - 1)
          break;
      }
      _cost = _cost + a[i];
      a[j] = v;
    }
  } while (h > 1);
  return _cost;
}

int bubbleSort(itemType a[], int n)
{
  int i, Sorted;
  Sorted = false;
  int _cost = 0;

  while (!Sorted)
  {
    Sorted = true;
    for (i = 1; i < n; i++)
    {
      int temp;
      itemType *a_i = &a[i];
      if (*(a_i - 1) > *a_i)
      {
        _cost = _cost + 2 * (*a_i) + *(a_i - 1);
        temp = *(a_i - 1);
        *(a_i - 1) = *a_i;
        *a_i = temp;
        Sorted = false;
      }
    }
  }

  return _cost;
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
  itemType *A1 = new itemType[N + 1];
  itemType *B1 = new itemType[N + 1];
  A1[0] = -999999;
  B1[0] = -999999;
  itemType *A2 = new itemType[N + 1];
  itemType *B2 = new itemType[N + 1];
  A2[0] = -999999;
  B2[0] = -999999;

  itemType **a = new itemType *[N];
  srand((unsigned)time(NULL)); // 현재시간을 이용해 난수발생기 rand()의 초기값을 재설정
  for (int i = 0; i < N; i++)
  {
    a[i] = new int[2];
    a[i][0] = (1 + rand() % N); // 1~n 사이의 숫자 n개를 랜덤하게 생성
    a[i][1] = i + 1;
  } // 난수가 만들어질 때마다 1씩 증가시켜가며 각 난수의 고유 인덱스를 생성
  sort(a, N, B);
  sort(a, N, B1);
  sort(a, N, B2);

  for (int i = 0; i < N; i++)
    delete[] a[i]; // a관련 메모리의 활용이 끝난 경우 이중 구조 메모리 해제
  delete[] a;

  for (int i = 1; i <= N; i++)
  {
    A[i] = N - i + 1;
    A1[i] = N - i + 1;
    A2[i] = N - i + 1;
  }

  int insertCostA = insertion(A, N);
  cout << "Insert Sort A: " << insertCostA << endl;

  int insertCostB = insertion(B, N);
  cout << "Insert Sort B: " << insertCostB << endl
       << endl;

  int bubbleCostA = bubbleSort(A1, N);
  cout << "Bubble Sort A: " << bubbleCostA << endl;

  int bubbleCostB = bubbleSort(B1, N);
  cout << "Bubble Sort B: " << bubbleCostB << endl
       << endl;

  int shellCostA = shellSort(A2, N);
  cout << "Shell Sort A: " << shellCostA << endl;

  int shellCostB = shellSort(B2, N);
  cout << "Shell Sort B: " << shellCostB << endl
       << endl;

  delete[] A;
  delete[] B;
}
