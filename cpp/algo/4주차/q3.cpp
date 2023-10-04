#include <iostream>
#include <fstream>

using namespace std;

class KVS
{
private:
  string _key;
  int _value;

public:
  KVS() {}
  KVS(string key, int value)
  {
    this->_key = key;
    this->_value = value;
  }
  string key()
  {
    return this->_key;
  }
  int value()
  {
    return this->_value;
  }
  void set_key(string key)
  {
    this->_key = key;
  }
  void set_value(int value)
  {
    this->_value = value;
  }
};

class Dictionary
{
private:
  KVS(*dictionary)
  [100] = new KVS[144][100];

  int hash(string key)
  {
    int _key = key[0];
    return _key + 22;
  }

public:
  void print()
  {
    for (int i = 0; i < 144; i++)
    {
      KVS *bucket = dictionary[i];
      for (int j = 0; j < 100; j++)
      {
        if (bucket[j].value() > 0)
        {
          cout << bucket[j].key() << " : " << bucket[j].value() << endl;
        }
        else
        {
          break;
        }
      }
    }
  }
  int get_value(string key)
  {
    int _key = (wchar_t)hash(key);
    KVS *bucket = dictionary[_key];
    for (int i = 0; i < 100; i++)
    {
      if (bucket[i].key() == key)
      {
        return bucket[i].value();
      }
    }
    return -1;
  }
  void add_value(string key)
  {
    int _key = hash(key);
    KVS *bucket = dictionary[_key];
    int value = get_value(key);
    if (value < 0)
    {
      for (int i = 0; i < 100; i++)
      {
        if (bucket[i].value() == 0)
        {
          bucket[i].set_key(key);
          bucket[i].set_value(1);
          return;
        }
      }
    }
    for (int i = 0; i < 100; i++)
    {
      if (bucket[i].key() == key)
      {
        bucket[i].set_value(value + 1);
        return;
      }
    }
  }
};

int main()
{
  Dictionary dict = Dictionary();
  ifstream datafile;
  datafile.open("datafile.txt");

  if (datafile.is_open())
  {
    while (!datafile.eof())
    {
      string word;
      datafile >> word;
      if (datafile.fail())
      {
        break;
      }
      dict.add_value(word);
    }
  }
  datafile.close();
  dict.print();
}