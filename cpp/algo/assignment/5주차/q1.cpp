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
  void swap(itemType *a, int i, int j, int *_move)
  {
    itemType temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    (*_move) += 3;
  }

  void makeHeap(itemType *a, int root, int last, int *_compare, int *_move)
  {
    int parent, leftSon, rightSon, son;
    itemType rootValue;
    parent = root;
    rootValue = a[root];
    (*_move)++;
    leftSon = 2 * parent + 1;
    rightSon = leftSon + 1;
    while (leftSon <= last)
    {
      if ((*_compare)++ && rightSon <= last && a[leftSon] < a[rightSon])
      {
        son = rightSon;
      }
      else
      {
        son = leftSon;
      }
      if ((*_compare)++ && rootValue < a[son])
      {
        a[parent] = a[son];
        (*_move)++;
        parent = son;
        leftSon = parent * 2 + 1;
        rightSon = leftSon + 1;
      }
      else
      {
        break;
      }
    }
    a[parent] = rootValue;
    (*_move)++;
  }

  void heapSort(itemType *a, int N, int *_compare, int *_move)
  {
    int i;
    for (i = N / 2; i >= 0; i--)
    {
      makeHeap(a, i, N - 1, _compare, _move);
    }
    for (i = N - 1; i >= 1; i--)
    {
      swap(a, 0, i, _move);
      makeHeap(a, 0, i - 1, _compare, _move);
    }
  }
};

void print(itemType *a, string name, int _cmp, int _move)
{
  cout << "sortedData: " << name << " ";
  for (int i = 0; i < 20; i++)
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
  int A[N];
  int *B;
  int C[N];

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

  for (int i = 0; i < N; i++)
  {
    int rand = random() % N + 1;
    C[i] = rand;
  }

  MakeHeap mh = MakeHeap(N);
  mh.heapSort(A, N, ca, ma);
  mh.heapSort(B, N, cb, mb);
  mh.heapSort(C, N, cc, mc);

  print(A, "A", _compare_a, _move_a);
  print(B, "B", _compare_b, _move_b);
  print(C, "C", _compare_c, _move_c);
}