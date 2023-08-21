#include <iostream>
#include <vector>

using namespace std;

enum class city : int
{
  // city라는 enum class
  // static_cast<int>(city::_item) -> enum class에서 해당하는 정수로 캐스팅
  MOSCOW,
  LONDON,
  SEOUL,
  SEATTLE,
  DUBAI,
  SYDNEY
};

ostream &operator<<(ostream &os, const city c)
{
  // out stream (<<) operator redefine
  switch (c)
  {
  case city::LONDON:
    os << "런던";
    return os;
  case city::MOSCOW:
    os << "모스크바";
    return os;
  case city::SEOUL:
    os << "서울";
    return os;
  case city::SEATTLE:
    os << "시애틀";
    return os;
  case city::DUBAI:
    os << "두바이";
    return os;
  case city::SYDNEY:
    os << "시드니";
    return os;
  default:
    return os;
  }
}

struct graph
{
  // 2차원 행렬
  vector<vector<int>> data;

  graph(int n)
  {
    // reserve: 재할당 빈도 감소
    data.reserve(n);
    vector<int> row(n);
    fill(row.begin(), row.end(), -1);

    for (int i = 0; i < n; i++)
    {
      data.push_back(row);
    }
  }

  void addEdge(const city c1, const city c2, int distance)
  {
    // undirected
    // weighted
    cout << "엣지 추가: " << c1 << " - " << c2 << ", 거리: " << distance << endl;

    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);
    data[n1][n2] = distance;
    data[n2][n1] = distance;
  }

  void removeEdge(const city c1, const city c2)
  {
    cout << "엣지 삭제: " << c1 << " - " << c2 << endl;

    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);

    data[n1][n2] = -1;
    data[n2][n1] = -1;
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