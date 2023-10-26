#include <iostream>

#define infoNIL 0
#define itemMIN -1
#define black 0
#define red 1

using namespace std;

using itemType = int;
using infoType = double;

void insert(itemType k, infoType info, int *cmp_rb);
void split(itemType k, int *cmp_rb);
struct node *rotate(itemType k, struct node *y);

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
  void BSTinsert(itemType item, infoType info, int *_compare);
  void inorder(node *current, BST T, int *cmp_bst, int *cmp_rb);
};

void BST::inorder(node *current, BST T, int *cmp_bst, int *cmp_rb)
{
  if (current == NULL)
    current = head->r;
  if (current == z)
    return;
  inorder(current->l, T, cmp_bst, cmp_rb);
  // cout << current->key << endl;
  T.BSTinsert(current->key, current->info, cmp_bst);
  insert(current->key, current->info, cmp_rb);

  inorder(current->r, T, cmp_bst, cmp_rb);
}

infoType BST::BSTsearch(itemType item, int *_compare)
{
  struct node *x = head->r;
  z->key = item;
  while (x->key != item)
    x = ((*_compare)++ && x->key > item) ? x->l : x->r;
  return x->info;
}

void BST::BSTinsert(itemType item, infoType info, int *_compare)
{
  struct node *p, *x;
  p = head;
  x = head->r;
  while (x != z)
  {
    p = x;
    x = ((*_compare)++ && x->key < item) ? x->r : x->l;
  }
  x = new node(item, info, z, z);
  if ((*_compare)++ && p->key < item)
  {
    p->r = x;
  }
  else
  {
    p->l = x;
  }
}

struct node
{
  itemType key, tag;
  infoType Info;
  struct node *l, *r;
  node(itemType k, infoType i, itemType t, struct node *ll, struct node *rr)
  {
    key = k;
    Info = i;
    tag = t;
    l = ll;
    r = rr;
  }
};

struct node *head, *tail, *x, *p, *g, *gg, *z;
void RBtree(int max)
{
  z = new node(0, infoNIL, black, 0, 0);
  z->l = z;
  z->r = z;
  head = new node(itemMIN, infoNIL, black, z, z);
}
void insert(itemType k, infoType info, int *cmp_rb)
{
  x = head;
  p = head;
  g = head;
  while (x != z)
  {
    gg = g;
    g = p;
    p = x;
    x = ((*cmp_rb)++ && k < x->key) ? x->l : x->r;
    if (x->l->tag && x->r->tag)
      split(k, cmp_rb);
  }
  x = new node(k, info, red, z, z);
  if ((*cmp_rb)++ && k < p->key)
    p->l = x;
  else
    p->r = x;
  split(k, cmp_rb);
  head->r->tag = black;
}

struct node *rotate(itemType k, struct node *y, int *cmp_rb)
{
  struct node *high, *low;
  high = ((*cmp_rb)++ && k < y->key) ? y->l : y->r;
  if ((*cmp_rb)++ && k < high->key)
  {
    low = high->l;
    high->l = low->r;
    low->r = high;
  }
  else
  {
    low = high->r;
    high->r = low->l;
    low->l = high;
  }
  if ((*cmp_rb)++ && k < y->key)
    y->l = low;
  else
    y->r = low;
  return low;
}
void split(itemType k, int *cmp_rb)
{
  x->tag = red;
  x->l->tag = black;
  x->r->tag = black;
  if (p->tag)
  {
    g->tag = red;
    if (((*cmp_rb)++ && k < g->key) != ((*cmp_rb)++ && k < p->key))
      p = rotate(k, g, cmp_rb);
    x = rotate(k, gg, cmp_rb);
    x->tag = black;
  }
}
infoType search(itemType k, int *_compare)
{
  struct node *current = head->r;

  while (current != z)
  {
    if ((*_compare)++ && k == current->key)
    {
      return current->Info;
    }
    else if ((*_compare)++ && k < current->key)
    {
      current = current->l;
    }
    else
    {
      current = current->r;
    }
  }

  return infoNIL;
}

int main()
{

  int N;
  cin >> N;

  int *random_array = new int[N];
  random_array = return_B(N);

  BST T1 = BST(N);
  BST T2 = BST(N);
  RBtree(N);

  int cmp_1 = 0;
  int *_compare1 = &cmp_1;
  int cmp_2 = 0;
  int *_compare2 = &cmp_2;
  int cmp_3 = 0;
  int *_compare3 = &cmp_3;

  for (int i = 0; i < N; i++)
  {
    T1.BSTinsert(random_array[i], infoNIL, _compare1);
  }

  T1.inorder(NULL, T2, _compare2, _compare3);

  cout << "T1 구축 비교 횟수: " << double(cmp_1) / N << endl;
  cout << "T2 구축 비교 횟수: " << double(cmp_2) / N << endl;
  cout << "T3 구축 비교 횟수: " << double(cmp_3) / N << endl
       << endl;

  cmp_1 = 0;
  cmp_2 = 0;
  cmp_3 = 0;

  for (int i = 0; i < N; i++)
  {
    T1.BSTsearch(random_array[i], _compare1);
  }

  for (int i = 0; i < N; i++)
  {
    T2.BSTsearch(random_array[i], _compare2);
  }

  for (int i = 0; i < N; i++)
  {
    search(random_array[i], _compare3);
  }

  cout << "T1 탐색 비교 횟수: " << double(cmp_1) / N << endl;
  cout << "T2 탐색 비교 횟수: " << double(cmp_2) / N << endl;
  cout << "T3 탐색 비교 횟수: " << double(cmp_3) / N << endl;
}
