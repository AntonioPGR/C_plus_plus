#include <stdio.h>
#include <iostream>

using namespace std;

int writeLine(string message)
{
  cout << message << endl;
}

int writeBar()
{
  const string BAR = "-----------------------";
  writeLine(BAR);
}

int main()
{
  writeBar();
  writeLine("- Pedra Papel Tesoura -");
  writeBar();
  writeLine(" ");
  writeLine("-> Voce jogara uma melhor de tres de pedra papel tesoura contra o computador");
  writeLine("-> Escolha sabiamente suas jogadas e ganhe o jogo!");
  writeLine(" ");

  int player_score = 0;
  int computer_score = 0;

  writeBar();
  cout << "Qual sera sua opcao?" << endl;
  writeLine("Pedra (R)");
  writeLine("Papel (P)");
  writeLine("Tesoura (T)");
  writeBar();
  string computer_choice = "R";
  string player_choise;
  cin >> player_choise;
  writeBar();
  bool has_computer_winned = (player_choise == "R" && computer_choice == "P") || (player_choise == "P" && computer_choice == "T") || (player_choise == "T" && computer_choice == "R");
  bool has_player_winned = (player_choise == "R" && computer_choice == "T") || (player_choise == "T" && computer_choice == "P") || (player_choise == "P" && computer_choice == "R");

  if (has_player_winned)
  {
    cout << "Voce venceu!! O computador escolheu " << computer_choice << " e voce " << player_choise << endl;
    player_score++;
  }
  else if (has_computer_winned)
  {
    cout << "Voce perdeu!! O computador escolheu " << computer_choice << " e voce " << player_choise << endl;
    computer_score++;
  }
  else
  {
    cout << "Voces empataram!! voces escolheram " << computer_choice << endl;
  }
  writeLine(" ");
}