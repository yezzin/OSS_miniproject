#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int main(){

	Record records[MAX_RECORDS];
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[]){

	// TODO: Modify this function as you need
	int defr = 0;

	if(!strcmp(input, "1"))			//Create 1 & 2
		add_a_record(records);
	else if(!strcmp(input, "2"))	//Delete
		delete_a_member(records);
	else if(!strcmp(input, "3"))	//
		print_all_records(records);	
	else if(!strcmp(input, "4"))	//Update	
		update_detail(records);
	else if(!strcmp(input, "5"))	//Read 1
		list_record(records);
	else if(!strcmp(input, "6")){	//extras
		defr = defragment(records);
		if(defr) printf("\n**Defragment successful!\n");
		else	printf("\n**Defragment failed. There is no empty record.\n");
	}
	else if(!strcmp(input, "7"))	//extras
		search_name(records);
	else if(!strcmp(input, "8"))	//read
		load(records);
	else if(!strcmp(input, "9"))	//read
		save_export(records);
	else if(!strcmp(input, "12"))	//extras
		display_stats(records);	
	else if(!strcmp(input, "13"))	
	;
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}


// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("*******************************\n");
	printf(" Students in Handong Dormitory \n");
	printf("*******************************\n");
	printf(" 1. Add a new member\n");
	printf(" 2. Delete a member\n");
	printf(" 3. Print all members\n");
	printf(" 4. Update member details\n");
	printf(" 5. Students list\n");
	printf(" 6. Defragment\n");
//	printf(" 6. School year ratio (RC)\n");
	printf(" 7. Gender ratio(RC)\n");
	printf(" 8. Load a new data file\n");	
	printf(" 9. Save(export) to a data file\n");
	printf(" 10. Search (name/age/RC)\n");
	//printf(" 11. \n");
	
	printf(" 99. Quit\n");
}


