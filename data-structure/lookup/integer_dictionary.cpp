#include <iostream>
#include <vector>

using namespace std;

using uint = unsigned int;

class hash_map
{
  vector<int> data;

public:
  hash_map(size_t n)
  {
    data = vector<int>(n, -1);
  }

  void insert(int value)
  {
    int n = data.size();
    int key = value % n;

    data[key] = value;
    cout << value << "을(를) 삽입했습니다." << endl;
  }

  // lookup function
  bool find(uint value)
  {
    int n = data.size();
    int key = value % n;

    return data[key] == value;
  }

  void erase(uint value)
  {
    int n = data.size();
    int key = value % n;

    data[key] = -1;
    cout << value << "를 삭제했습니다." << endl;
  }
};

int main()
{
  hash_map hm(7);

  auto print = [&](int value)
  {
    if (hm.find(value))
    {
      cout << "hm에서 " << value << "를 찾았습니다." << endl;
    }
    else
    {
      cout << "hm에서 " << value << "를 찾지 못했습니다." << endl;
    }
  };

  hm.insert(2);
  hm.insert(25);
  hm.insert(10);

  print(25);

  hm.insert(100);
  print(100);
  print(2);

  hm.erase(25);
  print(25);
}