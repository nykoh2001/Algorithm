#include <iostream>
#define MINUS_INF -9999999

using namespace std;

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void insertionSort(int *numbers, int length)
{
  for (int i = 2; i < length; i++)
  {
    int j = i;
    int val = numbers[i];
    while (numbers[j - 1] > val)
    {
      numbers[j] = numbers[j - 1];
      j--;
    }
    numbers[j] = val;
  }
}

int main()
{
  int numbers[] = {MINUS_INF, 30, 20, 40, 10, 5, 10, 30, 15};
  int length = sizeof(numbers) / sizeof(numbers[0]);

  insertionSort(numbers, length);

  for (int number : numbers)
  {
    cout << number << " ";
  }
  cout << endl;
}