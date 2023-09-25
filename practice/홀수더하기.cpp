#include <iostream>
#include <sstream>

using namespace std;

int main()
{
  int N;
  cin >> N;

  for (int n = 0; n < N; n++)
  {

    int result = 0;
    for (int i = 0; i < 10; i++)
    {
      string item;
      cin >> item;
      int num = stoi(item);

      if (num % 2 == 1)
      {
        result += num;
      }
    }
    cout << "#" << n + 1 << " " << result << "\n";
  }
}