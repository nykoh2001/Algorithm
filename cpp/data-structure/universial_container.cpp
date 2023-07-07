#include <iostream>
#include <array>
#include <type_traits>

using namespace std;

template <typename... Args>

// builder function: 모호한 데이터 입력에 대해 사용
// 함수 인자에 의존적인 타입 -> 후행 리턴 타입으로 선언
auto build_array(Args &&...args) -> array<typename common_type<Args...>::type, sizeof...(args)>
{
  // common Type 계산
  using commonType = typename common_type<Args...>::type;
  // 배열 생성
  return {forward<commonType>((Args &&)args)...};
}
