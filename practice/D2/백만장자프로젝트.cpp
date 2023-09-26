#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    int N;
    cin >> N;

    vector<int> numbers;
    numbers.reserve(1000000);

    for (int j = 0; j < N; j++)
    {
      string num;
      cin >> num;

      int number = stoi(num);
      numbers.push_back(number);
    }

    int maximum = 0;
    long long benefit = 0;

    for (int j = N - 1; j >= 0; j--)
    {
      int number = numbers.at(j);
      if (maximum < number)
      {
        maximum = number;
        continue;
      }

      benefit += maximum - number;
    }
    cout << "#" << i + 1 << " " << benefit << "\n";
  }
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//   int T;
//   cin >> T;

//   for (int i = 0; i < T; i++)
//   {
//     int N;
//     cin >> N;

//     vector<int> numbers = vector<int>();
//     vector<int> maxes_idx = {0};

//     for (int j = 0; j < N; j++)
//     {

//       string num;
//       cin >> num;

//       numbers.push_back(stoi(num));

//       if (j > 0 && numbers.at(j) > numbers.at(j - 1))
//       {
//         if (stoi(num) > numbers.at(maxes_idx.back()))
//         {
//           maxes_idx.pop_back();
//         }
//         maxes_idx.push_back(j);
//       }
//     }

//     for (int max : maxes_idx)
//     {
//       cout << max << " ";
//     }
//     cout << endl;

//     int benefit = 0;
//     int current_max_idx = 0;
//     int current_max = numbers.at(maxes_idx.at(current_max_idx));
//     int maxes_size = maxes_idx.size();
//     for (int j = 0; j < N; j++)
//     {
//       if (j == maxes_idx.at(current_max_idx))
//       {
//         current_max_idx += 1;
//         if (current_max_idx == maxes_size)
//           break;

//         current_max = numbers.at(maxes_idx.at(current_max_idx));
//       }
//       if (current_max > numbers.at(j))
//       {
//         benefit = benefit + current_max - numbers.at(j);
//       }
//     }

//     cout << "#" << i + 1 << " " << benefit << "\n";
//   }
// }