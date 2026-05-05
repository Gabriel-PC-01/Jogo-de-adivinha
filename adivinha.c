#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




#define SIZE_STRING_NAME 50




int get_string(char *string);


int draw_number(int range);


int initial_screen(char *player_name);


void clean_screen();





    int main(void){

        char current_user_name[50];

        if(initial_screen(current_user_name) == 1){

            printf("Problema na leitura de string");
        }


        return 0;
    }




int draw_number(int range){

    srand(time(NULL));

    range = (rand() % range) + 1;


    return range;
}




int initial_screen(char *player_name){



    printf("**********************************************************************************************************************\n");
    printf("\t\t\t\t\t\tBEM-VINDO AO JOGO DE ADIVINHAÇÃO\n");
    printf("**********************************************************************************************************************\n");

    printf("\n\n\n \t\t\t\t\t\t informe o nome do jogador:\n\n");
    int output = get_string(player_name); 
        
    
    return 0;

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
