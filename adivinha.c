#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




#define SIZE_STRING_NAME 50




int get_string(char *string);


int draw_number(int *range);


int initial_screen(char *player_name);


void clean_screen();


void dif_screen(int *attempts, int *range);




int main(void){

  char current_user_name[50];
  int tentativas, intervalo; 


  if(initial_screen(current_user_name) == 1){

      printf("Problema na leitura de string");
  }

  dif_screen(&tentativas, &intervalo);

  return 0;
}




int draw_number(int *range){

    srand(time(NULL));

    *range = (rand() % *range) + 1;


    return *range;
}




int initial_screen(char *player_name){



    printf("**********************************************************************************************************************\n");
    printf("\t\t\t\t\t\tBEM-VINDO AO JOGO DE ADIVINHAÇÃO\n");
    printf("**********************************************************************************************************************\n");

    printf("\n\n\n \t\t\t\t\t\t informe o nome do jogador:\n\n");
    int output = get_string(player_name); 
        
    
    return output;

}



void clean_screen(){


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





void dif_screen(int *attempts, int *range){


  clean_screen();


  int choice;


  printf("Escolha a dificuladade\n\n\n");

  printf("\t\t\t\t\t\t 1 - muito fácil : numeros de 0-10, 5 tentativas\n");
  printf("\t\t\t\t\t\t 2 - fácil : numeros de 0-100, 20 tentativas\n");
  printf("\t\t\t\t\t\t 3 - normal: numeros de 0-100, 10 tentativas\n");
  printf("\t\t\t\t\t\t 4 - difícil: numeros de 0-100, 5 tentativas\n");
  printf("\t\t\t\t\t\t 5 - muito difícil: numeros de 0-1000, 10 tentativas\n");

  printf("Faça sua escolha:");
  scanf("%d", &choice);

  switch (choice) {

    case 1 :

      *range = 10;
      *attempts = 5;

    break;

     case 2 :

      *range = 100;
      *attempts = 20;

    break;

    case 3:

      *range = 100;
      *attempts = 10;

    break;

    case 4:

      *range = 100;
      *attempts = 5;

    break;

    case 5:

      *range = 1000;
      *attempts = 10;

    break;
  }



}

