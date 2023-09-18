#include <iostream>
#include <stdlib.h>

using namespace std;

void print_sorted(int *array, int size)
{
  // bubble sort
  for (int i = 0; i < size; i++)
  {
    for (int j = i; j < size; j++)
    {
      if (array[i] > array[j])
      {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
}

int main()
{
  srand(time(NULL));

  int N, M;
  cout << "10이상의 정수를 입력해주세요";
  cin >> N;
  cout << "10이상의 정수를 입력해주세요";
  cin >> M;
  int SET1[N];
  int SET2[M];

  // SET1 생성
  for (int i = 0; i < N; i++)
  {
    int random = rand() % 40 + 1;
    SET1[i] = random;
    for (int j = 0; j < i; j++)
    {
      if (SET1[i] == SET1[j])
      {
        i--;
      }
    }
  }

  // SET2 생성
  for (int i = 0; i < M; i++)
  {
    int random = rand() % 40 + 1;
    SET2[i] = random;
    for (int j = 0; j < i; j++)
    {
      if (SET2[i] == SET2[j])
      {
        i--;
      }
    }
  }

  int SET_UNION[10000];
  int union_index = 0;

  int SET_INTER[10000];
  int inter_index = 0;

  cout << "\nSET1" << endl;
  print_sorted(SET1, N);
  cout << endl;
  cout << "\nSET2" << endl;
  print_sorted(SET2, M);
  cout << endl
       << endl;

  // 합집합 만들기
  for (int set_one : SET1)
  {

    for (int i = 0; i < M; i++)
    {
      if (SET2[i] == set_one)
      {
        // 겹치는 원소 SET_INTER에 추가
        SET_INTER[inter_index++] = SET2[i];
        // SET2에서 SET1과 겹치는 원소 제거
        SET2[i] = -9999;
      }
    }
  }

  for (int set_one : SET1)
  {
    SET_UNION[union_index++] = set_one;
  }
  for (int set_two : SET2)
  {
    if (set_two != -9999)
    {
      SET_UNION[union_index++] = set_two;
    }
  }

  cout << "합집합" << endl;
  print_sorted(SET_UNION, union_index);

  // 교집합 만들기
  for (int set_two : SET2)
  {
    for (int i = 0; i < N; i++)
    {
      if (SET1[i] == set_two)
      {
        // 겹치는 원소 한번 더 추가
        SET_INTER[inter_index++] = SET1[i];
        SET1[i] = -9999;
      }
    }
  }

  cout << endl
       << endl;
  cout << "교집합" << endl;
  for (int i = 0; i < inter_index; i++)
  {
    cout << SET_INTER[i] << " ";
  }
}