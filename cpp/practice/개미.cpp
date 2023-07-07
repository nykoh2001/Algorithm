// 1차: TLE
// 2차: 20

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;

int Answer;

int main(int argc, char **argv)
{
  int T, test_case;

  // 	freopen("sample_input.txt", "r", stdin);

  ios_base::sync_with_stdio(0), cout.tie(0);
  cin >> T;
  for (test_case = 0; test_case < T; test_case++)
  {

    Answer = 0;

    int ant_cnt, num;
    cin >> ant_cnt;
    vector<int> locations;
    vector<pair<int, int>> values;
    for (int i = 0; i < ant_cnt; i++)
    {
      cin >> num;
      locations.push_back(num);
    }
    for (int i = 0; i < ant_cnt; i++)
    {
      cin >> num;
      values.push_back(make_pair(num, locations.at(i)));
    }

    sort(values.begin(), values.end());

    for (int i = 0; i < ant_cnt; i++)
    {
      int offset = abs(values.at(i).second - locations.at(i));
      Answer = Answer + offset;
    }

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0; // Your program should return 0 on normal termination.
}