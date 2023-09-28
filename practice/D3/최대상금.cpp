#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int C;
  cin >> C;
  for (int t = 1; t <= C; t++)
  {
    string number;
    int iter;
    cin >> number >> iter;

    int len = number.length();

    if (iter >= len - 1)
    { // iter == len - 1일 때 전체 내림차순 정렬
      sort(number.begin(), number.end());
      reverse(number.begin(), number.end());

      int remain = iter - (len - 1);
      if (remain % 2)
      {
        int temp = number.at(len - 1);
        number.at(len - 1) = number.at(len - 2);
        number.at(len - 2) = temp;
      }
    }
    else
    {
      for (int i = 0; i < iter; i++)
      {
        int maximum = i;
        bool found_max = false;
        for (int j = i + 1; j < len; j++)
        {
          char c = number.at(j);

          if (c - '0' >= number.at(maximum) - '0')
          {
            maximum = j;
            found_max = true;
          }
        }

        if (found_max)
        {
          char temp = number.at(i);
          number.at(i) = number.at(maximum);
          number.at(maximum) = temp;
        }
        else
        {
          // 그 다음 인덱스에 대해 같은 동작 반복
          iter++;
        }
      }

      int count = 1;
      int last_index = iter + 1;
      for (int i = 0; i < iter; i++)
      {
        if (number.at(i) == number.at(i + 1))
        {
          count++;
        }
        else
        {
          sort(number.begin() + last_index, number.begin() + last_index + count);
          reverse(number.begin() + last_index, number.begin() + last_index + count);

          last_index += count;
          count = 1;
        }
      }
      sort(number.begin() + last_index, number.begin() + last_index + count);
      reverse(number.begin() + last_index, number.begin() + last_index + count);
    }
    cout << "#" << t << " " << number << "\n";
  }
}
