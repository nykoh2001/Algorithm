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

typedef struct node *node_pointer;
typedef struct node
{
  itemType value;
  node_pointer next;
};
node_pointer TABLE[10], x, z, temp;
void radixSort(itemType *a, int n, int *_compare, int *_move)
{
  int i, j, cnt, radix, radix_mod = 10, cipher = 0;
  i = n;
  while (i > 0)
  {
    i = i / 10;
    cipher++;
  } // cipher : 입력 데이터의 자리수 (ex. 450 -> 3)
  for (i = 0; i < cipher; i++)
  {
    for (j = 0; j < n; j++)
    {
      cnt = 0;
      radix = (a[j] % radix_mod) / (radix_mod / 10);
      /* radix_mod = 10 이면 radix는 a[j]의 일의 자리수
     radix_mod = 100 이면 radix는 a[j]의 십의 자리수 */
      temp = new node;
      temp->value = a[j];
      (*_move)++;
      temp->next = z;
      (*_move)++;
      if (TABLE[radix] == z)
      {
        // z는 list의 끝을 확인하기 위한 노드 포인터 (NULL에 해당)
        TABLE[radix] = temp;
        (*_move)++;
      }
      else
      {
        x = TABLE[radix];
        (*_move)++;
        while ((*_compare)++ && x->next != z)
        {
          x = x->next;
          (*_move)++;
        }
        x->next = temp;
        (*_move)++;
      }
    }

    for (j = 0; j < 10; j++)
    {
      if ((*_compare)++ && TABLE[j] != z)
      {
        x = TABLE[j];
        (*_move)++;
        while ((*_compare)++ && x != z)
        {
          a[cnt++] = x->value;
          (*_move)++;
          temp = x; // 메모리에서 노드를 삭제하기 위해 임시 저장
          (*_move)++;
          x = x->next;
          (*_move)++;
          delete temp; // 배열에 이미 넣은 노드를 메모리에서 삭제
        }
      }
      TABLE[j] = z;
      (*_move)++;
    }
    radix_mod *= 10;
  }
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

  int max_C = 0;
  for (int i = 0; i < N; i++)
  {
    int rand = random() % N + 1;
    if (max_C < rand)
      max_C = rand;
    C[i] = rand;
  }

  radixSort(A, N, ca, ma);
  radixSort(B, N, cb, mb);
  radixSort(C, N, cc, mc);

  print(A, "A", _compare_a, _move_a);
  print(B, "B", _compare_b, _move_b);
  print(C, "C", _compare_c, _move_c);
}