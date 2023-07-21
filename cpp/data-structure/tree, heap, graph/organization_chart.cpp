#include <iostream>
#include <queue>

using namespace std;

// 한 직원 당 최대 두 명의 부하 직원

struct node
{
  string position;
  node *first;
  node *second;
};

struct org_tree
{
  node *root;
  static org_tree create_tree(const string &pos)
  {
    org_tree tree;
    tree.root = new node{pos, NULL, NULL};
    return tree;
  }

  static node *find(node *root, const string &value)
  {
    // recursive
    if (root == NULL)
    {
      return NULL;
    }
    if (root->position == value)
    {
      return root;
    }
    // 왼쪽 서브 트리 먼저 검사
    node *first_found = org_tree::find(root->first, value);
    if (first_found != NULL)
    {
      return first_found;
    }
    // 없으면 오른쪽 서브 트리 검사
    return org_tree::find(root->second, value);
  }

  bool add_subordinate(const string &manager, const string &subordinate)
  {
    node *manager_node = org_tree::find(root, manager);
    if (!manager_node)
    {
      cout << manager << "를 찾을 수 없습니다." << endl;
      return false;
    }
    if (manager_node->first && manager_node->second)
    {
      cout << subordinate << "를 추가할 수 없습니다." << endl;
      return false;
    }
    if (!manager_node->first)
    {
      manager_node->first = new node{subordinate, NULL, NULL};
    }
    else
    {
      manager_node->second = new node{subordinate, NULL, NULL};
    }
    cout << manager << " 아래에 " << subordinate << "를 추가했습니다." << endl;
    return true;
  }
};

int main()
{
  org_tree organization_tree = org_tree::create_tree("CEO");
  organization_tree.add_subordinate("CEO", "부사장");
  organization_tree.add_subordinate("부사장", "IT부장");
  organization_tree.add_subordinate("부사장", "마케팅부장");
  organization_tree.add_subordinate("IT부장", "보안팀장");
  organization_tree.add_subordinate("IT부장", "앱개발팀장");
  organization_tree.add_subordinate("마케팅부장", "물류팀장");
  organization_tree.add_subordinate("마케팅부장", "홍보팀장");
  organization_tree.add_subordinate("부사장", "재무부장");
}