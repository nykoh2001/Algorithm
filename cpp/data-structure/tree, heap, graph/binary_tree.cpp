#include <iostream>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

class binary_tree
{

  node *root;

  binary_tree(node *root)
  {
    this->root = root;
  }

  node *find(int data)
  {
    // node *current = this->root;
    // if (!current)
    // {
    //   return NULL;
    // }
    // int value = current->data;
    // if (value == data)
    // {
    //   cout << data << " 찾음" << endl;
    //   return current;
    // }
    // else if (value < data)
    // {
    //   current = current->right;
    //   cout << "오른쪽으로 이동" << endl;
    //   return find(current->data);
    // }
    // else
    // {
    //   current = current->left;
    //   cout << "왼쪽으로 이동" << endl;
    //   return find(current->data);
    // }
    return find_impl(this->root, data);
  }

private:
  node *find_impl(node *current, int data)
  {
    if (!current)
    {
      return NULL;
    }
    int value = current->data;
    if (value == data)
    {
      cout << data << " 반환" << endl;
      return current;
    }
    else if (value < data)
    {
      cout << "오른쪽으로 이동" << endl;
      return find_impl(current->right, data);
    }
    else
    {
      cout << "왼쪽으로 이동" << endl;
      return find_impl(current->left, data);
    }
  }
  void insert_impl(node *current, int value)
  {
    if (current->data < value)
    {
      if (!current->left)
      {
        current->left = new node{value, NULL, NULL};
      }
      else
      {
        insert_impl(current->left, value);
      }
    }
    if (current->data > value)
    {
      if (!current->right)
      {
        current->right = new node{value, NULL, NULL};
      }
      else
      {
        insert_impl(current->right, value);
      }
    }
  }

  void inorder_impl(node *current)
  {
    if (!current)
    {
      return;
    }

    inorder_impl(current->left);
    cout << current->data << endl;
    inorder_impl(current->right);
  }
  node *delete_impl(node *current, int value)
  {
    if (!current)
    {
      return;
    }
    if (value < current->data)
    {
      current->left = delete_impl(current->left, value);
    }
    else if (value > current->data)
    {
      current->right = delete_impl(current->right, value);
    }
    else
    {
      if (!current->left)
      {
        // 자식이 아예 없는 경우: current를 지우는 동작과 동일
        // 왼쪽 자식만 없는 경우: 바로 오른쪽 자식이 후속
        node *tmp = current->right;
        delete current;
        return tmp;
      }
      if (!current->right)
      {
        // 오른쪽 자식만 없는 경우: 바로 왼쪽 자식이 후속
        node *tmp = current->left;
        delete current;
        return tmp;
      }

      // 현재 값보다 큰 값 중에서 가장 작은 값을 갖는 자식을 후속으로 정의
      node *successNode = successor(current);

      // 후속 노드 값으로 교체
      current->data = successNode->data;

      // 남아있는 나머지 후속 노드 제거
      current->right = delete_impl(current->right, successNode->data);
    }
  }

public:
  void insert(int value)
  {
    if (!root)
    {
      root = new node{value, NULL, NULL};
    }
    else
      insert_impl(root, value);
  }
  void inorder()
  {
    inorder_impl(root);
  }
  node *successor(node *start)
  {
    node *current = start->right;
    while (current && current->left)
    {
      current = current->left;
    }
    return current;
  }
  void deleteValue(int value)
  {
    root = delete_impl(root, value);
  }
};