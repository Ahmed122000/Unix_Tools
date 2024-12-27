#include<stdio.h> 
#include<string.h>
#include<unistd.h>


int line =1;

/**
 * @brief function to handle printing the line number excluding the blanks
 * 
 * @param fptr a pionter for the input source
 */
void printWithLinesNoBlank(FILE* fptr){
    char content[1024]; 
    while(fgets(content, sizeof(content), fptr)) {
        if(strcmp(content, "\n") != 0)
            printf("%d %s", line++, content);
        else
            printf("\n");
    }
 }
 /**
  * @brief function to write the line numbers before the content of the line
  * 
  * @param fptr a file pointer for the input source
  */
void printWithLineNumber(FILE* fptr){
    char content[1024];

    while(fgets(content, sizeof(content), fptr)) {
        printf("%d %s", line++, content);
    }
}

/**
 * @brief function to write the content of input without any enumeration 
 * 
 * @param fptr a file pionter for the input source
 */
void printWithoutLineNumber(FILE* fptr){
    char content[1024];
    while(fgets(content, sizeof(content), fptr)) {
        printf("%s", content);
    }
}

/**
 * @brief first feature of the tool: read the input form file, then print it on the screen 
 * 
 * @param address the path (relative path), to read the file
 */
void readFromFile(char* address, int flag){
    FILE *fptr;
    fptr = fopen(address, "r");
    
    //return an error message and exit the tool in case of wrong path
    if(fptr == NULL){
        printf("Sorry, file not found\n");
        printf("we will exit\n");
        return; 
    }

    //read the input from the file and print it
    if(flag & 2 == 2){
        printWithLinesNoBlank(fptr);
    }
    else if(flag & 1 == 1){
        printWithLineNumber(fptr);
    }
    else{
        printWithoutLineNumber(fptr);
    }
}

/**
 * @brief second feature of the tool: read the input form standard input, then print it on the screen
 * 
 */
void readFromSTD(int flag){
    char buffer[1024];
    //while there is input read it then print it 
    if((flag & 2) == 2){
        printWithLinesNoBlank(stdin);
    }
    else if(flag & 1 == 1){
        printWithLineNumber(stdin);
    }
    else{
        printWithoutLineNumber(stdin);
    } 
}


int main(int argc, char *argv[]){
    
    int opt;
    int flag = 0; 
    while((opt = getopt(argc, argv, "nb")) != -1)
    {
        switch(opt){
            case 'n':
                flag |= 1; 
                break; 
            case 'b':
                flag |= 2; 
                break;
        }

    }

    if(optind == argc || strcmp(argv[optind], "-") == 0 ){
        readFromSTD(flag);

    }
    else{
        for(; optind < argc; optind++){        
            readFromFile(argv[optind], flag);
        }
    }
    return 0; 
}