#include <stdio.h>

#define WIDTH 7
#define HEIGHT 6
#define HIGHSCORE 10

void selectWindow();
void selectGameMode();
int printingInstructions(char* instructions);
void displayBoard();
void readConfiguration();

int main() {
    // selectWindow();
    readConfiguration();
    return 0;
}

void selectWindow() {
    int selectedValue = printingInstructions("Type 0 for New Game\nType 1 for Load Game\nType 2 for Quit\n");
    
    //directing the program to where the user selected
    switch (selectedValue)
    {
    case 0:
        selectGameMode();
        break;
    case 1:
        printf("Load Game Selected\n");
        break;
    case 2:
        printf("Quit Game Selected\n");
        break;
    default:
        printf("You have not selected a correct value! Try Again!\n");
    }
}

void selectGameMode() {
    int selectedValue = printingInstructions("Type 0 for Human Vs Human\nType 1 for Human Vs Computer\n");

    //directing the program to where the user selected
    switch (selectedValue)
    {
    case 0:
        displayBoard();
        printf("Human Vs Human Selected\n");
        break;
    case 1:
        printf("Human Vs Computer Selected\n");
        break;
    default:
        printf("You have not selected a correct value! Try Again!\n");
    }
}

//printing intructions for users
int printingInstructions(char* instructions){
    int temp;
    printf("%s", instructions);
    printf("Type: ");
    scanf("%d", &temp);
    return temp;
}

void displayBoard() {
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH +1; j++){
            printf("| ");
        }
        printf("\n");
    }
}

void readConfiguration(){
    FILE* ptr;
    char ch;

    ptr = fopen("config.xml", "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    printf("content of this file are \n");

    do {
        ch = fgetc(ptr);
        printf("%c", ch);
    } while (ch != EOF);
 
    fclose(ptr);
}