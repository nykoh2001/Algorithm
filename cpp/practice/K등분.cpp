// 1차: TLE

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int Answer;

int main(int argc, char **argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(NULL);
  int T, test_case;

  // freopen("input.txt", "r", stdin);

  cin >> T;
  for (test_case = 0; test_case < T; test_case++)
  {

    Answer = 0;

    vector<int> numbers;
    int N, K, num, sum = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
      cin >> num;
      sum += num;
      numbers.push_back(num);
    }

    int target = sum / K;

    // 2차원 행렬
    // 		bool is_target[N+1][N+1];
    // 		fill_n(is_target[0], (N+1)*(N+1), false);

    // 		int i = 0, j = 0;
    // 		while (true){
    // 		    for (j; j < N; j++) {
    // 		        if
    // 		    }
    // 		}

    // bfs

    vector<int> available[N];

    for (int i = 0; i < N; i++)
    {
      for (int j = i + 1; j < N; j++)
      {
        // i ~ j-1번째 수까지의 합
        int sum = 0;
        for (int p = i; p < j; p++)
        {
          sum += numbers.at(p);
        }
        if (sum == target)
        {
          available[i].push_back(j);
        }
      }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 1));
    while (!q.empty())
    {
      pair<int, int> current = q.front();
      q.pop();

      if (current.second > K)
      {
        continue;
      }

      if (current.first == N - 1 && current.second == K)
      {
        Answer++;
      }

      for (vector<int>::iterator iter = available[current.first].begin(); iter != available[current.first].end(); iter++)
      {
        q.push(make_pair(*iter, current.second + 1));
      }
    }

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0; // Your program should return 0 on normal termination.
}