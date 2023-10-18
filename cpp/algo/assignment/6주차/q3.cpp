#include <iostream>
#include <random>

#define infoNIL 0.0
#define itemMIN -999999

using namespace std;
using itemType = int;
using infoType = double;

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
  random_device rd;

  mt19937 gen(rd());

  uniform_int_distribution<int> dis(1, 30000);

  int N;
  cin >> N;
  // int *random_array = create_random_array(N);
  int *random_array = new int[N];
  for (int i = 0; i < N; i++)
  {
    random_array[i] = dis(gen);
    for (int j = 0; j < i; j++)
    {
      if (random_array[j] == random_array[i])
      {
        i--;
        break;
      }
    }
  }

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
