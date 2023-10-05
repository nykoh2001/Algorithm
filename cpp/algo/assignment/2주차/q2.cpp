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

class Queue
{
private:
  itemType *queue;
  int head;
  int tail;
  int size;

public:
  Queue(int max = 100)
  {
    queue = new itemType[max];
    head = 0;
    tail = 0;
    size = 100;
  }
  void put(itemType v);
  itemType get();
  int empty();
};

void Queue::put(itemType v)
{
  queue[tail++] = v;
  if (tail > size)
    tail = 0;
}
itemType Queue::get()
{
  itemType t = queue[head++];
  if (head > size)
    head = 0;
  return t;
}
int Queue::empty()
{
  return head == tail;
}

Queue queue = Queue(100);

void visit(struct treeNode *t)
{
  cout << t->info << " ";
}

void stack_traverse(struct treeNode *t)
{
  if (t != z)
  {
    stack_traverse(t->l);
    visit(t);
    stack_traverse(t->r);
  }
}
void traverse(struct treeNode *t)
{
  queue.put(t);
  while (!queue.empty())
  {
    t = queue.get();
    visit(t);
    if (t->l != z)
      queue.put(t->l);
    if (t->r != z)
      queue.put(t->r);
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
  itemType root = stack.pop();
  // stack_traverse(root);
  traverse(root);
  cout << endl;
}
