#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int atoi();

//function to count appearance of each digit in file content
int countAppearance(char fileContent[], char countNo[]){
    //loop1-through the file content
    for(int i=0; i < strlen(fileContent); i++){

        //initialize a variable to 1 that represents the least appearance of each "string digit"
        int count = 1;
        //store that the count of that variable in the countNo array at index of i
        countNo[i] =  count; //mistake

        //loop2 - through the file content
        for(int j=0; j < strlen(fileContent); j++){
            //if value of fileContent of loop1 equals that of loop 2:
           //value of loop appears again, hence increase count and update array of that index
            if(fileContent[i] == fileContent[j] && i != j){
                count++;
                countNo[i] =  count;

            }else {
                //else retain count to be last value recorded
                countNo[i] = count;
            }

        }
            
    }

    
};

//function to check if number is selfdesribing or not: 
int checkDescribing(char fileContent[], char countNo[], int intFileContent[]){
    //array to hold "T" or "F" based on value of number array equaling current index
    char boolArray[100];

    //insert the string of digits as integers in intFileContent
    for (int j = 0; j < strlen(fileContent); j++) {
        intFileContent[j] = fileContent[j] - '0';
    }

    //loop3 through fileContent using
    for(int i=0; i<strlen(fileContent); i++){
        //initialize all i values of boolArray[i] to T
        boolArray[i] = 'T';

    //loop4 though fileContent using j
        for(int j=0; j<strlen(fileContent); j++){
            //if value of intFileContent at index j is equal to index of i 
            if(intFileContent[j] == i ){
                //if value of intFileContent at index i = value of countNo at index j         
                if(countNo[j] == intFileContent[i]){
                   //the current digit  fulfils self description, hence initialize the current index at boolArray to be true; 
                    boolArray[i] = 'T';

                }else {
                    //else the whole integer does not fulfil being self descriptive. Hence print "Not self descriptive"
                    boolArray[i] = 'F';
                    printf("Not self descriptive \n");

                    //Hence return 
                    return 0;
                    }
            }
            
        }
    }
            //if all digits have been looped through and each fulfills self description, then the whole integer is self descriptive.Hence print self descriptive!
            if(strlen(boolArray) - 1 <= strlen(fileContent)){
                if(fileContent[strlen(fileContent) - 1]= '\r'){
                    fileContent[strlen(fileContent) - 1]= '\0';
      };
                printf("self descriptive \n");
            }
      return 0;
}



int main(){
    //access the file
    FILE *file = fopen("describing.in", "r");

    char countNo[250]; //array to store the number of times each digit appears
    int intFileContent[250]; //array to store the integer equivalent of file content
    

    //read number of test cases from the file
    char testCases[250]; // array to store the number of test cases
    fgets(testCases, 250, file);//store the number of test cases into testCases array

    char fileContent[250]; //array to store each case value as string

    //Error handling if file reading is unsuccesful
    if(file == NULL){
        printf("Error opening file");
        return 1;
    }

    //convert number of testCases to int
    int numCases = atoi(testCases);

    //check if number of testCases is greater than 1
    if(numCases < 1){
        printf("Error! Number of inputs cannot be less than 1");
        return 1;
    }

    //while each test case is truthy:
    while(fgets(fileContent, 250, file)){

        //call the countAppearance function
        countAppearance(fileContent, countNo);
        //call the checkDescribing function
        checkDescribing(fileContent, countNo, intFileContent);
    
       
    }
        //close file
        fclose(file);    




    return 0;
}