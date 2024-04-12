#include <iostream>
#include <string>
#define Nmax 100
using namespace std;

struct point
{
  char c;
  int x, y;
};
struct line
{
  struct point p1, p2;
  float angle;
};
struct point polygon[Nmax];

int flag = 1;
float ComputeAngle(struct point p1, struct point p2)
{

  int dx, dy, ax, ay;
  float t;
  dx = p2.x - p1.x;
  ax = abs(dx);
  dy = p2.y - p1.y;
  ay = abs(dy);
  t = (ax + ay == 0) ? 0 : (float)dy / (ax + ay);
  if (dx < 0)
    t = 2 - t;
  else if (dy < 0)
    t = 4 + t;
  return t * 90.0;
}

void swap(line a[], int i, int j)
{
  line temp;
  temp = a[j];
  a[j] = a[i];
  a[i] = temp;
}

void MakeHeap(line a[], int Root, int LastNode)
{
  int Parent, LeftSon, RightSon, Son;
  line RootValue;
  Parent = Root;
  memcpy(&RootValue, &a[Root], sizeof(struct line));

  LeftSon = 2 * Parent;
  RightSon = LeftSon + 1;
  while (LeftSon <= LastNode)
  {

    if (RightSon <= LastNode && a[LeftSon].angle < a[RightSon].angle)
    {
      Son = RightSon;
    }
    else
      Son = LeftSon;

    if (RootValue.angle < a[Son].angle)
    {
      memcpy(&a[Parent], &a[Son], sizeof(struct line));

      Parent = Son;
      LeftSon = Parent * 2;
      RightSon = LeftSon + 1;
    }
    else
      break;
  }
  memcpy(&a[Parent], &RootValue, sizeof(struct line));
}

void heapsort(line a[], int N)
{
  int i;
  for (i = N / 2; i >= 1; i--)
  {
    MakeHeap(a, i, N);
  }
  for (i = N; i > 1; i--)
  {
    swap(a, 1, i);
    MakeHeap(a, 1, i - 1);
  }
}

bool isInside(point B, point p[], int n)
{
  int crosses = 0;
  for (int i = 0; i < n; i++)
  {
    int j = (i + 1) % n;

    if ((p[i].y > B.y) != (p[j].y > B.y))
    {
      long double atX = (p[j].x - p[i].x) * (B.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
      if (B.x < atX)
        crosses++;
    }
  }
  return crosses % 2 > 0;
}

int main()
{
  int n, zx, zy;
  int j1, j2;
  cout << "N, Z의 x y값을 입력하세요 : ";
  // while (1)
  // {
  //   cin >> n;
  //   if (n <= 100)
  //     break;
  //   else
  //     cout << "다시 입력하세요: ( N<=100 ) " << endl;
  // }
  cin >> n >> zx >> zy;
  cout << endl;

  point test = {'x', zx, zy};
  for (int i = 0; i < n; i++)
  {
    char ch(i + 65);
    cout << ch << " ";
    cin >> j1 >> j2;
    polygon[i].c = ch;
    polygon[i].x = j1;
    polygon[i].y = j2;
  }

  int min = 0;
  for (int i = 1; i < n; i++)
  {
    if (polygon[i].y < polygon[min].y)
      min = i;
    else if (polygon[i].y == polygon[min].y)
      if (polygon[i].x < polygon[min].x)
        min = i;
  }

  // 2
  float *angle = new float[n];
  line *path = new line[n + 1];

  path[0] = {NULL, NULL, NULL};
  for (int i = 1; i <= n; i++)
  {
    path[i] = {polygon[min], polygon[i - 1], 0.0};
    path[i].angle = ComputeAngle(polygon[min], polygon[i - 1]);
  }

  cout << endl
       << "다각형이 만들어지는 순서 : ";
  heapsort(path, n);
  for (int i = 1; i <= n; i++)
  {
    cout << path[i].p2.c;
    if (i != n)
      cout << "->";
    else
      cout << endl;
    polygon[i - 1] = path[i].p2;
  }

  if (isInside(test, polygon, n))
    cout << "True" << endl;
  else
    cout << "False" << endl;
}

// 8 3 5
// 3 4
// 1 2
// 2 5
// 2 6
// 9 3
// 5 3
// 6 4
// 8 7