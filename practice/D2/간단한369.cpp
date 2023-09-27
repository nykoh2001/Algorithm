#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;

  for (int i = 1; i < N + 1; i++)
  {
    string n_str = to_string(i);
    string hypen = "";
    for (char c : n_str)
    {
      if ((c - '0') % 3 == 0 && (c - '0') > 0)
      {
        hypen += "-";
      }
    }

    if (hypen == "")
    {
      cout << n_str;
    }
    else
    {
      cout << hypen;
    }
    cout << " ";
  }
  cout << endl;
}