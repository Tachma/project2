#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

//====FUNCTIONS====//
void set_prices();
void signup_user();
void login_user();
void view_user(int current_user);
void modify_user(int current_user);
void calculate_cost(int current_user, int i);

//====VARIABLES====//
int admin_login_done = 0 , set_done = 0 , reg_user_done = 0 , user_counter = 0 , at_least_one_flight = 0;
int to_ath,to_rom,to_mad,to_lon,to_ber,to_ams,to_nyw,to_bei,to_chi,to_syd; //Prices set by the admin.

//====STRUCTS====//
struct passenger{
	char name[20];
	char surname[20];
	struct address{
		char name[20];
		int number;
		char location[20];
		int postal;
	}addr;
	char username[30];
	char password[20];
	char flights[3][4][11]; 
};
struct passenger pass[20];


int main(int argc, char *argv[]) {
	char option[10];

	
	
	do{
		system("cls");
		
		printf("\n***************** HOME SCREEN *****************\n");
		printf("\n-For admin login type 'admin'.");
		printf("\n-For user login type 'user'.");
		printf("\n-For termination type '0'.");
		printf("\nWhat do you select: ");
		
	
		do{ //INPUT CHECK.
			scanf(" %s",option);
			if(strcmp(option,"admin")!=0 && strcmp(option,"user")!=0 && strcmp(option,"0")!=0 ){ // STRCMP FUNCTION TO COMPARE STRINGS.CONTAINED IN STRING.H .
				printf("\nWrong input.Try again:");
				continue;
			}
			else if(strcmp(option,"user")==0 && admin_login_done == 0){
				printf("\nYou have to login as admin first to set the prices.Try again:");
				continue;
			}
			else{
				break;
			}
		}while(1);
		
		if(strcmp(option,"admin")==0){
			system("cls");
			char username[10],password[10];
			
			printf("\n***************** ADMIN SCREEN *****************\n");
			
			do{
			 
				printf("Type the admin username: ");
				scanf(" %s",username);
				printf("Type the admin password: ");
				scanf(" %s",password);
				
				if(strcmp(username,"airadmin")!=0 || strcmp(password,"Air123")!=0 ){
					printf("\nWrong credentials.Try again.\n ");
					continue;
				}
				break;
			}while(1);
			printf("\nLogged in successfully");
			 
			
			char choice_admin;
			
			do{
				sleep(2);
				
				system("cls");
				
				printf("\n***************** ADMIN SCREEN *****************\n");
				
				
				printf("\n\n--a.Set Prices.\n--b.Log Out.\nWhat do you select:");
				do{
					
					scanf(" %c",&choice_admin);
					if(choice_admin != 'a' && choice_admin != 'b'){
						printf("Wrong Input.Try again: ");
						continue;
					}
					break;
				}while(1);
				
				if(choice_admin == 'a'){
					set_prices();
					admin_login_done = 1; //FLAG THAT SHOWS THAT PRICES HAS BEEN SET.
				}
				
			}while(choice_admin == 'a');
		}
		
		
		if(strcmp(option,"user")==0){
			char choice_user;
			do{
				
				
				system("cls");
			
				printf("\n***************** USER SCREEN *****************\n");
				printf("---a.Register\n---b.Login\n---c.Logout\n");
			
				do{
				
					
					printf("Type your option:");
					scanf(" %c",&choice_user);
					
					if(choice_user != 'a' && choice_user != 'b' && choice_user != 'c'){
						printf("\nWrong input try again.");
						continue;
					}
					else if(reg_user_done == 0 && choice_user == 'b'){
						printf("\nYou have to register at least one user before login.Try again.");
						continue;
					}else if(user_counter == 19){
						printf("\nNo more avaible space for registering an other user.Select an other option.");
						continue;
					}
					break;
				}while(1);
				
				if(choice_user == 'a'){
					signup_user();
					reg_user_done = 1;
				}
				else if(choice_user == 'b'){
					login_user();
				}
				
				
			}while(choice_user != 'c');
		
		}
		
		
	}while(strcmp(option,"0")!=0);
	
	
	return 0;
}


//START OF THE FUNCTION SET_PRICES==============
void set_prices(){
	
	printf("\n====== Set Prices ======\n");
	
	if(set_done == 0){
	
		printf("\nSet the flight cost to Athens:");
		scanf("%d",&to_ath);
		
		printf("\nSet the flight cost to Rome:");
		scanf("%d",&to_rom);
		
		printf("\nSet the flight cost to Madrid:");
		scanf("%d",&to_mad);
		
		printf("\nSet the flight cost to London:");
		scanf("%d",&to_lon);
		
		printf("\nSet the flight cost to Berlin:");
		scanf("%d",&to_ber);
		
		printf("\nSet the flight cost to Amsterdam:");
		scanf("%d",&to_ams);
		
		printf("\nSet the flight cost to New York:");
		scanf("%d",&to_nyw);
		
		printf("\nSet the flight cost to Beijing:");
		scanf("%d",&to_bei);
		
		printf("\nSet the flight cost to Chicago:");
		scanf("%d",&to_chi);
		
		printf("\nSet the flight cost to Sydney:");
		scanf("%d",&to_syd);
		
		set_done = 1;
	}
	else{
		printf("\nSet the flight cost to Athens:");
		scanf("%d",&to_ath);
	}
	
	
}
//END OF THE FUNCTION SET_PRICES==============

//START OF THE FUNCTION SIGNUP_USER==============
void signup_user(){
	system("cls");
	
	printf("========== User Signup ==========\n");
	
	printf("Type your name: ");
	scanf(" %s",pass[user_counter].name);
	
	printf("Type your surname: ");
	scanf(" %s",pass[user_counter].surname);
	
	printf("Type your address name: ");
	scanf(" %s",pass[user_counter].addr.name);
	
	printf("Type your address number: ");
	scanf("%d",&pass[user_counter].addr.number);
	
	printf("Type your address location: ");
	scanf(" %s",pass[user_counter].addr.location);
	
	printf("Type your address postal code: ");
	scanf("%d",&pass[user_counter].addr.postal);
	
	strcat(pass[user_counter].username,pass[user_counter].surname); //combines the two strings. Found in <string.h> library.
	
	for(int i = 0; i< strlen(pass[user_counter].username); i++ ){ //Lower casing every letter. strlen included in string.h library.
		pass[user_counter].username[i] = tolower(pass[user_counter].username[i]);
	}
	
	strcat(pass[user_counter].username,"456"); //And adds the '456' in the end of the previously lowered cased surname.
	
	printf("Type your password: ");
	scanf(" %s",pass[user_counter].password);
	
	user_counter++;
	
	
}
//END OF THE FUNCTION SIGNUP_USER==============

//START OF THE FUNCTION LOGIN_USER==============
void login_user(){
	int current_user;
	system("cls");
	
	printf("========== User Login ==========\n");

	do{
	 	char username[20] , password[20];
	 	int pass_check = 0 , user_check = 0 ;
	 	
		printf("Type the user username: ");
		scanf(" %s",username);
		printf("Type the user password: ");
		scanf(" %s",password);
		
		int i;
		for(i = 0 ; i < user_counter; i++){
			if(strcmp(username,pass[i].username) == 0 && strcmp(password,pass[i].password) == 0){
				user_check = 1;
				pass_check = 1;
				current_user = i;
				break;
			}
		}
		
		if(pass_check == 0 || user_check == 0){
			printf("\nYour username or password are not correct try again.");
			continue;
		}
		else{
			printf("\nSuccessfully logged in!");
			sleep(2);
			break;
		}
		
	}while(1);
	
	int user_login_choice;
	
	do{
		system("cls");
		
		printf("========== User Page ==========\n");
		printf("--- 1.View\n--- 2.Modify\n--- 3.Calculate\n--- 4.Payment\n--- 5.Most Expensive\n--- 6.Logout\n");
		
		do{ //Input check.
			printf("Type your option: ");
			scanf("%d",&user_login_choice);
			if(user_login_choice > 6 || user_login_choice < 1){
				printf("Wrong input.Try again:");
				continue;
			}	
			break;
		}while(1);
		
		if(user_login_choice == 1){
			view_user(current_user);
		}
		else if(user_login_choice == 2){
			modify_user(current_user);
		}
		else if(user_login_choice == 3){
			
			printf("\n---------CALCULATE COST PAGE---------\n");
			
			int i;
			for(i = 0;i<3; i++);
				calculate_cost(current_user,i);
				
		}
		
	}while(user_login_choice != 6);
	
}
//END OF THE FUNCTION LOGIN_USER==============

//START OF THE FUNCTION VIEW_USER==============
void view_user(int current_user){
	
	printf("\n---------VIEW PAGE---------\n");
	printf("--Name: %s\n",pass[current_user].name);
	printf("--Surname: %s\n",pass[current_user].surname);
	printf("--Address: %s\n",pass[current_user].addr.name);
	printf("--Address number: %d\n",pass[current_user].addr.number);
	printf("--Address location: %s\n",pass[current_user].addr.location);
	printf("--Postal Code: %d\n",pass[current_user].addr.postal);
	printf("--Username: %s\n",pass[current_user].username);
	printf("--Password: %s\n",pass[current_user].password);
	
	if(at_least_one_flight == 1){
		
	}
	
	sleep(10);
}
//END OF THE FUNCTION VIEW_USER==============

//START OF THE FUNCTION MODIFY_USER==============
void modify_user(int current_user){
	
	printf("\n---------MODIFY PAGE---------\n");
	
	printf("Type your new address name: ");
	scanf(" %s",pass[current.user].addr.name);
	
	printf("Type your new address number: ");
	scanf("%d",&pass[current_user].addr.number);
	
	printf("Type your new address location: ");
	scanf(" %s",pass[current.user].addr.location);
	
	printf("Type your new address postal code: ");
	scanf("%d",&pass[current_user].addr.postal);
	
	printf("\nChange Successfull!");
	
	sleep(3);
	
	
}
//END OF THE FUNCTION MODIFY_USER==============

//START OF THE FUNCTION CALCULATE_COST==============
void calculate_cost(int current_user , int i){
	
	char sel[4];
	
	printf("\nBook your flight number %d --- \n",i);
	
	printf("-Type ROM for Rome\n-Type MAD for Madrid\nType LON for London\n-Type BER for Berlin\n-Type AMS for Amsterdam\n-Type NYW for New York\n-Type BEI for Beijing\n-Type CHI for Chicago\n-Type SYD for Sydney\n");
	
	do{
		
		printf("What do you select: ");
		scanf("%s",sel);
		
		
		if(strcmp(sel,"ROM") == 0){
			
		}
		else if(strcmp(sel,"MAD") == 0){
			
		}
		else if(strcmp(sel,"LON") == 0){
			
		}
		else if(strcmp(sel,"BER") == 0){
			
		}
		else if(strcmp(sel,"AMS") == 0){
			
		}
		else if(strcmp(sel,"NYW") == 0){
			
		}
		else if(strcmp(sel,"BEI") == 0){
			
		}
		else if(strcmp(sel,"CHI") == 0){
			
		}
		else if(strcmp(sel,"SYD") == 0){
			
		}
		else{
			printf("Wrong input try again.");
			continue;
		}
		
		break;
	}while(1);
	
	
}