#include <iostream>
#include <algorithm>

using namespace std;

// linked list node
// data, next node pointer
struct singly_ll_node
{
  int data;
  singly_ll_node *next;
};

// linke list 전체
// singly_ll_node 로 구성
class singly_ll
{
  // singly_ll_node, singly_ll_node pointer 을 node, node_ptr로 사용
public:
  using node = singly_ll_node;
  using node_ptr = node *;

  // 가장 첫번째 노드
private:
  node_ptr head;

public:
  // push_front, pop_front - head만 고려
  void push_front(int val)
  {
    node_ptr new_node = new node{val, NULL};
    // 이렇게 head가 비어있는 예외를 고려해주자
    if (head != NULL)
      new_node->next = head;
    head = new_node;
  }
  int pop_front()
  {
    node_ptr first = head;
    int return_val = first->data;
    if (head != NULL)
    {
      head = head->next;
      delete first;
    }
    return return_val;
  }

  // linked list의 iterator 구조체 정의
  struct singly_ll_iterator
  {
  private:
    // 현재 node를 가리키는 iter
    node_ptr iter;

  public:
    // iterator 생성자 호출 -> iter를 p로 초기화
    singly_ll_iterator(node_ptr p) : iter(p) {}
    // 역참조 연산자, get
    int &operator*()
    {
      return iter->data;
    }
    node_ptr get()
    {
      return iter;
    }
    // 전위 증가 연산자
    singly_ll_iterator &operator++()
    {
      iter = iter->next;
      return *this;
    }
    // 후위 증가 연산자
    singly_ll_iterator operator++(int)
    {
      singly_ll_iterator result = *this;
      // iter = iter->next;
      // 관용적 표현
      ++(*this);
      return result;
    }

    // 두 객체 비교 연산 - friend method
    friend bool operator==(const singly_ll_iterator &iter1, const singly_ll_iterator &iter2)
    {
      return iter1.iter == iter2.iter;
    }

    friend bool operator!=(const singly_ll_iterator &iter1, const singly_ll_iterator &iter2)
    {
      return iter1.iter != iter2.iter;
    }
  };

  singly_ll_iterator begin() { return singly_ll_iterator(head); }
  singly_ll_iterator end() { return singly_ll_iterator(NULL); }
  singly_ll_iterator begin() const { return singly_ll_iterator(head); }
  singly_ll_iterator end() const { return singly_ll_iterator(NULL); }

  // 기본 생성자
  singly_ll() = default;
  // 깊은 복사 생성자
  singly_ll(const singly_ll &other) : head(NULL)
  {
    // 1. head 초기화
    head = new node{0, NULL};
    // 2. 현재 노드를 head에서 시작
    node_ptr current = head;
    // 3. 현재 iterator를 참조하는 연결 리스트의 시작 iterator로 초기화
    singly_ll_iterator iter = other.begin();

    while (true)
    {
      // 4. 현재 참조 값을 현재 노드 값에 대입
      current->data = *iter;

      // 5. 지금이 마지막 iterator인지 확인
      singly_ll_iterator temp = iter;
      temp++;
      if (temp == other.end())
      {
        break;
      }
      // 6. 새로운 노드 다음 노드로 연결
      current->next = new node{0, NULL};
      // 7. 다음 노드로 이동 & 증가한 iterator를 대입
      current = current->next;
      iter = temp;
    }
  }
  // data list 생성자
  singly_ll(const initializer_list<int> &list) : head(NULL)
  {
    for (reverse_iterator iter = rbegin(list); iter != rend(list); iter++)
    // std::reverse_iterator
    // push_front로 추가: 뒤에 요소부터 넣어야 함
    {
      push_front(*iter);
    }
  }
};