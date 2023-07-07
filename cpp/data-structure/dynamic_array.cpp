#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename T>
class dynamic_array
{
  // 배열 원소들을 저장하는 배열
  T *data;
  // 배열의 크기 (size_t 자료형)
  size_t n;

public:
  // 생성자: 사이즈, dynamic array 참조
  dynamic_array(int n)
  {
    this->n = n;
  }
  dynamic_array(const dynamic_array<T> &other)
  {
    n = other.n;
    data = new T[n];

    for (int i = 0; i < n; i++)
    {
      data[n] = other[n];
    }
  }

  // (dynamic array).data[index] -> (dynamic array)[index]
  // 일반 배열과 동일한 접근
  T &operator[](int index)
  {
    return data[index];
  }
  const T &operator[](int index) const
  {
    return data[index];
  }
  // at은 일반 인덱스 연산자와 다르게 범위 밖에 접근하면 에러 발생
  // 인덱스 연산자는 segment fault 발생
  T &at(int index)
  {
    if (index < n)
    {
      return data[index];
    }
    throw "Index out of range";
  }

  // 사이즈 반환, 소멸자
  size_t size()
  {
    return n;
  }
  ~dynamic_array()
  {
    delete[] data;
  }

  // iterator
  T *begin()
  {
    return data;
  }
  const T *begin() const
  {
    return data;
  }
  T *end()
  {
    return data + n;
  }
  const T *end() const
  {
    return data + n;
  }

  // 배열을 합치는 + 연산자 정의
  friend dynamic_array<T> operator+(const dynamic_array<T> &arr1, const dynamic_array<T> &arr2)
  {
    dynamic_array<T> array(arr1.size() + arr2.size());
    copy(arr1.begin(), arr1.end(), array.begin());
    copy(arr2.begin(), arr2.end(), array.begin() + arr1.size());

    return array;
  }

  // to_string method
  string to_string(const string &sep = ", ")
  {
    if (n == 0)
    {
      return "";
    }
    /*
    istringstream: string 파싱
    ostringstream: string 조합, 저장
    sstringstream: 문자열에서 원하는 자료형 데이터 추출
    */
    ostringstream os;
    os << data[0];

    for (int i = 1; i < n; i++)
    {
      os << sep << data[i];
    }

    return os.str();
  }
};
