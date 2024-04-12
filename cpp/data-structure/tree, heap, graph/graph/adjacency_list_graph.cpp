#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class city : int
{
  MOSCOW,
  LONDON,
  SEOUL,
  SEATTLE,
  DUBAI,
  SYDNEY
};

ostream &operator<<(ostream &os, const city c)
{
  switch (c)
  {
  case city::MOSCOW:
    return os << "모스크바";
  case city::LONDON:
    return os << "런던";
  case city::SEOUL:
    return os << "서울";
  case city ::SEATTLE:
    return os << "시애틀";
  case city::DUBAI:
    return os << "두바이";
  case city::SYDNEY:
    return os << "시드니";
  default:
    break;
  }
}

struct graph
{
  vector<vector<pair<int, int>>> data;

  graph(int n)
  {
    data = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
  }

  void addEdge(const city c1, const city c2, int distance)
  {
    cout << "엣지 추가: " << c1 << " - " << c2 << ", 거리: " << distance << endl;

    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);

    data[n1].push_back({n2, distance});
    data[n2].push_back({n1, distance});
  }

  void removeEdge(const city c1, const city c2)
  {
    cout << "엣지 삭제: " << c1 << " - " << c2 << endl;

    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);

    remove_if(data[n1].begin(), data[n1].end(), [n2](const pair<int, int> &pair)
              { return pair.first == n2; });
    remove_if(data[n2].begin(), data[n2].end(), [n1](const pair<int, int> &pair)
              { return pair.first == n1; });
  }
};

int main()
{
  graph _graph(6);

  _graph.addEdge(city::LONDON, city::MOSCOW, 2500);
  _graph.addEdge(city::LONDON, city::SEOUL, 9000);
  _graph.addEdge(city::LONDON, city::DUBAI, 5500);
  _graph.addEdge(city::DUBAI, city::SEOUL, 7000);
  _graph.addEdge(city::SEOUL, city::MOSCOW, 6600);
  _graph.addEdge(city::SEOUL, city::SYDNEY, 8000);
  _graph.addEdge(city::DUBAI, city::SYDNEY, 1200);
  _graph.addEdge(city::SEATTLE, city::SEOUL, 80000);
  _graph.addEdge(city::SEATTLE, city::MOSCOW, 8400);
  _graph.addEdge(city::SEATTLE, city::SYDNEY, 12000);

  _graph.addEdge(city::SEATTLE, city::LONDON, 8000);
  _graph.removeEdge(city::SEATTLE, city::LONDON);
}