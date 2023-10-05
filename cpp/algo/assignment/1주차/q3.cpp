#include <iostream>

using namespace std;

using itemType = double;

class Stack2
{
public:
  Stack2()
  {
    head = NULL;
  };
  ~Stack2(){};
  void push(itemType v)
  {
    if (head == NULL)
    {
      head = new node{v, NULL};
      return;
    }
    node *new_node = new node{v, NULL};
    node *current_node = head;

    while (current_node->next != NULL)
    {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  };
  itemType pop()
  {
    if (head == NULL)
    {
      cout << "stack is empty";
      return -1;
    }
    node *current_node = head;
    while (current_node->next != NULL)
    {
      z = current_node;
      current_node = current_node->next;
    }
    itemType val = current_node->key;
    z->next = NULL;
    if (current_node == head)
    {
      head = NULL;
    }
    delete current_node;
    return val;
  };
  int empty()
  {
    if (head == NULL)
    {
      return 1;
    }
    return 0;
  };

private:
  struct node
  {
    itemType key;
    struct node *next;
  };
  struct node *head, *z;
};

int main()
{
  char c;
  Stack2 stack;
  itemType x;
  while ((c = cin.get()) != '\n')
  {
    x = 0;
    while (c == ' ')
    {
      cin.get(c);
    }
    if (c == '+')
    {
      itemType x_1 = stack.pop();
      itemType x_2 = stack.pop();
      x = x_1 + x_2;
    }
    if (c == '*')
    {
      x = stack.pop() * stack.pop();
    }
    if (c == '/')
    {
      double x_1 = stack.pop();
      double x_2 = stack.pop();
      x = x_2 / x_1;
    }
    if (c == '-')
    {
      double x_1 = stack.pop();
      double x_2 = stack.pop();
      x = x_2 - x_1;
    }
    while (c >= '0' && c <= '9')
    {
      x = 10 * x + (c - '0');
      cin.get(c);
    }
    stack.push(x);
  }
  double result = stack.pop();
  if (result == double(int(result)))
  {
    cout << result << endl;
  }
  else
    cout << double(floor(result * 100)) / 100 << '\n';
}
