#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct nTree
{
  string name;
  bool isDirectory;
  vector<nTree *> children;
  nTree *parent;
};

vector<string> split(string str)
{
  vector<string> result;
  stringstream ss(str);
  string temp;
  while (getline(ss, temp, '/'))
  {
    result.push_back(temp);
  }
  return result;
}

class FileSystemStructure
{
private:
  nTree *root = new nTree{"/", true, vector<nTree *>(), NULL};
  nTree *current_directory = root;
  vector<string> path = vector<string>();

  nTree *search_impl(string path)
  {
    vector<string> dirs = split(path);
    nTree *temp = root;
    for (vector<string>::iterator iter = dirs.begin(); iter != dirs.end(); iter++)
    {
      if (*iter == ".")
      {
        continue;
      }
      if (*iter == "..")
      {
        if (temp == root)
        {
          cout << "상위 디렉토리가 없습니다." << endl;
          return NULL;
        }
        temp = temp->parent;
        continue;
      }
      vector<nTree *>::iterator inner;
      for (inner = temp->children.begin(); inner != temp->children.end(); inner++)
      {
        if (*iter == (*inner)->name)
        {
          iter++;
          temp = *inner;
          break;
        }
      }
      if (inner == temp->children.end())
      {
        cout << "해당하는 경로의 디렉토리/파일이 없습니다." << endl;
        return NULL;
      }
    }
    cout << path << "에 해당하는 디렉토리/파일 반환" << endl;
    return temp;
  }

public:
  nTree *search(string path)
  {
    search_impl(path);
  }
  void add(string name, bool isDirectory)
  {
    current_directory->children.push_back(new nTree{name, isDirectory, vector<nTree *>(), current_directory});
  }
  void print()
  {
    cout << "파일/디렉토리 목록" << endl;
    for (vector<nTree *>::iterator iter = current_directory->children.begin(); iter != current_directory->children.end(); iter++)
    {
      cout << ((*iter)->isDirectory ? "-d " : "- ") << (*iter)->name << endl;
    }
  }
  void move(string path)
  {
    nTree *target = search_impl(path);
    if (!target)
    {
      return;
    }
    current_directory = target;
  }
};
