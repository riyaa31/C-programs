//RIYA SHAH, 201817129
//Q2, ASSIGNMENT 2, CS 2004


#include <stdio.h>  //INPUT OUTPUT HEADER FILE 
#include <sys/stat.h> //POSIX HEADER FILE
#include <sys/types.h> //POSIX HEADER FILE
#include <fcntl.h>  //USED TO OPEN A FILE IN LINUX
#include <unistd.h> //USED TO CLOSE A FILE IN LINUX
#include <errno.h> // USED TO DETECT ERRORS
#define FILENAME "Test2.txt"


#define READ_MAX_SIZE 1024
#define BLOCK_SIZE 1024
#define DEBUG false
#if DEBUG
#else
#define debug(args)
#endif

//Following are the functions( or methods) to read, write and copy the files to a destination file

void outputline(char * buf) //buf points to a character array
{
    int bytes = 0;
    while(buf[bytes] != '\0') {
        bytes++;
    }
    write(STDOUT_FILENO, buf, bytes);
}

void inputline(char * buf) //replaces new line
{
    size_t bytes_read;
    bytes_read = read(STDIN_FILENO, buf, READ_MAX_SIZE);
    buf[bytes_read - 1] = '\0'; 
}

void copyFile(int from_fd, int to_fd) 
{
    size_t bytes_read;
    char buf[BLOCK_SIZE];
    do {
        bytes_read = read(from_fd, buf, READ_MAX_SIZE);
        write(to_fd, buf, bytes_read);
    } while(bytes_read == BLOCK_SIZE);
}

int main(int argc, char *argv[]) 
{
    char path_from[READ_MAX_SIZE], path_to[READ_MAX_SIZE];
    int inputFile, outputFile;

    outputline("Please input file: ");
    inputline(path_from);
    inputFile = open(path_from, O_RDONLY);
    
    debug(("%d, %d, %s\n", inputFile, errno, path_from));
   
    if(inputFile == -1) {
        outputline("File cannot be opened. ");
        
        switch errno {
            
            case EACCES:
                outputline("Permission denied.\n");
                break;
            case ENOENT:
                outputline("File not found.\n");
                break;
            default:
                outputline("Unknown error.\n");
        }
        
        return 1;
    }

    outputline("output file: ");
    inputline(path_to);
    outputFile = open(path_to,
                     O_WRONLY | O_CREAT | O_EXCL,
                     S_IRWXU | S_IRGRP | S_IROTH);
    
    debug(("%d, %d, %s\n", outputFile, errno, path_to));
    
    if(outputFile == -1) {
        
        switch errno {
            
            case EACCES:
                outputline("Permission denied. \n");
                break;
            case EEXIST:
                outputline("File already exists.\n");
                break;
            default:
                outputline("Unknown error.\n");
        }

        return 1;
    }

    copyFile(inputFile, outputFile);
    close(outputFile);
    close(inputFile);
    
    return 0;
}