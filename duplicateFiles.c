#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZ 128
#define RSIZ 20


int checkStringEqual(char string1[], char string2 []){

    //two arrays to store the next the two values in the loop
    char cpystring1[100];
    char cpystring2[100];

    //copy and split the next two values using space delimiter into the splitString1 and splitString2 to get the non-digit part of the file
    char * splitString1 =  strtok(strcpy(cpystring1, string1), " "); 
    char * splitString2 =  strtok(strcpy(cpystring2, string2), " "); 


    //compare the split versions
    if(strcmp(splitString1, splitString2)){
        //if not equal : print the last part of the original strings which is the index part of the file in the order of which is smaller
        string1[strlen(string1) -1] < string2[strlen(string2) -1] ? 

        printf("%c %c", string1[strlen(string1) -1], string2[strlen(string2)- 1]) : 
        printf("%c %c", string2[strlen(string2) -1], string1[strlen(string1)- 1]);


    }
}



int main(void)
{

    // Read the file using fopen
    FILE *file = fopen("duplicate.in", "r");

    //check if file is valid
     if(file == NULL){
        printf("Error opening file");
        return 1;
    }    

    // variable to store the number of test cases
    int testCases;    

    //array to store the values in the file
    char fileValues[RSIZ][LSIZ];

    //initialize a counter variable to store the number of lines in the file
    int i = 0;

    //read the first line of the file as the number of test cases
    fscanf(file, "%d \n", &testCases);


    //loop through the rest of the file and determine the number of values usign the counter variable
    while(fgets(fileValues[i], LSIZ, file)){
        fileValues[i][strlen(fileValues[i]) - 1] = '\0';
        i++;
    }
        


    // loop through the file and store each values into the fileValues Array created
    for(int j=0; j < i; j++){
        fscanf(file, "%s", &fileValues[j]);
    }

    //declare an array to store only values which are not digits in the files
    char *stringValues[100];

    //loop through the fileValues Array
    for(int k = 0; k < i; k++){
        if(atoi(fileValues[k]) > 0){
        //if current value is a digit, it represents the number of testCases within each test case
            int y = 0;
            //loop 2 through the next filevalues[k] lines
            for(int l = k+1; l <= atoi(fileValues[k]) + k; l++){
                y++;

                //store each line value in the stringValues array
                stringValues[y] = fileValues[l];
               
               if(l == atoi(fileValues[k]) + k){     
                    //loop through the stringValues array and run the chekcStringEqual functions for the next two values in each loop
                    for(int z = 1; z < atoi(fileValues[k]); z ++){
                        checkStringEqual(stringValues[z], stringValues[z+1]);
                        
                    }

                }                
                
            }              

        }
    }
    return 0;
}
