#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print(const unordered_set<int> &container)
{
  for (const int &element : container)
  {
    cout << element << " ";
  }
  cout << endl;
}

void print(const unordered_map<int, int> &container)
{
  for (const pair<int, int> &element : container)
  {
    cout << element.first << "-> " << element.second << ", ";
  }
  cout << endl;
}

void find(const unordered_set<int> &container, const int element)
{
  if (container.find(element) == container.end())
  {
    cout << element << " 검색: 실패" << endl;
  }
  else
  {
    cout << element << " 검색: 성공" << endl;
  }
}

void find(const unordered_map<int, int> &container, const int element)
{
  unordered_map<int, int>::const_iterator it = container.find(element);
  if (it == container.end())
  {
    cout << element << " 검색: 실패" << endl;
  }
  else
  {
    cout << element << " 검색: 성공" << endl;
  }
}

int main()
{
  cout << "*** unordered_set 예제 ***" << endl;
  unordered_set<int> us = {1, 2, 3, 4, 5};

  cout << "us 초기값: ";
  print(us);

  us.insert(2);
  cout << "2 삽입: ";
  print(us);

  us.insert(10);
  us.insert(300);
  cout << "10, 300 삽입: ";
  print(us);

  find(us, 4);
  find(us, 100);

  us.erase(2);
  cout << "2 삭제: ";
  print(us);

  find(us, 2);

  cout << "*** unordered_map 예제 ***" << endl;
  unordered_map<int, int> squareMap;

  squareMap.insert({2, 4});
  squareMap[3] = 9;
  cout << "2, 3의 제곱 삽입: ";
  print(squareMap);

  squareMap[20] = 400;
  squareMap[30] = 900;
  cout << "20, 30의 제곱 삽입: ";
  print(squareMap);

  find(squareMap, 10);
  find(squareMap, 20);
  cout << "squareMap[3] = " << squareMap[3] << endl;
  cout << "squareMap[100] = " << squareMap[100] << endl;
  print(squareMap);
}