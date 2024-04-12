#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <limits>
#include <json/json.h>

using namespace std;

const double INF = 1e9; // 무한대 값

struct Position
{
  double latitude;
  double longitude;
};

struct Node
{
  unsigned long long id;
  Position position;
};

struct Edge
{
  unsigned long long start;
  unsigned long long end;
  double cost;
};

std::vector<std::vector<double>> floydWarshall(std::vector<Node> &nodes, std::vector<Edge> &edges, std::unordered_map<int, int> &idToIndexMap)
{
  // cout << "floyd warshall" << endl;
  int numNodes = nodes.size();
  std::vector<std::vector<double>> dist(numNodes, std::vector<double>(numNodes, std::numeric_limits<double>::infinity()));

  // 초기화: 자기 자신으로 가는 거리는 0, 간선의 가중치로 초기화
  for (int i = 0; i < numNodes; ++i)
  {
    dist[i][i] = 0.0;
  }

  for (const auto &edge : edges)
  {
    // cout << "edge" << endl;
    int startIndex = idToIndexMap[edge.start];
    int endIndex = idToIndexMap[edge.end];
    dist[startIndex][endIndex] = edge.cost;
  }

  // 플로이드-워셜 알고리즘 수행
  for (int k = 0; k < 20; ++k)
  {
    // cout << "K: " << k << endl;
    for (int i = 0; i < numNodes; ++i)
    {
      for (int j = 0; j < numNodes; ++j)
      {
        if (dist[i][k] + dist[k][j] < dist[i][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  return dist;
}

std::pair<std::vector<Node>, std::vector<Edge>> parseData(const std::string &data)
{
  Json::Value root;
  Json::Reader reader;
  bool parsingSuccessful = reader.parse(data.c_str(), root);
  if (!parsingSuccessful)
  {
    std::cout << "Failed to parse JSON\n"
              << reader.getFormattedErrorMessages();
    return std::make_pair(std::vector<Node>(), std::vector<Edge>());
  }

  std::vector<Node> nodes;
  std::vector<Edge> edges;

  const Json::Value nodeArray = root["node"];
  for (int index = 0; index < nodeArray.size(); ++index)
  {
    Node node;
    node.id = nodeArray[index]["id"].asUInt64();
    node.position.latitude = nodeArray[index]["position"]["latitude"].asDouble();
    node.position.longitude = nodeArray[index]["position"]["longitude"].asDouble();
    nodes.push_back(node);
  }

  const Json::Value edgeArray = root["edge"];
  for (int index = 0; index < edgeArray.size(); ++index)
  {
    Edge edge;
    edge.start = edgeArray[index]["start"].asUInt64();
    edge.end = edgeArray[index]["end"].asUInt64();
    edge.cost = edgeArray[index]["cost"].asDouble();
    edges.push_back(edge);
  }

  return std::make_pair(nodes, edges);
}

int main()
{
  ifstream file("./driveway_seoul.json");

  if (!file.is_open())
  {
    std::cout << "Failed to open file." << std::endl;
    return 1;
  }

  string jsonString((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

  std::pair<std::vector<Node>, std::vector<Edge>> parsedData = parseData(jsonString);

  // parsedData 출력하기
  // std::cout << "Node data:\n";
  // for (const auto &node : parsedData.first)
  // {
  //   std::cout << "ID: " << node.id
  //             << ", Latitude: " << node.position.latitude
  //             << ", Longitude: " << node.position.longitude << std::endl;
  // }

  vector<Node> nodes = parsedData.first;
  vector<Edge> edges = parsedData.second;

  unordered_map<int, int> idToIndexMap;
  for (int i = 0; i < nodes.size(); ++i)
  {
    idToIndexMap[nodes[i].id] = i;
  }

  std::vector<std::vector<double>> shortestDistances = floydWarshall(nodes, edges, idToIndexMap);

  // 결과 출력
  std::cout << "Shortest distances between nodes:" << std::endl;
  for (int i = 0; i < shortestDistances.size(); ++i)
  {
    for (int j = 0; j < shortestDistances[i].size(); ++j)
    {
      if (shortestDistances[i][j] < std::numeric_limits<double>::infinity() && shortestDistances[i][j] > 0)
      {
        std::cout << "Node " << nodes[i].id << " to Node " << nodes[j].id << ": " << shortestDistances[i][j] << std::endl;
      }
    }
  }

  return 0;
}
