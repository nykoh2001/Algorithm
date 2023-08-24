#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
using uint = unsigned int;

class hash_map
{
  vector<list<int>> data;

public:
  hash_map(size_t n)
  {
    data.resize(n);
  }

  void insert(uint value)
  {
    size_t n = data.size();
    int key = value % n;

    data[key].push_back(value);
    cout << value << "을(를) 삽입했습니다." << endl;
  }

  bool find(uint value)
  {
    // lookup function
    size_t n = data.size();
    int key = value % n;

    // for (list<int>::iterator iter = data[key].begin(); iter != data[key].end(); iter++)
    // {
    //   if (*iter == value)
    //   {
    //     return true;
    //   }
    // }
    // return false;

    list<int> &entries = data[key];

    // 자체 호출이 아닌 std에 정의된 함수 호출
    return std::find(entries.begin(), entries.end(), value) != entries.end();
  }

  void erase(uint value)
  {
    size_t n = data.size();
    int key = value % n;

    list<int> &entries = data[key];
    remove_if(entries.begin(), entries.end(), [&value](int item)
              { 
                if (item == value){
                  cout << value << "을(를) 지웠습니다." << endl;
                }
                return item == value; });

    // list<int>::iterator iter = std::find(entries.begin(), entries.end(), value);
    // if (iter != entries.end())
    // {
    //   entries.erase(iter);
    //   cout << value << "을(를) 지웠습니다." << endl;
    // }
  }
};

int main()
{
  hash_map hm(7);

  auto print = [&](int value)
  {
    if (hm.find(value))
    {
      cout << "해시 맵에서 " << value << "을(를) 찾았습니다." << endl;
    }
    else
    {
      cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다." << endl;
    }
    cout << endl;
  };

  hm.insert(2);
  hm.insert(25);
  hm.insert(10);

  hm.insert(100);
  hm.insert(55);

  print(100);
  print(2);

  hm.erase(2);
  print(2);
}