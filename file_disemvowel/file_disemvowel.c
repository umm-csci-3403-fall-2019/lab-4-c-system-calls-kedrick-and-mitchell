#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#define BUF_SIZE 1024

bool is_vowel(char c) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
       
	return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I'|| c == 'o' || c == 'O' || c == 'u' || c == 'U');      
}



int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
	int i,k;
	for(i = 0, k = 0; i < num_chars; i++) {
                 if(!is_vowel(in_buf[i])) {
                         out_buf[k] = in_buf[i];
                         k++;
                 }
         }
         out_buf[num_chars] = '\0';

        return k;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
      char* in_buf = (char*) calloc(BUF_SIZE, sizeof(char));
      char* out_buf = (char*) calloc(BUF_SIZE, sizeof(char));

int non_vowel_len;
int read_size;

       while (!feof(inputFile)) {
        read_size = fread(in_buf, sizeof(char), (BUF_SIZE), inputFile);
        non_vowel_len = copy_non_vowels(read_size, in_buf, out_buf);
        fwrite(out_buf, sizeof(char), non_vowel_len, outputFile);
      }
      free(in_buf);
      free(out_buf);
}


int main(int argc, char *argv[]) {
    // You should set these to `stdin` and `stdout` by default
    // and then set them to user specified files when the user
    // provides files names as command line arguments.

    FILE *inputFile = stdin;
    FILE *outputFile = stdout;

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    //*******ask nic about fopen and using file ptrs****************
//    inputFile = fopen(File, "r");
//    outputFile = fopen(File, "w");// use argc to check how many arguments there are. if 1, if 2, if 3

if (argc > 2 || argc < 1) {
printf("please specify 2 or less files\n");
}

if (argc == 1) {
disemvowel(inputFile, outputFile);
}

if (argc == 2) {
inputFile = fopen(argv[1], "r");
disemvowel(inputFile, outputFile);
fclose(inputFile);
}

if (argc == 3) {
inputFile = fopen(argv[1], "r");
outputFile = fopen(argv[2], "w");
disemvowel(inputFile, outputFile);
fclose(inputFile);
fclose(outputFile);
}

}
