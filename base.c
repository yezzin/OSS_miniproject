#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"


// Get # of members
int Count(Record records[]){
	int count = 0;   //get # of records
    while(records[count].id!='\0') count++;
	return count;
}

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// print all records on memory
void print_all_records(Record records[]){

	// TODO: Modify this function as you need    
    int count = Count(records);   //get # of records

    printf("T - Torrey / J - Jankiryew / K - Kyuper / S - Sonyangwon / P - Philadelphos / C - Carmichael\n");
    printf("\tName\t\tYear\tRC\tGender\n");
    for(int i=0 ; i<count ;i++){
        if(strlen(records[i].name)>=8)
            printf("%d.\t%s\t%d\t%c\t%c\n",records[i].id,records[i].name,records[i].year,records[i].rc,records[i].gender);
        else
            printf("%d.\t%s\t\t%d\t%c\t%c\n",records[i].id,records[i].name,records[i].year,records[i].rc,records[i].gender);
    }
    printf("\n");
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// 1. You can "add" data from report.txt.
//After 4.18, add data from not report.txt but data.txt
// 2. Or you can "add" a record(data) by taking your input.
void add_a_record(Record records[]){

	// TODO: Modify this function as you need    
    int count = Count(records);   //get # of records
    
    int w;  // whether input from file or from standard input. 1 - .txt 2 - stdin
	printf("Choose whether you add a record from \"data.txt\" or from your input.\n");
    printf("(from .txt - 1 / from your input - 2) ");
    scanf("%d",&w);
    
    if(w == 1){

        FILE *fpd = fopen("data.txt","r");
        char buffer[128];   //to get line until EOF
        int i=0;
        if(fpd == NULL){ 
            printf("ERROR during open file.\n");
            exit(-1);
        }

        fgets(buffer, sizeof(buffer), fpd);
        if(buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';    //trim '\n'
        
        if(buffer[0]!='\n'&&buffer[0]!='\0'){
            records[count].id = count+1;
            char str1[20];
            char str2[20];
            char str_rc[20];
            sscanf(buffer,"%s %s %c %d %s",str1, str2,&records[count].gender, &records[count].year,str_rc);
            strcat(str1," ");
            strcat(str1,str2);
            strcpy(records[count].name,str1);
            records[count].rc = str_rc[0];
        }
        fclose(fpd);
        getchar();
    }else if(w == 2){
        Record newmem;
        newmem.id = count+1;
        printf("- 1. New member's name (with one space between input): ");

        getchar();  //get rid of rest '\n' made when take 'w' input
        int space = 0;
        while(1){
            fgets(newmem.name,20,stdin);
            for(int i=0 ;i <strlen(newmem.name) - 1 ;i++)
                if(newmem.name[i] == ' ') space++;
            if(space == 1) break;
            else{
                printf("Please input name again with \'one\' space.\nName: ");
                space = 0;
            }
        }
        newmem.name[strlen(newmem.name)-1] = '\0'; 

        printf("- 2. New member's year: ");
        scanf("%d",&newmem.year);
        
        printf("- 3. New member's rc \n(Torrey - T / Jankiryew - J / Kyuper - K / Sonyangwon - S / Philadelphos - P / Carmichael - C): ");
        char c;
        while(1){
            scanf(" %c", &c);
            if(c != 'T' && c != 'J' && c != 'K' && c != 'S' && c != 'P' && c != 'C')
                printf("Input again: ");
            else
                break;
        }
        newmem.rc = c;

        printf("- 4. New member's gender (m/f) ");
        while(1){
            scanf(" %c",&newmem.gender);
            if(newmem.gender != 'f' && newmem.gender != 'm')
                printf("Input again: ");
            else
                break;
        }

        //copy newmem struct into records
        memcpy(&records[count],&newmem,sizeof(Record));
        //Before going back to main, get rid of rest '\n'
        getchar();
    }
}


// TODO: Add more functions to fulfill the requirements

// Function: list_record()
// Input: record - array of Records
// Output: none
// According to user specified conditions, Read
// r. You can take a list according to only one rc you want to see.
// y. You can take a list according to only one year(admission year) you want to see. 
void list_record(Record records[]){
    char list;

    int count = Count(records);   //get # of records
    //printf("count : %d\n", count);
    
    int check =0;   // Is/Are there member/s according to your input?
    printf("Input r/y (r - RC / y - year) ");
    scanf(" %c",&list);
    if(list == 'r'){
        char rc;    //What RC?
        printf("What list do you want?(T/J/K/S/P/C): ");
        scanf(" %c",&rc);
        printf("List according to RC: %c\n",rc);
        for(int i=0; i<count;i++){
            if(records[i].rc == rc){
                check = 1;
                printf(" Name: %s Year: %d Gender: %c\n", records[i].name, records[i].year, records[i].gender);
            }
        }
        if(check == 0)
            printf("There is no member according to that RC.\n\n");
        else
            printf("\n");
        getchar();
        
    }else if(list == 'y'){
        
        int year;
        //What year?
        printf("Input year(of admission) ");
        scanf("%d",&year);
        printf("List according to admission year\n");
        for(int i=0 ;i<count;i++){
            if(records[i].year == year){
                check = 1;
                printf(" Name: %s RC: %c Gender: %c\n", records[i].name, records[i].rc, records[i].gender);
            }
        }        
        if(check == 0)
            printf("There is no member according to that year.\n\n");
        else
            printf("\n");
        //Before going back to main, get rid of rest '\n'
        getchar();
    }
}

// Function: load()
// Input: record - array of Records
// Output: none
// Read/Load from text.file(filesystem)
void load(Record records[]){

    //reset existing memory
    int count = Count(records);   //get # of records
    
    // Clear the records existing by memset with 0
    for(int i=0; i<count;i++)
        memset(&records[i],0,sizeof(Record));

    //open data.txt on read mode
    FILE *fp = fopen("data.txt", "r");
    char buffer[128];   //to get line until EOF
    int i=0;
    if(fp == NULL){ 
        printf("ERROR during open file.\n");
        exit(-1);
    }
    //Repeat until EOF, load all records from report.txt
    while(!feof(fp)){
        
        fgets(buffer, sizeof(buffer), fp);
        if(buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';    //trim '\n'
        
        if(buffer[0]!='\n'&&buffer[0]!='\0'){
            records[i].id = i+1;
            char str1[20];
            char str2[20];
            char str_rc[20];
            sscanf(buffer,"%s %s %c %d %s",str1, str2,&records[i].gender, &records[i].year,str_rc);
            strcat(str1," ");
            strcat(str1,str2);
            strcpy(records[i].name,str1);
            if(str_rc[0] == 'T' || str_rc[0] == 'J'|| str_rc[0] =='K'||str_rc[0] =='S'||str_rc[0] =='P'||str_rc[0] =='C')
                records[i].rc = str_rc[0];
            i++;
        }
    }
    print_all_records(records);
    //clear standard output
    fflush(stdout);
    //close file
    fclose(fp);
}

// Function: save_export()
// Input: record - array of Records
// Output: none
//Read from txtfile
void save_export(Record records[]){
    //open report.txt on write mode
    FILE *fp = fopen("report.txt","w");

    int count = Count(records);   //get # of records
    //while(records[count].id!='\0') count++;
    for(int i=0;i<count;i++){
        fputs("======================\n",fp);
        fprintf(fp,"Name: %s - %c\n",records[i].name, records[i].gender);
        fprintf(fp,"Year: %d\n",records[i].year);
        char rc = records[i].rc;
        switch(rc){
            case 'T':
                fprintf(fp,"RC: Torrey");
                break;
            case 'J':
                fprintf(fp,"RC: Jankiryew");
                break;
            case 'K':
                fprintf(fp,"RC: Kuyper");
                break;
            case 'S':
                fprintf(fp,"RC: Sonyangwon");
                break;
            case 'P':
                fprintf(fp,"RC: Philadelphos");
                break;
            case 'C':
                fprintf(fp,"RC: Carmichael");
                break;
            default:
                fprintf(fp,"RC: ");
        }
        fputs("\n",fp);
    }
    //close file
    fclose(fp);
}

//Update
void update_detail(Record records[]){
    print_all_records(records);
    
    int count = Count(records);   //get # of records

    Record old;
    Record update;

    // ask which student you want to update, input number(id) of list.
    int id;
    printf("Which student's information do you want to update?\n");
    while(1){
        printf("** Input the number of list above: ");
        scanf("%d",&id);
        if(id <= count){
            memcpy(&old,&records[id-1],sizeof(Record));
            break;
        } 
        else printf("Please input again smaller the end number of list.\n");
    }

    // update information of records[id - 1]
    // if you want leave the same for specific elements, input '\n' or '0'.
    //printf("If you enter for an element, that element will be left same.\n");
    
    // Name
    getchar();
    printf("** 1. Input name to update\n(If you want to leave this element same, input 'enter'): ");
    // check # of space in name input;
    while(1){
        int space = 0;
        fgets(update.name,20,stdin);
        //If you enter, leave same.
        if(update.name[0] == '\n'){
            strcpy(update.name, old.name);
            break;
        }
        for(int i=0; i<strlen(update.name) - 1; i++)
            if(update.name[i] == ' ') space++;
        if(space == 1){
            update.name[strlen(update.name)-1] = '\0';      //trim '\n'
            break;
        } 
        else
            printf("Please input updating name again with \'one\' space.\nName: ");
    }
    
    // Assigned year
    printf("** 2. Input assigned year (integer) to update\n(If you leave same, input 0): ");
    scanf("%d",&update.year);
    
    if(update.year == 0) update.year = old.year;
    
    // RC
    printf("** 3. Input RC to update\n(If you leave same, input 0): ");
    while(1){
        scanf(" %c",&update.rc);
        if(update.rc == '0') {  //leave same
            update.rc = old.rc;
            break;
        }
        if(update.rc != 'T' && update.rc != 'J' && update.rc != 'K' && update.rc != 'S' && update.rc != 'P' && update.rc != 'C')
            printf("Input again: ");
        else
            break;
    }
    
    // Gender
    printf("** 4. Input gender to update\n(If you leave same, input 0): ");
    while(1){
        scanf(" %c",&update.gender);
        if(update.gender == '0') {
            update.gender = old.gender;
            break;
        }
        if(update.gender != 'f' && update.gender != 'm')
            printf("Input again: ");
        else
            break;
    }

    // show updated list. compare old and updated
    printf("-----------------------------------------------------\n");
    printf("you input updating inform of #%d\n",id);
    printf("Old name = %s\t->\tUpdating name = %s\n",old.name,update.name);
    printf("Old assigned year = %d \t->\tUpdating year = %d\n",old.year,update.year);
    printf("Old rc = %c\t->\tUpdating rc = %c\n",old.rc,update.rc);
    printf("Old gender = %c\t->\tUpdating gender = %c\n",old.gender, update.gender);
    printf("-----------------------------------------------------\n");
    // ask whether to save that updating, 
    printf("*** Will you update the information? Input (yes - y /no - n) ");
    char yes_no;     // yes or no
    scanf(" %c",&yes_no);
    
    if(yes_no == 'y'){   // yes -> memcpy(&records[id-1],&update,sizeof(Record))
        update.id = id;
        memcpy(&records[id-1],&update,sizeof(Record));
    }
    print_all_records(records);
    getchar();      // trim '\n' for menu
}

//Delete
void Delete(Record records[]){
    int count = Count(records);   //get # of records
    int op = 0;
    
    printf("Delete a member(input 1) or a specific elements(input 2), quit (input 0): ");
    scanf("%d",&op);

    if(op == 0) {
        getchar();
        return;
    }
    else if(op == 1)
        delete_member(records);
    else if(op == 2)
        delete_detail(records);

    print_all_records(records);
    getchar();
}

void delete_member(Record records[]){
    int num = 0;
    printf("Choose # member of list you want delete: ");
    scanf("%d",&num);
    records[num-1].name[0] = '\0';
    records[num-1].year = '\0';
    records[num-1].rc = '\0';
    records[num-1].gender = '\0';
}

void delete_detail(Record records[]){
    int num = 0;
    int choose = 0;
    printf("Choose # of list you want delete specific element: ");
    scanf("%d",&num);
    printf("Input number what you want to delete(Name - 1, Year - 2, RC - 3, Gender - 4): ");
    scanf("%d",&choose);
    switch(choose){
        case 1:
            records[num-1].name[0] = '\0';
            break;
        case 2:
            records[num-1].year = '\0';
            break;
        case 3:
            records[num-1].rc = '\0';
            break;
        case 4:
            records[num-1].gender = '\0';
            break;
        default:
            break;
    }
}
