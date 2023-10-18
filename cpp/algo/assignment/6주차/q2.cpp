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
  void BSTdelete(itemType v, int *_compare);
};

void BST::BSTdelete(itemType v, int *_compare)
{
  struct node *x = head->r, *p, *t, *c;
  p = head;
  while (++(*_compare) && x->key != v && ++(*_compare) && x != z)
  {
    p = x;
    x = (++(*_compare) && v < x->key) ? x->l : x->r;
  }
  if (++(*_compare) && x == z)
    return;
  else
    t = x;
  if (++(*_compare) && t->r == z)
    x = t->l;
  else if (++(*_compare) && t->r->l == z)
  {
    x = t->r;
    x->l = t->l;
  }
  else
  {
    c = x->r;
    while (++(*_compare) && c->l->l != z)
      c = c->l;
    x = c->l;
    c->l = x->r;
    x->l = t->l;
    x->r = t->r;
  }
  free(t);
  if (++(*_compare) && v < p->key)
    p->l = x;
  else
    p->r = x;
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

  std::mt19937 gen(rd());

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

  BST T2 = BST(N);

  for (int i = 0; i < N; i++)
  {
    T2.BSTinsert(random_array[i], infoNIL);
  }

  int cmp = 0;
  int *_compare = &cmp;

  for (int i = 0; i < N / 10; i++)
  {
    int rand_index = rand() % 10;
    T2.BSTdelete(random_array[10 * i + rand_index], _compare);
  }

  cout << double(cmp) / N << endl;
}
