#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dfs

int level = 1;
vector<int> *graph;
int *visited;

void dfs(
    int node
    // , vector<int> *graph, int *visited
)
{
  visited[node] = level++;

  // for (int i = 0; i < (int)graph[node].size(); i++)
  for (vector<int>::iterator iter = graph[node].begin(); iter != graph[node].end(); iter++)
  {
    if (visited[*iter] == 0)
    {
      dfs(*iter);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, R;
  cin >> N >> M >> R;

  // vector<int> graph[N+1];

  // visited 선언 및 초기화
  // int visited[N+1];
  // fill_n(visited, N+1, 0);

  // 전역 포인터로 선언 -> 동적 할당
  graph = new vector<int>[N + 1];
  visited = new int[N + 1];

  // graph 생성
  for (int i = 0; i < M; i++)
  {
    int n1, n2;
    cin >> n1 >> n2;

    // 양방향 엣지
    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
  }

  for (int i = 0; i < N + 1; i++)
  {
    sort(graph[i].begin(), graph[i].end());
  }

  // for (int i= 0; i < N+1; i++) {
  //   for (auto j = graph[i].begin(); j != graph[i].end(); j++){
  //     cout << *j;
  //   }
  //   cout << endl;
  // }

  dfs(R);

  for (int i = 1; i < N + 1; i++)
  {
    cout << visited[i] << '\n';
    // endl은 다음 줄로 이동함과 동시에 버퍼 클리어
    // 많은 양을 출력할 때는 매우 오뢔 걸림
    // ,,,
  }
}