#include <iostream>
#include <fstream>
#include <string>

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
    KVS *results = new KVS[10000];
    int idx = 0;
    for (int i = 0; i < 144; i++)
    {
      KVS *bucket = dictionary[i];
      for (int j = 0; j < 100; j++)
      {
        if (bucket[j].value() > 0)
        {
          // cout << bucket[j].key() << " : " << bucket[j].value() << endl;
          results[idx++] = bucket[j];
        }
        else
        {
          break;
        }
      }
    }

    for (int i = 0; i < idx; i++)
    {
      for (int j = i + 1; j < idx; j++)
      {
        if (results[i].value() < results[j].value())
        {
          KVS temp = results[i];
          results[i] = results[j];
          results[j] = temp;
        }
        else if (results[i].value() == results[j].value())
        {
          if (strcmp(results[i].key().c_str(), results[j].key().c_str()) > 0)
          {
            KVS temp = results[i];
            results[i] = results[j];
            results[j] = temp;
          }
        }
      }
    }

    for (int i = 0; i < idx; i++)
    {
      cout << results[i].key() << " : " << results[i].value() << endl;
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

string *return_word(string word)
{
  string *words = new string[100];
  int idx = 0;
  for (char c : word)
  {
    int ascii = c;
    if (ascii >= 33 && ascii <= 47)
    {
      words[idx++] = word.substr(0, word.find(c));
      word = word.substr(word.find(c));
    }
  }
  return words;
}

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
      string *words = return_word(word);
      int w_idx = 0;
      while (true)
      {
        if (words[w_idx] == "")
        {
          break;
        }
        dict.add_value(words[w_idx]);
        w_idx++;
      }
      if (w_idx == 0)
      {
        dict.add_value(word);
      }
    }
  }
  datafile.close();
  dict.print();
}