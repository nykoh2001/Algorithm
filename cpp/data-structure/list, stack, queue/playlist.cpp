#include <iostream>
#include <algorithm>

// circular doubly linked list

using namespace std;

struct circular_list_node
{
  string data;
  circular_list_node *next;
  circular_list_node *prev;
};
;

struct circular_list
{
public:
  using node = circular_list_node;
  using node_ptr = node *;

private:
  node_ptr head;
  node_ptr current = head;
  node_ptr tail;

public:
  struct circular_list_iterator
  {
  private:
    node_ptr iter;

  public:
    // 생성자
    circular_list_iterator(node_ptr iter) : iter(iter) {}

    string operator*()
    {
      return iter->data;
    }
    node_ptr get()
    {
      return iter;
    }

    circular_list_iterator operator++()
    {
      iter = iter->next;
      return *this;
    }
    circular_list_iterator operator++(int)
    {
      node_ptr result = this->iter;
      ++(*this);
      return result;
    }

    circular_list_iterator operator--()
    {
      iter = iter->prev;
      return *this;
    }
    circular_list_iterator operator--(int)
    {
      node_ptr result = this->iter;
      --(*this);
      return result;
    }

    friend bool operator==(const circular_list_iterator &iter1, const circular_list_iterator &iter2)
    {
      return iter1.iter == iter2.iter;
    }
    friend bool operator!=(const circular_list_iterator &iter1, const circular_list_iterator &iter2)
    {
      return iter1.iter != iter2.iter;
    }
  };
  circular_list_iterator begin() { return circular_list_iterator(head); }
  circular_list_iterator begin() const { return circular_list_iterator(head); }
  circular_list_iterator end() { return circular_list_iterator(tail); }
  circular_list_iterator end() const { return circular_list_iterator(tail); }

  circular_list() = default;
  circular_list(const circular_list &other) : head(NULL)
  {
    head = new node{0, NULL, NULL};
    tail = new node{"\0", head, head};
    head->prev = tail;
    head->next = tail;
    node_ptr current = head;
    circular_list_iterator iter = other.begin();
    while (true)
    {
      current->data = *iter;

      circular_list_iterator temp = iter;
      temp++;
      if (temp == other.end())
      {
        current->next = tail;
        break;
      }

      current->next = new node{0, NULL, current};
      current = current->next;
      cout << "현재 플레이 중인 곡: " << current->data << endl;
      iter = temp;
    }
  }
  circular_list(const initializer_list<string> &list) : head(NULL)
  {
    for (string str : list)
    {
      insert(str);
    }
  }
  node_ptr next()
  {
    current = current->next;
    if (current == tail)
      current = current->next;
    cout << "현재 플레이 중인 곡: " << current->data << endl;
    return current;
  }
  node_ptr previous()
  {
    current = current->prev;
    if (current == tail)
      current = current->prev;
    cout << "현재 플레이 중인 곡: " << current->data << endl;
    return current;
  }
  void print_all()
  {
    if (head == NULL)
    {
      cout << "Nothing" << endl;
    }
    for (circular_list_iterator iter = begin(); iter != end(); iter++)
    {
      cout << *iter << " ";
    }
    cout << endl;
  }
  void insert(string data)
  {
    node_ptr new_node = new node{data, NULL, NULL};
    if (head == NULL)
    {
      head = new_node;
      tail = new node{"\0", NULL, NULL};
      head->next = tail;
      head->prev = tail;
      current = head;
      cout << "현재 플레이 중인 곡: " << current->data << endl;
      tail->next = head;
      tail->prev = head;
    }
    else
    {
      new_node->next = current->next;
      new_node->prev = current;
      current->next->prev = new_node;
      current->next = new_node;
    }
  }
  void remove()
  {
    if (head != NULL)
    {
      if (head->next == tail)
      {
        delete head;
        delete tail;
      }
      // fix: 지우려는 대상이 current일 때
      else if (head == current)
      {
        node_ptr target = head;
        head = head->next;
        // head가 바뀔 때마다 prev를 tail과 연결
        head->prev = tail;
        tail->next = head;
        current = head;
        delete target;
      }
      else
      {
        node_ptr target = current;
        node_ptr after = current->next;
        node_ptr before = current->prev;
        before->next = after;
        after->prev = before;
        current = after;
        cout << "현재 플레이 중인 곡: " << current->data << endl;
        delete target;
      }
    }
  }
};

int main()
{
  circular_list cl = {"song 1", "song 2", "song 3"};
  cout << "첫번째 리스트: ";
  cl.print_all();

  cl.insert("something new1");
  cout << "두번째 리스트: ";
  cl.print_all();

  cl.remove();
  cout << "세번째 리스트: ";
  cl.print_all();

  cl.next();
  cl.next();
  cl.next();

  cl.previous();
  cl.previous();
}