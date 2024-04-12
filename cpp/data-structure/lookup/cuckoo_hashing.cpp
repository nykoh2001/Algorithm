#include <iostream>
#include <vector>

using namespace std;

class hash_map
{
  vector<int> data1;
  vector<int> data2;
  int size;

  int hash1(int key) const
  {
    return key % size;
  }
  int hash2(int key) const
  {
    return (key / size) % size;
  }

public:
  hash_map(int n) : size(n)
  {
    data1 = vector<int>(size, -1);
    data2 = vector<int>(size, -1);
  }

  vector<int>::iterator lookup(int key)
  {
    int hash_value1 = hash1(key);
    if (data1[hash_value1] == key)
    {
      cout << "1번 테이블에서 " << key << "을(를) 찾았습니다." << endl;
      return data1.begin() + hash_value1;
    }

    int hash_value2 = hash2(key);
    if (data2[hash_value2] == key)
    {
      cout << "2번 테이블에서 " << key << "을(를) 찾았습니다." << endl;
      return data2.begin() + hash_value2;
    }
    return data2.end();
  }

  void erase(int key)
  {
    vector<int>::iterator position = lookup(key);
    if (position != data2.end())
    {
      *position = -1;
      cout << key << "에 해당하는 원소를 삭제했습니다." << endl;
    }
    else
    {
      cout << key << "을(를) 찾지 못했습니다." << endl;
    }
  }

  void print()
  {
    cout << "Index: ";
    for (int i = 0; i < size; i++)
    {
      cout << i << "\t";
    }
    cout << endl;

    cout << "Data1: ";
    for (int i : data1)
    {
      cout << i << "\t";
    }
    cout << endl;

    cout << "Data2: ";
    for (int i : data2)
    {
      cout << i << "\t";
    }
    cout << endl;
  }

  void insert(int key)
  {
    insert_impl(key, 0, 1);
  }

private:
  void insert_impl(int key, int cnt, int table)
  {
    // cnt: 재귀 호출 횟수
    // 각 해시 테이블의 크기를 최대 재귀 호출 횟수로 설정 => 성능 보장
    int hash = (table == 1) ? hash1(key) : hash2(key);
    vector<int> &data = (table == 1) ? data1 : data2;
    if (cnt >= size)
    {
      cout << "삽입 시 순환 발생, 재해싱 필요" << endl;
      return;
    }

    if (data[hash] == -1)
    {
      cout << table << "번 테이블에 " << key << " 삽입" << endl;
      data[hash] = key;
    }
    else
    {
      int origin = data[hash];
      data[hash] = key;
      cout << table << "번 테이블에 " << key << " 삽입: 기존의 " << origin << " 이동 -> ";
      // 이젠 원래 있던 origin을 삽입하므로 key 대신 origin 전달
      insert_impl(origin, cnt + 1, table % 2 + 1);
    }
  }
};

int main()
{
  hash_map hm(7);
  hm.print();
  cout << endl;

  hm.insert(10);
  hm.insert(20);
  hm.insert(30);
  cout << endl;

  hm.insert(104);
  hm.insert(2);
  hm.insert(70);
  hm.insert(9);
  hm.insert(90);
  hm.insert(2);
  hm.insert(7);
  cout << endl;

  hm.print();
  cout << endl;

  hm.insert(14);
}