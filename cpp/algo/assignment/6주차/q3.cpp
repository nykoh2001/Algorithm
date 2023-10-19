#include <iostream>
#include <random>

#define infoNIL 0.0
#define itemMIN -999999

using namespace std;
using itemType = int;
using infoType = double;

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

class BST
{
private:
  struct node
  {
    itemType key;
    infoType info;
    struct node *l, *r;
    node(itemType key, infoType info, node *l, node *r)
    {
      this->key = key;
      this->info = info;
      this->l = l;
      this->r = r;
    }
  };
  struct node *head, *z;

public:
  BST(int max)
  {
    z = new node(itemMIN, infoNIL, NULL, NULL);
    head = new node(0, infoNIL, z, z);
  }
  ~BST(){};
  infoType BSTsearch(itemType item, int *_compare);
  void BSTinsert(itemType item, infoType info);
  void inorder(node *current, BST T3);
};

void BST::inorder(node *current, BST T3)
{
  if (current == NULL)
    current = head->r;
  if (current == z)
    return;
  inorder(current->l, T3);
  // cout << current->key << endl;
  T3.BSTinsert(current->key, current->info);
  inorder(current->r, T3);
}

infoType BST::BSTsearch(itemType item, int *_compare)
{
  struct node *x = head->r;
  z->key = item;
  while (x->key != item)
    x = ((*_compare)++ && x->key > item) ? x->l : x->r;
  return x->info;
}

void BST::BSTinsert(itemType item, infoType info)
{
  struct node *p, *x;
  p = head;
  x = head->r;
  while (x != z)
  {
    p = x;
    x = (x->key < item) ? x->r : x->l;
  }
  x = new node(item, info, z, z);
  if (p->key < item)
  {
    p->r = x;
  }
  else
  {
    p->l = x;
  }
}

int main()
{

  int N;
  cin >> N;
  // int *random_array = create_random_array(N);
  int *random_array = new int[N];
  random_array = return_B(N);

  BST T1 = BST(N);
  BST T3 = BST(N);

  for (int i = 0; i < N; i++)
  {
    T1.BSTinsert(random_array[i], infoNIL);
  }

  int cmp_1 = 0;
  int *_compare1 = &cmp_1;
  int cmp_3 = 0;
  int *_compare3 = &cmp_3;

  T1.inorder(NULL, T3);

  for (int i = 0; i < N; i++)
  {
    T1.BSTsearch(random_array[i], _compare1);
  }

  for (int i = 0; i < N; i++)
  {
    T3.BSTsearch(random_array[i], _compare3);
  }

  cout << "T1의 탐색 평균 비교 횟수: " << double(cmp_1) / N << endl;
  cout << "T3의 탐색 평균 비교 횟수: " << double(cmp_3) / N << endl;
}
