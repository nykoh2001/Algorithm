#include <iostream>

using namespace std;

struct treeNode
{
  char info;
  struct treeNode *l, *r;
};

using itemType = treeNode *;

struct treeNode *x, *z;

class Stack
{
public:
  Stack(int max = 100)
  {
    stack = new itemType[max];
    p = 0;
  };
  ~Stack()
  {
    delete stack;
  };
  inline void push(itemType v)
  {
    itemType new_node = new treeNode{v->info, v->l, v->r};
    stack[p] = new_node;
    p++;
  };
  inline itemType pop()
  {
    itemType val = stack[p - 1];
    p--;
    return val;
  };
  inline int empty()
  {
    if (p == 0)
    {
      return 1;
    }
    return 0;
  };

private:
  itemType *stack;
  int p;
};

void visit(struct treeNode *t)
{
  cout << t->info << " ";
}
void traverse(struct treeNode *t)
{
  if (t != z)
  {
    traverse(t->l);
    visit(t);
    traverse(t->r);
  }
}

int main()
{
  char c;
  Stack stack(50);
  z = new treeNode;
  z->l = z;
  z->r = z;
  cout << "입력: ";
  while ((c = cin.get()) != '\n')
  {
    while (c == ' ')
      cin.get(c);
    x = new treeNode;
    x->info = c;
    x->l = z;
    x->r = z;
    if (c == '+' || c == '*' || c == '-')
    {
      x->r = stack.pop();
      x->l = stack.pop();
    }
    stack.push(x);
  }
  cout << "출력: ";
  traverse(stack.pop());
  cout << endl;
  return 0;
}
