// Marcus Schumann Room #8
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> //sleep timer

//colors
#define RED     "\x1b[0;31m"
#define BOLDRED "\x1b[1;31m"

#define GREEN   "\x1b[0;32m"
#define BOLDGREEN   "\x1b[1;32m"

#define YELLOW  "\x1b[0;33m"
#define BOLDYELLOW  "\x1b[01;33m"

#define BLUE    "\x1b[0;34m"
#define BOLDBLUE    "\x1b[1;34m"

#define MAGENTA "\x1b[0;35m"
#define BOLDMAGENTA "\x1b[1;35m"

#define CYAN    "\x1b[0;36m"
#define BOLDCYAN    "\x1b[1;36m"

#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define REVERSED "\x1b[7m"
#define RESET   "\x1b[0m"
						

// Methods
void displayOpeningSplash(void);
int displayMenu(void);

void TypeWriter(char *arr);
int checkInput(char option[10]);

int getFileInfo(int num);
void gameOver(int winOrlose);

int main(void) {

    int i,choice= 0;

    char name[256];
	char option[10];
	int result;

	displayOpeningSplash();

    printf("Please enter your name: "); //Input any number of array inputs
    scanf("%s",name);
	puts("\n\n");

    printf("Hello %s welcome to the rpgGame!\n",name);
	puts("\n\n");

	while(choice != 99) {

		choice = displayMenu();

		if(choice == 1){
			system("clear");
			puts("Type "BOLDMAGENTA "h" RESET" for help\n\n\n\n\n\n\n\n\n\n\n\n");
		
			int playedGames = getFileInfo(1);
			
			//PROLOGUE (if never played)//
			if(playedGames == 0){
				//Question 1
				while(1){
					//Introduction
					TypeWriter("\nYour name is ");
					printf(BOLDBLUE"%s"RESET,name);
					TypeWriter(", and you're on a trip to see family in Canada....\n");
					TypeWriter("Everything seems to be going normally. You went through security and\nfound your seat on the plane.\n");
					TypeWriter("Pretty soon you're in the air and the flight attendants are going\ndown the aisles to give out drinks\n");
					TypeWriter("Would you like something to drink sir?\n");
						puts("\t1. ask for water");
						puts("\t2. ask for a sprite ");
						puts("\t3. ask for a beer ");
						puts("\t4. tell her to go away\n");
					
					TypeWriter(BOLDGREEN REVERSED"What Say You?:"RESET" ");
					scanf("%s",option);
					result = checkInput(option);
				
					while(result  == 0 || result == -1){
					
						if(result == 0 && result != 1){
							if(strcmp("h",option) == 0 || strcmp("H",option) == 0){
								//help
								printf(BOLDMAGENTA UNDERLINE "HELP:\n"RESET);
								printf("\nThis is an interactive game. Use numbers to make\nchoices in the game\n");
								
							}
						}
							
						printf("\nWrong input type try again..\n\n");
						printf(BOLDGREEN REVERSED"What Say You?:"RESET" ");
						scanf("%s",option);
						result = checkInput(option);
							
					}
				
				
					//extract integer out of string
					int num_choice;
					char *ptr = option;
					
					while (*ptr){
						if (isdigit(*ptr)) {
							int val = strtol(ptr, &ptr, 10);
							num_choice = val;
						} else {
							ptr++;
						}
					}
				
					choice = num_choice;

					switch(choice) {
						case 1:
							printf("Here you go sir\n");
							printf("You like water.\n\n");
							break;
						case 2:
							printf("Here you go sir\n");
							printf("You like sprite.\n\n");
							break;
						case 3:
							printf("Here you go sir\n");
							printf("You like beer.\n\n");
							break;
						case 4:
							printf("She looks at you angrily, then keeps going down the aisles\n\n");
							break;
						case  99:
							printf("You quit the game\n\n");
							exit(0);
							break;
						default :
							printf(BOLDRED"\n\nNot a valid choice, Try Again.\n"RESET);
					}
				
					if(choice == 1){
						break;
					}
					
					if(choice == 2){
						break;
					}
					
					if(choice == 3){
						break;
					}
					
					if(choice == 4){
						break;
					}
				}
				
				//Question 2
				while(1){
			
					puts("You decide to take nap........");
					puts("you have a long way to go and you hate flying");
					puts("zzzzzzzzzzzzzzzzzz");

					puts("\n\n\n\n\n\n\n\n");

					puts("An hour passes and the pilot gives out a message: ");
					puts("Attention all passengers, we will be experiencing turbulence for the next hour. A large storm has formed in front of us");
					puts("How do you react?:");

					puts("\t1. Scream and freak out!-You start hyperventilating");
					puts("\t2. Remain calm\n");

					printf(BOLDGREEN REVERSED"What Say You?:"RESET" ");
					scanf("%s",option);
					result = checkInput(option);
					
					while(result  == 0 || result == -1){
						
						if(result == 0 && result != 1){
							if(strcmp("h",option) == 0 || strcmp("H",option) == 0){
								//help
								printf(BOLDMAGENTA UNDERLINE "HELP:\n"RESET);
								printf("\nThis is an interactive game. Use numbers to make\nchoices in the game\n");
								
							}
						}
						
						printf("\nWrong input type try again..\n\n");
						printf(BOLDGREEN REVERSED"What Say You?:"RESET" ");
						scanf("%s",option);
						result = checkInput(option);
						
					}
				
					//extract integer out of string
						int num_choice;
						char *ptr = option;
						
						while (*ptr){
							if (isdigit(*ptr)) {
								int val = strtol(ptr, &ptr, 10);
								num_choice = val;
							} else {
								ptr++;
							}
						}
					
					choice = num_choice;
					
					switch(choice) {
						case 1:
							printf("You begin screaming like a 3 year old girl and get up and start running around like a headless chicken. You die from a heartattack\n");
								//run GAMEOVER METHOD
							exit(0);
							choice = 99;
							break; /* optional */
						case 2:
							printf("You remain calm as the plane starts to shake\n");
							puts("A couple of minutes later the shaking becomes stronger and you glance around to see frightened passengers");
							puts("The plane is then struck with lightning and the plane starts FALLING");
							puts("\n");
							puts("You wake up and find yourself among the wreckage of the plane. You're head is hurting from the crash and you feel dizzy");
							puts("No one else is alive, but you know one thing: You must SURVIVE");
							
							
							int numInput;
							puts("\nDo you wish to continue?\ndo you accept the challenge to survive as long as possible?\n");
							puts("\t1. yes");
							puts("\t2. no\n");
							scanf("%d",&numInput);
							
							
							if(numInput == 1){
								
							}else{
								printf("too bad");
							}
							
							break; /* optional */
						case  99:
							printf("\n\nYou quit the game\n\n");
							exit(0);
							break;
						default :
							printf(BOLDRED"\n\nNot a valid choice, Try Again.\n"RESET);
					}
					
					if(choice == 1){
						break;
					}
				
					if(choice == 2){
						break;
					}
				}
			}
			//END of PROLOGUE//
			
			
			//MAIN GAME//
			
			//Question1
			while(1){
				TypeWriter("\n\nOk let's begin...\n");
				TypeWriter("So where were we...\n");
				TypeWriter("Oh yeah, You find yourself in a clearing near the plane wreckage.\n");
				puts("\t1. to the North there is a dense forest");
				puts("\t2. to the East is the plane");
				puts("\t3. to the West you can see mountains in the distance");
				TypeWriter("\nWhere do you go?\n");
				
				TypeWriter(BOLDGREEN REVERSED">>"RESET" ");
				scanf("%s",option);
				result = checkInput(option);
				
				while(result  == 0 || result == -1){
					
					if(result == 0 && result != 1){
						if(strcmp("h",option) == 0 || strcmp("H",option) == 0){
							//help
							printf(BOLDMAGENTA UNDERLINE "HELP:\n"RESET);
							printf("\nThis is an interactive game. Use numbers to make\nchoices in the game\n");
							
						}
					}
						
					printf("\nWrong input type try again..\n\n");
					printf(BOLDGREEN REVERSED"What Say You?:"RESET" ");
					scanf("%s",option);
					result = checkInput(option);
						
				}


				//extract integer out of string
					int num_choice;
					char *ptr = option;
					
					while (*ptr){
						if (isdigit(*ptr)) {
							int val = strtol(ptr, &ptr, 10);
							num_choice = val;
						} else {
							ptr++;
						}
					}
				
				choice = num_choice;
				
				switch(choice) {
					case 1:
						printf("You venture forwards into the dense forest\n");
						puts("You get eaten by a pack of wolves");
						puts("Did you forget you're in the wilderness?");
						gameOver(0);
						break;
					case 2:
						puts("You go East towards the plane wreckage");
						puts("You sift through the wreckage looking for anything you can use to survive");
						puts("You find a backpack!");
						puts("in the backpack you find some stuff:");
						puts("\t1.matches");
						puts("\t2.snickers - because snickers satisfies");
						break;
					case 3:
						puts("You decide to trek to the mountains");
						puts("Without food or water you die within the week");
						gameOver(0);
						break;
					case  99:
						printf("You quit the game\n\n");
						exit(0);
						break;
					default :
						printf(BOLDRED"\n\nNot a valid choice, Try Again.\n"RESET);
				}
				
				if(choice == 1){
					break;
				}
				
				if(choice == 2){
					break;
				}
				
				if(choice == 3){
					break;
				}
										
			}
			//Question 1 END
			
			
			//Question 2
			system("clear");
			while(1){
				puts("It's getting and late and the Sun is slowly disappearing");
				puts("You need to make a fire...");
				puts("\t1. Gather firewook and kindling, and use the matches");
				puts("\t2. Freeze to death");
				puts("\t3. Shout for help");
				
				printf(BOLDGREEN REVERSED"What Say You?:"RESET" ");
				scanf("%s",option);
				result = checkInput(option);
				
				while(result  == 0 || result == -1){
					
					if(result == 0 && result != 1){
						if(strcmp("h",option) == 0 || strcmp("H",option) == 0){
							//help
							printf(BOLDMAGENTA UNDERLINE "HELP:\n"RESET);
							printf("\nThis is an interactive game. Use numbers to make\nchoices in the game\n");
							
						}
					}
						
					printf("\nWrong input type try again..\n\n");
					printf(BOLDGREEN REVERSED"What Say You?:"RESET" ");
					scanf("%s",option);
					result = checkInput(option);
						
				}


				//extract integer out of string
					int num_choice;
					char *ptr = option;
					
					while (*ptr){
						if (isdigit(*ptr)) {
							int val = strtol(ptr, &ptr, 10);
							num_choice = val;
						} else {
							ptr++;
						}
					}
				
				choice = num_choice;
				
				switch(choice) {
					case 1:
						puts("Good job.");
						puts("you find an axe while scavenging for wood");
						puts("and some rocks that look like they might give off a spark");
						puts("do you want to store the rocks?");
						puts("\t1. yes.");
						puts("\t2. no. \n");
						//gameOver(0);
						break;
					case 2:
						puts(":(");
						gameOver(0);
						break;
					case 3:
						puts("Wow great decision!");
						puts("You are ripped apart by an angry bear who hears you");
						gameOver(0);
						break;
					case  99:
						printf("You quit the game\n\n");
						exit(0);
						break;
					default :
						printf(BOLDRED"\n\nNot a valid choice, Try Again.\n"RESET);
				}
				
				if(choice == 1){
					break;
				}
				
				if(choice == 2){
					break;
				}
				
				if(choice == 3){
					break;
				}					
			}
			//Question 2 END
		
			break;
		
		
		}else if(choice == 2){
			system("clear");
			//game stats
				int gamesPlayed = 0;
				int totalDeaths = 0;
				int totalWins = 0;
		
			puts("+-----------------------------------------------------------------------------+\n");

			//TotalGames played
				for(i = 0;i < 25;i++){
					printf(" ");
				}
				printf("Total Games Played:   "BOLDRED);
				gamesPlayed = getFileInfo(1);
				printf("%d\n\n"RESET,gamesPlayed);

			//TotalDeaths
				for(i = 0;i < 25;i++){
					printf(" ");
				}
				printf("Total Wins:   "BOLDRED);
				totalWins = getFileInfo(2);
				printf("%d\n\n"RESET,totalWins);

			//LongestTimeSurvived
				for(i = 0;i < 25;i++){
					printf(" ");
				}
				printf("Total Deaths:   "BOLDRED);
				totalDeaths = getFileInfo(3);
				printf("%d\n\n"RESET,totalDeaths);
				
			puts("+-----------------------------------------------------------------------------+");
			
			puts("["BOLDGREEN"1"RESET"] Back");
			puts("["BOLDRED"99"RESET"] Exit");
			
			puts("+-----------------------------------------------------------------------------+");
			
			TypeWriter(BOLDGREEN REVERSED">"RESET" ");
			scanf("%d",&choice);
			
			if(choice == 1){
				
				
			}else if(choice == 99){
				printf("You quit the game\n\n");
				exit(0);
			}
				
		}else if(choice == 3){
			system("clear");
			puts("+-----------------------------------------------------------------------------+\n");
			
			puts("Not implemented yet: version 2.0 :(\n");
			
			puts("+-----------------------------------------------------------------------------+");
			
			puts("["BOLDGREEN"1"RESET"] Back");
			puts("["BOLDRED"99"RESET"] Exit");
			
			puts("+-----------------------------------------------------------------------------+");
			
			TypeWriter(BOLDGREEN REVERSED">"RESET" ");
			scanf("%d",&choice);
			
			if(choice == 1){
				
				
			}else if(choice == 99){
				printf("You quit the game\n\n");
				exit(0);
			}
			
		}else if(choice == 4){
			system("clear");
			puts("+-----------------------------------------------------------------------------+\n");
			
			//help
				printf(BOLDMAGENTA UNDERLINE "HELP:\n"RESET);
				printf("\nThis is an interactive game. Use numbers or short words to make choices in the \ngame.\n\n");
				
			puts("+-----------------------------------------------------------------------------+");
			
			puts("["BOLDGREEN"1"RESET"] Back");
			puts("["BOLDRED"99"RESET"] Exit");
			
			puts("+-----------------------------------------------------------------------------+");
			
			TypeWriter(BOLDGREEN REVERSED">"RESET" ");
			scanf("%d",&choice);
			
			if(choice == 1){
				
				
			}else if(choice == 99){
				printf("You quit the game\n\n");
				exit(0);
			}
				
		}else if(choice == 99){
			printf("You quit the game\n\n");
			exit(0);
		}else{
			printf("Sorry con't recognize that input type\n\n");
		}
	}
}

void displayOpeningSplash(void) {

	system("clear");

	//OPENING TITLES//
	usleep(75000 * 10);  /* sleep for 100 milliSeconds */

	//frame1
		puts("\n\n\n\n\n\n\n\n\n");
		puts("+-----------------------------------------------------------------------------+");
		puts("+-----------------------------------------------------------------------------+");
		usleep(50000); 
		system("clear");
	//frame2
		puts("\n\n\n\n\n\n\n\n");
		puts("+-----------------------------------------------------------------------------+");
		puts(BOLDBLUE"  \\___ \\| | | | '__\\ \\ / / \\ \\ / / _` | | | | |_ |/ _` | '_ ` _ \\ / _ \\ "RESET);
		puts("+-----------------------------------------------------------------------------+");
		usleep(50000); 
		system("clear");
	//frame3
		puts("\n\n\n\n\n\n\n");
		puts("+-----------------------------------------------------------------------------+");
		puts(BOLDBLUE" | (___  _   _ _ ____   _____   ____ _| | | |  __  __ _ _ __ ___   ___ ");
		puts("  \\___ \\| | | | '__\\ \\ / / \\ \\ / / _` | | | | |_ |/ _` | '_ ` _ \\ / _ \\ ");
		puts("  ____) | |_| | |   \\ V /| |\\ V / (_| | | | |__| | (_| | | | | | |  __/"RESET);
		puts("+-----------------------------------------------------------------------------+");
		usleep(50000); 
		system("clear");

	//frame4
		puts("\n\n\n\n\n\n");
		puts("+-----------------------------------------------------------------------------+");
		puts(BOLDBLUE"  / ____|                (_)          | |  / ____|                     ");
		puts(" | (___  _   _ _ ____   _____   ____ _| | | |  __  __ _ _ __ ___   ___ ");
		puts("  \\___ \\| | | | '__\\ \\ / / \\ \\ / / _` | | | | |_ |/ _` | '_ ` _ \\ / _ \\ ");
		puts("  ____) | |_| | |   \\ V /| |\\ V / (_| | | | |__| | (_| | | | | | |  __/"RESET);
		puts("+-----------------------------------------------------------------------------+");
		usleep(50000); 
		system("clear");
		
	//frame5
		puts("\n\n\n\n\n");
		puts("+-----------------------------------------------------------------------------+");
		puts(BOLDBLUE"   _____                  _            _    _____                      ");
		puts("  / ____|                (_)          | |  / ____|                     ");
		puts(" | (___  _   _ _ ____   _____   ____ _| | | |  __  __ _ _ __ ___   ___ ");
		puts("  \\___ \\| | | | '__\\ \\ / / \\ \\ / / _` | | | | |_ |/ _` | '_ ` _ \\ / _ \\ ");
		puts("  ____) | |_| | |   \\ V /| |\\ V / (_| | | | |__| | (_| | | | | | |  __/");
		puts(" |_____/ \\__,_|_|    \\_/ |_| \\_/ \\__,_|_|  \\_____|\\__,_|_| |_| |_|\\___|"RESET);
		puts("\n+-----------------------------------------------------------------------------+");
		printf("                                                            ");
		TypeWriter("Version 1.0");
		usleep(150000); 
		system("clear");
		
	//frame6
		puts("\n\n\n\n\n");
		puts("+-----------------------------------------------------------------------------+");
		puts(BOLDBLUE"   _____                  _            _    _____                      ");
		puts("  / ____|                (_)          | |  / ____|                     ");
		puts(" | (___  _   _ _ ____   _____   ____ _| | | |  __  __ _ _ __ ___   ___ ");
		puts("  \\___ \\| | | | '__\\ \\ / / \\ \\ / / _` | | | | |_ |/ _` | '_ ` _ \\ / _ \\ ");
		puts("  ____) | |_| | |   \\ V /| |\\ V / (_| | | | |__| | (_| | | | | | |  __/");
		puts(" |_____/ \\__,_|_|    \\_/ |_| \\_/ \\__,_|_|  \\_____|\\__,_|_| |_| |_|\\___|"RESET);
		puts("\n+-----------------------------------------------------------------------------+");
		printf(BOLDGREEN);
		printf("                                                            Version 1.0");
		printf(RESET);
		//usleep(100000 * 10); 

	//prompt to continue
		puts("\n\n\n\n\n\n\n");
		printf("Press ENTER to continue........");
		getchar();

}

int displayMenu(void) {
	int choice= 0;

	//MENU//
		system("clear");
		
		puts("+-----------------------------------------------------------------------------+");
		puts(BOLDGREEN"                                Survival Game                              1.0"RESET);
		puts("                        _");
		puts("                       /#\\");
		puts("                      /###\\     /\\");
		puts("                     /  ###\\   /##\\  /\\");
		puts("                    /      #\\ /####\\/##\\");
		puts("                   /  /       /     # / ##\\             _       /\\");
		puts("                 // //  /\\  /    _/  /    #\\ _         /#\\    _/##\\    /\\");
		puts("                // /   /  \\     /   /    #\\ \\        _/###\\_ /   ##\\__/ _\\");
		puts("               /  \\   / .. \\   / /   _   { \\ \\   _/       / //    /    \\");
		puts("     /\\      /    /\\  ...  \\_/   / / \\   } \\ | /  /\\  \\ /  _    /  /    \\ /\\\\ ");
		puts("+-----------------------------------------------------------------------------+");

		puts("["BOLDGREEN"1"RESET"] Play");
		puts("["BOLDBLUE"2"RESET"] Game Stats");
		puts("["BOLDYELLOW"3"RESET"] Pirate Mode");
		puts("["BOLDMAGENTA"4"RESET"] Help");
		puts("");
		puts("["BOLDRED"99"RESET"] Exit");
		puts("");
		puts(" Marcus Schumann                                   Copyright or something 2018  ");
		puts("+-----------------------------------------------------------------------------+");
		TypeWriter(BOLDGREEN REVERSED">"RESET" ");
		scanf("%d",&choice);

		return choice;
}

void TypeWriter(char *arr) {
    int len = strlen(arr);
    int i;
    for(i = 0; i < len; i++) {
        putchar(arr[i]);
        usleep(30000);  /* sleep for 35 milliSeconds */
		fflush(stdout);
    }
}


int checkInput(char option[10]) {
	
	//return 0 if alphanumeric
	//return 1 if has alpha characters
	//return 2 if has numbers
	for(int i = 0; i < 10; i++){
		if(isalnum(option[i])){
			if(isalpha(option[i])){
				return 0; //alpha character
				break;
			}
			
			if(isdigit(option[i])){
				return 1; // a integer
				break;
				
			}
			
		}else{
			return -1;
			break;
		}
	}
	
	return -1;
}


int getFileInfo(int num) {
	
	int gamesPlayed = 0;
	int totalDeaths = 0;
	int totalWins = 0;
	
	FILE *rptr;
	
	if((rptr = fopen("stats.txt","r")) == NULL)
	{
		fopen("stats.txt","w");
	}
	else{
		while(!feof(rptr)){
			
			fscanf(rptr,"%d %d %d",&gamesPlayed,&totalWins,&totalDeaths);
			
			//printf("%d %d %d\n",gamesPlayed,totalDeaths,longestTime);
			//fprintf(wptr," %d %d %d\n",gamesPlayed,totalDeaths,longestTime);
			
			if(num == 1){
				return(gamesPlayed);
			}else if(num == 2){
				return(totalWins);
			}else{
				return(totalDeaths);
			}
			
			fclose(rptr);
			
			break;
		}
	}
	
	return 0;
}


void gameOver(int winOrlose) {
	
	int gamesPlayed = 0;
	int totalDeaths = 0;
	int totalWins = 0;
	
	FILE *rptr;
	FILE *wptr;

	
	wptr = fopen("stats.txt","a");
	

	if((rptr = fopen("stats.txt","r")) == NULL)
	{
		puts("File could not be opened");
	}
	else{
		
		while(!feof(rptr)){
			//int ok,ok1,ok2;
			fscanf(rptr,"%d %d %d",&gamesPlayed,&totalWins,&totalDeaths);
			
			gamesPlayed++;
			
			if(winOrlose == 1){
				//win
				totalWins++;
			}else if(winOrlose == 0){
				//loss
				totalDeaths++;
			}
		
			wptr = fopen("stats.txt","w");
			fprintf(wptr,"%d %d %d",gamesPlayed,totalWins,totalDeaths);
			
			fclose(rptr);
			fclose(wptr);
			
			exit(0);
		}
	}
}