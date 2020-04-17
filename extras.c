#include <stdio.h>
#include <string.h>
#include "extras.h"

// Function: defragment() __ menu#13
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
int defragment(Record records[]){
	// TODO: Modify this function as you need
	printf("defragment(): this function needs to be implemented\n\n");
	int check = 0;
	int count = 0;   //get # of records
    while(records[count].id!='\0') count++;

	for(int i = count-1; i>=0; i--){
		if(records[i].name[0] == '\0' && records[i].year == '\0' && records[i].rc == '\0' && records[i].gender == '\0'){
			printf("The #%d of list are empty\n", i+1);
			records[i].id = '\0';
			count --;
		}else
			break;
	}
	printf("count = %d\n", count);
	for(int i=0 ;i<count;i++){
		if(records[i].name[0] == '\0' && records[i].year == '\0' && records[i].rc == '\0' && records[i].gender == '\0'){
			printf("The #%d of list are empty\n", i+1);
			memcpy(&records[i],&records[count-1],sizeof(Record));
			/*
			records[count-1].name[0] == '\0';
			records[count-1].year == '\0';
			records[count-1].rc == '\0';
			records[count-1].gender = '\0';
			*/
			records[count-1].id = '\0';
			records[i].id = i+1;
			count --;
			check = 1;
		}
	}
	for(int i = count-1; i>=0; i--){
		if(records[i].name[0] == '\0' && records[i].year == '\0' && records[i].rc == '\0' && records[i].gender == '\0'){
			printf("The #%d of list are empty\n", i+1);
			records[i].id = '\0';
			count --;
		}else
			break;
	}
	return check;	// TODO: return 1 if defragment succeed; return 0 otherwise 
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void display_stats(Record records[]){
	// TODO: Modify this function as you need
	printf("display_stats(): this function needs to be implemented\n\n"); // TODO: Remove this line
}


// TODO: Add more functions to fulfill the optional requirements
void search_name(Record records[]){
	
}
