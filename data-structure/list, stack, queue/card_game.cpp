#include <iostream>
#include <list>
#include <algorithm>
#include <random>

using namespace std;

class card_deck
{
private:
  list<int> cards = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  string name;

public:
  card_deck(string name)
  {
    this->name = name;
  }
  void shuffle_cards()
  {
    // list는 이런 셔플이 적용 안됨.
    // list: bidirectional iterator
    // vector: random access iterator
    // shuffle(cards.begin(), cards.end(), default_random_engine());

    for (int i = 0; i < cards.size(); i++)
    {
      list<int>::iterator iter1 = cards.begin();
      list<int>::iterator iter2 = cards.begin();

      int j = i + rand() % (cards.size() - i);

      advance(iter1, i);
      advance(iter2, j);
      int temp = *iter1;
      *iter1 = *iter2;
      *iter2 = temp;
    }
  }
  void remove()
  {
    // fix: 예외처리
    if (cards.size() == 0)
    {
      return;
    }
    cards.pop_front();
  }
  int select()
  {
    shuffle_cards();
    return cards.front();
  }
  int get_size()
  {
    return cards.size();
  }
  string get_name()
  {
    return name;
  }
};

class manager
{
private:
  bool winner = false;
  card_deck players[4] = {card_deck("Kim"), card_deck("Koh"), card_deck("Jang"), card_deck("Choi")};

public:
  list<int> select()
  {
    list<int> selected_cards;
    for (int i = 0; i < 4; i++)
    {
      selected_cards.push_back(players[i].select());
    }
    return selected_cards;
  }
  int match()
  {
    list<int> selected = select();
    // 중복 확인 + 제거
    // O(n^2)
    for (int num : selected)
    {
      list<int> indexes;
      int i = 0;
      for (int num_ : selected)
      {
        if (num == num_)
        {
          indexes.push_back(i);
        }
        i++;
      }
      if (indexes.size() == 2 || indexes.size() == 4)
      {
        cout << "number : " << num << endl;
        for (int target : indexes)
        {
          players[target].remove();
        }
      }
      else if (indexes.size() == 3)
      {
        int c = rand() % 3;
        cout << "number : " << num << endl;
        for (int target : indexes)
        {
          if (target != c)
            players[target].remove();
        }
      }
    }
  }
  void check_winner()
  {
    for (card_deck player : players)
    {
      cout << "size: " << player.get_size() << endl;
      if (player.get_size() == 0)
      {
        cout << "winner: " << player.get_name() << endl;
        exit(1);
      }
    }
    cout << "No winner this time" << endl;
  }
  void run()
  {
    select();
    match();
    check_winner();
  }
};

int main()
{
  manager game;
  while (true)
  {
    game.run();
  }
}