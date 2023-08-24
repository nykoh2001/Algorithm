
class manager
{
private:
  bool winner = false;
  card_deck *players = new card_deck[4];

public:
  int *select()
  {
    list<int> selected_cards;
    for (int i = 0; i < 4; i++)
    {
      selected_cards.push_back(players[i].select());
    }
  }
  bool match()
  {
  }
};
