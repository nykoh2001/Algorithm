#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

/*
forward_list
1. 연결 리스트의 축약된 형태
2. 전방으로만 이동
3. 삽입/삭제 용이
*/

struct citizen
{
  string name;
  int age;
};

ostream &operator<<(ostream &os, const citizen &c)
{
  return (os << "[" << c.name << ", " << c.age << "]");
}

int main()
{
  forward_list<citizen> citizens = {
      {"Kim", 18},
      {"Koh", 23},
      {"Choi", 22},
      {"Jang", 16}};

  forward_list<citizen> copy_citizens = citizens; // deep copy

  cout << "전체 시민들:" << endl;
  for (const citizen &c : citizens)
  {
    cout << c << " ";
  }
  cout << endl;

  // remove_if 조건이 true이면 삭제
  citizens.remove_if([](const citizen &c)
                     { return (c.age < 19); });

  copy_citizens.remove_if([](const citizen &c)
                          { return (c.age != 18); });

  cout << "전체 시민들:" << endl;
  for (const citizen &c : citizens)
  {
    cout << c << " ";
  }
  cout << endl;

  cout << "전체 시민들:" << endl;
  for (const citizen &c : copy_citizens)
  {
    cout << c << " ";
  }
  cout << endl;

  // forward_list::sort
  // 1. < operator, 2. > operator
  forward_list<int> list = {23, 0, 1, -1, 9, -3};
  // O(nlogn)
  list.sort();
  list.sort(greater<int>());

  // O(n)
  list.reverse();
  list.unique();
  // 인접한 두 원소 비교
  list.unique([](int a, int b)
              { return b - a < 2; });
}