#include <stdio.h>
#include <string.h>
#include "extras.h"
#include "base.h"

/*
// Get # of members
int Count(Record records[]){
	int count = 0;   //get # of records
    while(records[count].id!='\0') count++;
	return count;
}
*/

// Function: defragment() 
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
int defragment(Record records[]){
	// TODO: Modify this function as you need
	int check = 0;
	int count = Count(records);   //get # of records

	// for deleting empty record from the end
	for(int i = count-1; i>=0; i--){
		if(records[i].name[0] == '\0' && records[i].year == '\0' && records[i].rc == '\0' && records[i].gender == '\0'){
			printf("The #%d of list are empty\n", i+1);
			records[i].id = '\0';
			count --;
		}else
			break;
	}
	for(int i=0 ;i<count;i++){
		if(records[i].name[0] == '\0' && records[i].year == '\0' && records[i].rc == '\0' && records[i].gender == '\0'){
			printf("The #%d of list are empty\n", i+1);
			memcpy(&records[i],&records[count-1],sizeof(Record));
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


// TODO: Add more functions to fulfill the optional requirements

//extra
//search for name
// menu_#7
void search_name(Record records[]){
	// input one or more characters
	char str[20];	
	int count = Count(records);

	Record search[count];		// search have smaller number than records
	int sc = 0;
	char* comp = NULL;
	printf("Input character or string you want to search (name): ");
	scanf("%s",str);

	// loop the records
	for(int i=0; i<count; i++){
		// comparing the search characters and records
		if(str[1] == '\0'){
			// If user input one character, strchr
			char c = str[0];
			comp = strchr(records[i].name,c);
		}else{
			// If user input several characters, strstr
			comp = strstr(records[i].name,str);
		}
		// store the record to 'search' record
		if(comp != NULL){
			memcpy(&search[sc],&records[i],sizeof(Record));
			sc++;
		}
		comp = NULL;
	}

	// print the number of results
	printf("There are %d results.\n",sc);
	// print the search records
	if(sc>0){
		printf("------------------------------------------------------\n");
		for(int i=0; i<sc;i++){
			printf("%s\t",search[i].name);
			
			if(strlen(search[i].name)<4) 
				printf("\t");
			if(strlen(search[i].name)<8) 
				printf("\t");
			
			printf("- gender: %c\tyear: %d\trc: %c\n",search[i].gender, search[i].year,search[i].rc);
		}
		printf("------------------------------------------------------\n");
		printf("* T - Torrey / J - Jankiryew / K - Kyuper /\n  S - Sonyangwon / P - Philadelphos / C - Carmichael\n");
	}
	printf("\n");
	getchar();
}

//Sort function

void sort(Record records[]){

	int count = Count(records);

	// choose the criteria to sorting
	int choose = 0;
	printf("Choose the criteria you want to sort. (RC - 1, Year - 2, Gender - 3, Quit - 0): ");
	scanf("%d",&choose);
	
	// sort for name
	switch(choose){
		case 1:
			// 1. RC, call sort_RC
			sort_RC(records, count);
			break;
		case 2:
			// 2. year call sort_year
			sort_year(records,count);
			break;
		case 3:
			// 3. gender call sort_gender
			sort_gender(records, count);
			break;
	}

	getchar();
}

void swap(Record* a, Record* b){
	Record temp;
	memcpy(&temp,b,sizeof(Record));
	memcpy(b,a,sizeof(Record));
	memcpy(a,&temp,sizeof(Record));
    
    int t=0;
    t = a->id;
    a->id = b->id;
    b->id = t;
}

int RCtoNum(char rc){
	int num;
	switch(rc){
		case 'T':
			num = 0;
			break;
		case 'J':
			num = 1;
			break;
		case 'K':
			num = 2;
			break;
		case 'S':
			num = 3;
			break;
		case 'P':
			num = 4;
			break;
		case 'C':
			num = 5;
			break;
		default:
			num = 0;
    }
	return num;
}
// if there is empty, show empty rc, year, gender at the end.
void sort_RC(Record records[], int n){
	// using RCtoNum, sort.
	int min = 0;
	int check = 0;

	for(int i=0; i<n-1; i++){

		if(records[i].rc == '\0')
			min = 6;
		else
			min = RCtoNum(records[i].rc);
		
		int temp = 0;
		for(int j=i+1; j<n ; j++){
			if(min > RCtoNum(records[j].rc)){
				min = RCtoNum(records[j].rc);
				temp = j;
			}
		}
		if(temp != 0){
			swap(&records[i], &records[temp]);
			check = 1;
		}
	}

	// Let user know whether there are changes or not.
	if(check)
		printf("Result:\tSorting is completed according to RC.\n");
	else
		printf("Result:\tThere is no need for sorting according to RC.\n");
}


void sort_year(Record records[], int n){
	int check =0; // for checking there are changes by sorting
	int min = 0;

	for(int i=0 ; i<n-1 ;i++){
		min = records[i].year;
		int temp = 0;
		for(int j=i+1; j<n;j++){
			if(min > records[j].year && records[j].year != 0){
				min = records[j].year;
				temp = j;
			}
		}
		// if the year element is empty, pull that record to the end.
		if(min == 0){
			swap(&records[i], &records[n-1]);
			i--;
		}
		if(temp != 0){
			swap(&records[i], &records[temp]);
			check = 1;
		}
	}
	if(check)
		printf("Result:\tSorting is completed according to YEAR.\n");
	else
	 	printf("Result:\tThere is no need for sorting according to YEAR.\n");
}

void sort_gender(Record records[], int n){
	int check = 0;
	Record m[500], f[500], e[100];
	int mc = 0, fc = 0, ec=0;
	for(int i=0 ; i<n; i++){
		if(records[i].gender == 'm'){
			memcpy(&m[mc++], &records[i], sizeof(Record));
		}else if(records[i].gender == 'f'){
			memcpy(&f[fc++], &records[i], sizeof(Record));
		}else{
			memcpy(&e[ec++], &records[i], sizeof(Record));
		}
	}
	// According to the first record, the order whether f come first or m changed
	for(int i=0; i<n; i++){
		if(records[i].gender != '\0'){
			if(records[i].gender == 'm')	check = 1;
			else if(records[i].gender == 'f')	check = 2;
			break;
		}
	}

	if(check == 1){
		for(int i=0; i<fc; i++){
			memcpy(&records[i],&f[i],sizeof(Record));
			records[i].id = i+1;
		}
		for(int i = 0; i<mc; i++){
			memcpy(&records[i+fc],&m[i],sizeof(Record));
			records[i+fc].id = i+fc+1;
		}
	}else if(check == 2){
		for(int i=0; i<mc; i++){
			memcpy(&records[i],&m[i],sizeof(Record));
			records[i].id = i+1;
		}
		for(int i = 0; i<fc; i++){
			memcpy(&records[i+mc],&f[i],sizeof(Record));
			records[i+mc].id = i+mc+1;
		}
	}
	for(int i=0; i<ec; i++){
		memcpy(&records[i+mc+fc],&e[i],sizeof(Record));
		records[i+mc+fc].id = i+mc+fc+1;
	}

}


void ratio_gender(Record records[]){
	int male =0;
	int female =0;

	// Count the number of records
	int count = Count(records);
	for(int i =0; i<count;i++){
		if(records[i].gender == 'm') male++;
		else if(records[i].gender == 'f') female++;
	}

	float m = (1.0 * male)/count *100;
	float f = (1.0 * female)/count * 100;
	float un = (1.0 * (count - male - female))/count*100;

	printf("male : female = %d : %d\n", male,female);
	printf("-->\nmale = %.1f%%\nfemale %.1f%%\nundefined %.1f%%\n(total %d)\n", m,f,un, count);
}

