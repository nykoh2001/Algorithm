#include <iostream>
#include <random>

using namespace std;
using itemType = int;
#define NONE -1;

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
  B[0] = NONE;
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

class MakeHeap
{
private:
  itemType *a;
  int N;

public:
  MakeHeap(int max)
  {
    a = new itemType[max];
    N = 0;
  }
  ~MakeHeap()
  {
    delete a;
  }
  void swap(itemType *a, int i, int j)
  {
    itemType temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }

  void makeHeap(itemType *a, int root, int last)
  {
    int parent, leftSon, rightSon, son;
    itemType rootValue;
    parent = root;
    rootValue = a[root];
    leftSon = 2 * root + 1;
    rightSon = leftSon + 1;
    while (leftSon < last)
    {
      if (rightSon <= last && a[leftSon] < a[rightSon])
      {
        son = rightSon;
      }
      else
      {
        son = leftSon;
      }
      if (rootValue < a[son])
      {
        a[parent] = a[son];
        parent = son;
        leftSon = son * 2 + 1;
        rightSon = leftSon + 1;
      }
      else
      {
        break;
      }
    }
    a[parent] = rootValue;
  }

  void heapSort(itemType *a, int N)
  {
    int i;
    for (i = N / 2; i >= 1; i--)
    {
      makeHeap(a, i - 1, N - 1);
    }
    for (i = N - 1; i >= 1; i--)
    {
      swap(a, 0, i);
      makeHeap(a, 0, i - 1);
    }
  }
};

void print(itemType *a, string name)
{
  cout << "sortedData " << name << " ";
  for (int i = 1; i <= 20; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  int A[N + 1];
  int *B;
  int C[N + 1];

  A[0] = NONE;
  for (int i = 0; i < N; i++)
  {
    A[i + 1] = N - i;
  }

  B = return_B(N);

  C[0] = NONE;
  for (int i = 1; i <= N; i++)
  {
    int rand = random() % N + 1;
    C[i] = rand;
  }

  MakeHeap mh = MakeHeap(N);
  mh.heapSort(A, N);
  mh.heapSort(B, N);
  mh.heapSort(C, N);

  print(A, "A");
  print(B, "B");
  print(C, "C");
}