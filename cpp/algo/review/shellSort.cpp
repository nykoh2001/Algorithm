#include <iostream>

using namespace std;

void shellSort(int *numbers, int length)
{
  int h;
  h = 1;
  do
  {
    h = 3 * h + 1;
  } while (h < length);

  do
  {
    h = h / 3;
    for (int i = h; i < length; i++)
    {
      int value = numbers[i];
      int j = i;
      while (numbers[j - h] > value)
      {
        numbers[j] = numbers[j - h];
        j = j - h;
        if (j < h - 1)
        {
          break;
        }
      }
      numbers[j] = value;
    }
  } while (h > 1);
}

int main()
{
  int numbers[] = {30, 50, 15, 60, 35, 10, 40, 45, 5, 25, 55, 20};
  int length = sizeof(numbers) / sizeof(numbers[0]);
  shellSort(numbers, length);
  for (int num : numbers)
  {
    cout << num << " ";
  }
  cout << endl;
}