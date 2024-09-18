#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define inventory_size 10
#define playerhealth 100 
#define enemyhealth 50 

void playerdamage();
void enemydamage();
void gamestart();
void cellroom();
void cellroomLOCKPICKED();
void chapter1();
void chapter1plb();
void hallway();
void closet();

int main(){                                                                                                                     // GAME INITIALIZATION
    char response;
 
    printf("Do you wish to wake up?\n Y/N?");
    scanf(" %c", &response);

    if(response == 'Y' || response == 'y') {
        gamestart();
    } else {
        return 0;
    }  
}

void gamestart(){
    char response[4];                                                                                                           // LIMITING TO 4 JUST INCASE THE USER TYPES PL WRONG OR SOMETHING

    cellroom();

    printf("You awaken in a dark cell... \nYou have no recollection of how you got here.");
    printf("The main room you are imprisoned in is dimly lit by two torches.\nYou vaguely make out a door to your right.\n");
    printf("A small metallic object on the ground catches your eye and it appears to be skinny enough to pick the lock.\n");
    printf("Type 'PL' to attempt picking the lock.");
    scanf(" %s", response);

    if(strcmp(response,"PL") == 0 || strcmp(response, "pl") == 0){                                                              // (strcmp(response, " TEXT ") == 0 || strcmp(response, " text ") == 0) THIS USES 'TEXT' TO INITIALIZE THE NUMBER GENERATOR
        srand(time(NULL));                                                                                                      

        int rnd = rand() % 100;                                                                                                 // SETS THE RANGE FROM 0 TO 100 

        if(rnd < 70){                                                                                                           // 70 PERCENT CHANCE TO PICK THE LOCK
            printf("You picked the lock successfully.\n");
            printf("The lock opens...\n");

            chapter1();

        } else {                                                                                                                // 30 PERCENT CHANCE TO BREAK THE LOCK
            printf("The lockpick broke...\n");
            printf("You failed to pick the lock.\n");

            chapter1plb();
        }

    } else {
        return;
    }

}

void chapter1(){                                                                                                                // LOCK BROKE OR THE LOCK WAS PICKED/SMASH "TRUE GAME START" 
    char response[10];                                                                                                          // 10
    
    cellroomLOCKPICKED();

    printf("You find yourself out of the damp cell from which you awoke.\n");
    printf("The air in the decrepid stone built room is still.\n");
    printf("A noise outside of the room is drawing near, you notice a closet.\nDo you hide?");
    printf("Type 'yes' or 'no'.\n");
    scanf(" %s", response);

    if(strcmp(response, "yes") == 0 || strcmp(response, "Yes") == 0 || strcmp(response, "YES") == 0){
        closet();
    } else {
        printf("A loud bang at the door makes you flinch in fear.\nThe bang did not break the door.\n Do you decide to enter the closet to hide or search for other means?\n");
        printf("Type 'hide' or 'search'.");
        scanf(" %s", response);

        if(strcmp(response, "hide") == 0 || strcmp(response, "Hide") == 0 || strcmp(response, "HIDE") == 0){
            closet();
        } else {
            printf("You decide to search the room.\n");
            
        }
    }
}

void chapter1plb(){                                                                                                             // LOCK PICK BROKE ------> SMASH LOCK WITH ROCK ------> CHAPTER 1 
    char response[10];                                                                                                          // Increasing buffer size for responses [10]
    
    cellroom();

    printf("The lock keeps you within the cell.\n");
    printf("A large rock on the ground grabs your attention.\nYou consider smashing it against the lock to free yourself.\nType 'Smash' to attempt to break the lock.");
    scanf(" %s", response);

    if(strcmp(response, "Smash") == 0 || strcmp(response, "smash") == 0 || strcmp(response, "SMASH") == 0){
        srand(time(NULL));

        int rnd = rand() % 100;

        if(rnd < 70){                                                                                                           // 70 PERCENT CHANCE TO SMASH THE LOCK
            printf("You broke the lock successfully.\n");
            printf("Will you exit the cage? Type 'yes' or 'no'.");
            scanf(" %s", response);

            if(strcmp(response, "yes") == 0 || strcmp(response, "YES") == 0 || strcmp(response, "Yes") == 0){
                printf("You exit the cage.\n");

                chapter1();
            } else {
                return;
            }
        } else {                                                                                                                // 30 PERCENT CHANCE TO FAIL SMASHING THE LOCK
            printf("The rock did not break the lock.\n");
            printf("Do you decide to exit the cage? Type 'yes' or 'no'.");
            scanf(" %s", response);

            if(strcmp(response, "yes") == 0 || strcmp(response, "YES") == 0 || strcmp(response, "Yes") == 0){
                printf("You decide not to exit the cage.\nA noise outside the room you are in startles you.\n");
                printf("Swiftly is your exit from the cage as you ready yourself for the room.\n");

                chapter1();
            } else {
                return;
            }
        }
    }
}

void cellroom(){
    printf("########################\n");
    printf("#        T        C    #\n");
    printf("#                      #\n");
    printf("#                     D#\n");
    printf("#########             O#\n");
    printf("#       #             O#\n");
    printf("#   X   #L            R#\n");
    printf("#       #      T       #\n");
    printf("########################\n");
}

void cellroomLOCKPICKED(){
    printf("########################\n");
    printf("#        T        C    #\n");
    printf("#                      #\n");
    printf("#              X      D#\n");
    printf("#########             O#\n");
    printf("#       #             O#\n");
    printf("#       #             R#\n");
    printf("#       #      T       #\n");
    printf("########################\n");
}

void hallway(){
    printf("###########################################################\n");
    printf("#                                                         #\n");
    printf("#                                                         #\n");
    printf("#D                                                       D#\n");
    printf("#O X                                                     O#\n");
    printf("#O                                                       O#\n");
    printf("#R                                                       R#\n");
    printf("#                                                         #\n");
    printf("#                                                         #\n");
    printf("###########################################################\n");
}

void closet(){
    printf("#########\n");
    printf("#       #\n");
    printf("#   X   #\n");
    printf("#       #\n");
    printf("#########\n");
}

void playerdamage(){

}

void enemydamage(){

}
