#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define VERY_EASY 5
#define EASY 20
#define NORMAL 10
#define HARD 5
#define VERY_HARD 10

#define SIZE_STRING_NAME 50

int get_string(char *string);

int draw_number(int range);

int initial_screen(char *player_name);

void clean_screen();

void dif_screen(int *attempts, int *range);

int match_sreen(int random_number, int attempts, int *points);

void win_defeat_screen(int match_result, int points);

int main(void) {

  char current_user_name[50];
  int tentativas, intervalo, numero_secreto, resultado;
  int points = 1000;

  if (initial_screen(current_user_name) == 1) {

    printf("Problema na leitura de string");
  }

  dif_screen(&tentativas, &intervalo);

  numero_secreto = draw_number(intervalo);

  resultado = match_sreen(numero_secreto, tentativas, &points);

  win_defeat_screen(resultado, points);

  return 0;
}

int draw_number(int range) {

  int random_number;
  srand(time(NULL));

  random_number = (rand() % (range)) + 1;

  return random_number;
}

int initial_screen(char *player_name) {

  printf("*********************************************************************"
         "*************************************************\n");
  printf("\t\t\t\t\t\tBEM-VINDO AO JOGO DE ADIVINHAÇÃO\n");
  printf("*********************************************************************"
         "*************************************************\n");

  printf("\n\n\n \t\t\t\t\t\t informe o nome do jogador:\n\n");
  int output = get_string(player_name);

  return output;
}

void clean_screen() {

#ifdef _WIN32
  system("cls");
#elif __linux__
  system("clear");
#endif
}

int get_string(char *string) {

  int c;

  if (fgets(string, SIZE_STRING_NAME, stdin) == NULL) {
    return 1;
  }

  string[strcspn(string, "\n")] = '\0';

  return 0;
}

void dif_screen(int *attempts, int *range) {

  clean_screen();

  int choice;

  printf("Escolha a dificuladade\n\n\n");

  printf("\t\t\t\t\t\t 1 - muito fácil : numeros de 0-10, 5 tentativas\n");
  printf("\t\t\t\t\t\t 2 - fácil : numeros de 0-100, 20 tentativas\n");
  printf("\t\t\t\t\t\t 3 - normal: numeros de 0-100, 10 tentativas\n");
  printf("\t\t\t\t\t\t 4 - difícil: numeros de 0-100, 5 tentativas\n");
  printf("\t\t\t\t\t\t 5 - muito difícil: numeros de 0-1000, 10 tentativas\n");
  printf("\t\t\t\t\t\t 6 - custom : Escolha a quantidade de tentativas e "
         "numeros \n");

  printf("Faça sua escolha:");
  scanf("%d", &choice);

  switch (choice) {

  case 1:

    *range = 10;
    *attempts = VERY_EASY;

    break;

  case 2:

    *range = 100;
    *attempts = EASY;

    break;

  case 3:

    *range = 100;
    *attempts = NORMAL;

    break;

  case 4:

    *range = 100;
    *attempts = HARD;

    break;

  case 5:

    *range = 1000;
    *attempts = VERY_HARD;

    break;

  case 6:

    printf("\n\n Escolha a quatidade máxima de numeros que iram aparecer:");
    scanf("%d", range);
    printf("\n\n Escolha a quantidade de tentativas:");
    scanf("%d", attempts);

    break;
  }
}

int match_sreen(int random_number, int attempts, int *points) {

  clean_screen();

  int bet_number;

  printf("\t\t\t\t\t\t QUE O O JOGO COMEÇE\n\n\n");

  for (int i = 1; i <= attempts; i++) {

    printf("___________________________________________________________________"
           "______________________________\n\n");

    printf("\t\t\t\t\t\t Você tem %d tentativas:\n\n", (attempts + 1) - i);

    printf("\t\t\t\t\t\t Escolha qual numero voce quer\n\n\n");
    printf("\t\t\t\t\t\t\t\t");
    scanf("%d", &bet_number);

    if (bet_number < random_number) {
      printf("\t\t\t\t\t\t\t pequeno demais\n\n");
      (*points) = (*points) / 2;
    } else if (bet_number > random_number) {
      printf("\t\t\t\t\t\t\t alto demais\n\n");
      (*points) = (*points) / 2;
    } else {
      return 1;
    }

    printf("___________________________________________________________________"
           "______________________________\n");
  }

  return 0;
}


void win_defeat_screen(int match_result, int points){


 if(match_result){

    printf("Seu numero de pontos foir: %d\n\n", points);
        printf(
        "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
        "░░░░█▀▀▀░█▀▀▀░░█▀▀░▀▀█░░█░░░░\n"
        "░░░░█░▀█░█░▀█░░█▀▀░▄▀░░░▀░░░░\n"
        "░░░░▀▀▀▀░▀▀▀▀░░▀▀▀░▀▀▀░░▀░░░░\n"
        "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n");
  }else{

    printf("Você perdeu infizmente\n\n");

      printf(      "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣴⣶⣶⣶⣾⣿⣿⣿⣿⣶⣶⣶⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣶⣿⡿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠻⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠈⣉⣉⣿⣿⡿⠛⠛⠛⠀⠀⠀⠉⢻⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠻⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⡄⠀⠀⣀⣤⡤⢤⣀⠀⠀⢹⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⢴⣶⡶⢿⣿⣿⣿⣦⣄⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⡿⠋⢀⣴⡿⠟⠋⠀⠀⠻⣷⣦⡀⢿⣿⣿⡄⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⢀⣴⡿⠛⠉⠉⠉⠙⠻⢿⣿⣿⣦⠀⠀⠀⠀⠀⠀⣾⣿⣿⡿⠁⣠⣾⠋⠀⠀⠀⢰⣆⠀⠈⠛⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⣾⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⡁⠀⠀⠀⠀⠀⠀⢹⣿⣿⠃⢰⡿⠁⠀⠀⠀⠀⠀⢿⣦⣀⣠⡟⢻⣿⣿⣿⡆⠀⠀⠀⠀⠀\n"
        "⠀⠀⣸⣿⠃⠀⠀⠀⠀⣠⣴⠞⠋⠉⠛⠻⣷⣦⡀⠀⠀⠀⠀⠸⣿⠿⠀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠁⠀⢹⡟⢿⣿⡄⠀⠀⠀⠀\n"
        "⠀⢀⣿⡏⠀⠀⠀⢠⡾⠋⠁⠀⠀⠀⠀⠀⠀⠻⣿⣦⡀⠀⠀⠀⠀⠀⠀⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⠀⢻⣿⣄⠀⠀⠀\n"
        "⠀⢸⣿⠁⠀⠀⠀⡾⠳⠶⣶⡀⠀⠀⠀⠀⠀⠀⠙⠻⣷⠀⠀⠀⠀⠀⠀⠈⠻⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⢻⣿⣆⠀⠀\n"
        "⠀⣾⡏⠀⠀⠀⠀⢃⣠⣴⣿⠃⠀⠀⠀⠀⠀⠀⠀⣰⡟⠀⠀⢀⣀⣀⣀⣀⣀⡈⠻⣦⣄⡀⠀⠀⠀⠀⠀⠀⢀⣤⠆⠀⠀⠈⣿⣿⡆⠀\n"
        "⠀⣿⠃⠀⠀⠀⠰⣿⠋⠉⠀⠀⠀⠀⠀⠀⠀⢀⣼⠟⠀⣴⡿⢛⠉⠉⠉⢋⠉⠙⢛⡿⣿⡟⠳⠶⠶⠶⠶⠞⠋⠁⠀⠀⠀⠀⢹⣿⣿⠀\n"
        "⢠⣿⠀⠀⠀⠀⠀⢿⡆⠀⠀⠀⠀⠀⠀⠀⣠⡿⠋⢀⣼⠋⠀⢹⣧⡀⠀⣿⠿⠶⠾⠃⠈⠙⠻⢶⣤⣤⣤⣤⣄⠀⠀⠀⠀⠀⠀⢻⣿⡇\n"
        "⢸⡇⠀⠀⠀⠀⠀⠈⠻⣦⡀⠀⠀⠀⢀⣼⠋⠀⣠⡾⢳⡄⠀⠀⢻⠛⠳⠿⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠛⠋⠙⢧⠀⠀⠀⠀⠀⠘⣿⡇\n"
        "⣸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠒⠒⠛⠁⠀⠀⣿⠁⢸⣿⣦⣤⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣷⡀⠀⠀⠀⠀⣿⡇\n"
        "⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠦⠾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠘⢿⡄⠀⠀⠀⢻⡇\n"
        "⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠿⠋⠙⢷⣄⠀⠀⠀⠀⠀⠀⠈⣧⠀⠀⠀⢸⡇\n"
        "⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⢀⣤⠖⠚⠿⠿⠋⠀⠀⠀⢀⣿⣦⣀⡾⠛⠻⣶⡄⢸⠀⠀⠀⣼⡇\n"
        "⢻⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⢀⣾⠇⠀⠀⠀⠀⠀⣀⡀⠀⣾⠁⠀⢻⡇⠀⠀⠀⢁⣾⠀⠀⠀⢹⣇\n"
        "⠘⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏⠀⠀⠀⠀⠀⠀⠾⠏⠀⠀⠀⢰⣿⠋⠉⠻⣿⠏⣀⣤⣬⣤⣤⣤⣴⠿⠃⠀⠀⠀⠸⣿\n"
        "⠀⠹⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣤⠀⣼⡏⠀⠀⢀⣴⠞⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿\n"
        "⠀⠀⠹⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠃⠀⠀⠀⠀⠀⠀⣴⡟⠁⠀⠹⠿⠿⠁⣤⡶⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡿\n"
        "⠀⠀⠀⠹⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⣼⠃⠀⣴⡾⠿⣿⣄⣸⡏⠀⠀⠀⢀⣠⠶⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡟⠁\n"
        "⠀⠀⠀⠀⣿⠹⣷⣄⠀⠀⠀⠀⠀⠀⠿⣶⣾⣧⣀⣀⠀⠙⠋⢀⣤⡶⠞⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡿⠀⠀\n"
        "⠀⠀⠀⠀⢹⡄⠈⠻⣷⣦⡀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠙⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠃⠀⠀\n"
        "⠀⠀⠀⠀⠈⢷⡄⠀⠀⠙⢛⠷⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠃⠀⠀⠀\n"
    );

  } 

}
