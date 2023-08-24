#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(){

  system("cls");
  cout << "--------------------" << endl;
  cout << "- GUESS THE NUMBER -" << endl;
  cout << "--------------------" << endl;
  cout << " " << endl;

  int max_de_tentativas = 0;
  char dificuldade;
  while (true){
    cout << "As opcoes de dificuldades sao: " << endl;
    cout << "Facil (F) " << endl;
    cout << "Medio (M) " << endl;
    cout << "Dificil (D) " << endl;
    cout << "Escolha uma dificuldade: ";
    cin >> dificuldade;

    switch (dificuldade){
      case 'F':
        max_de_tentativas = 10;
        break;
      case 'M':
        max_de_tentativas = 7;
        break;
      case 'D':
        max_de_tentativas = 5;
        break;
    }
    if(max_de_tentativas != 0){
      break;
    }
    system("cls");
    cout << "A opcao que voce escolheu nao existe!!! lembre-se:" << endl;
  }
  
  // Numero aleatório
  srand(time(NULL));
  const int NUMERO_ESCOLHIDO = rand() % 100;

  int pontuacao_max = 200;
  int pontuacao = pontuacao_max;
  bool acertou = false;
  int tentativa_atual = 1;

  system("cls");
  cout << "------------------------------------------------------------" << endl;
  cout << "Com o jogo na dificuldade " << dificuldade << " voce tera " << max_de_tentativas << " tentativas" << endl;
  cout << "Boa sorte!" << endl;
  cout << "------------------------------------------------------------" << endl;

  for(tentativa_atual; tentativa_atual <= max_de_tentativas; tentativa_atual++){
    cout << " " << endl;
    cout << "Tentativa atual: " << tentativa_atual << "/" << max_de_tentativas << endl;
    cout << "Escolha um numero entre 1 e 100: ";
    int chute;
    cin >> chute;

    system("cls");

    if(chute == NUMERO_ESCOLHIDO){
      acertou = true;
      break;
    }
    if(chute < NUMERO_ESCOLHIDO){
      cout << "O numero " << chute << " e menor que o numero secreto" << endl;
    }
    if(chute > NUMERO_ESCOLHIDO){
      cout << "O numero " << chute << " e maior que o numero secreto" << endl;
    }

    int distancia_do_chute = abs(chute - NUMERO_ESCOLHIDO);
    double pontuacao_perdida = distancia_do_chute;
    pontuacao -= pontuacao_perdida;
  }
  
  if(acertou){
    cout << "Parabens!!! Voce ganhou!!!" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuacao foi " << pontuacao << "/" << pontuacao_max << endl;
  } else {
    cout << "Infelizmente nao foi dessa vez! Tente novamente!" << endl;
  }

  cout << "O numero escolhido era: " << NUMERO_ESCOLHIDO; 
}