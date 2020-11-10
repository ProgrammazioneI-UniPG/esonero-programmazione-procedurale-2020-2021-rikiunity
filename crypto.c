//libraries that include all the functions used in the program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//function to make work fgets and scanf together flushing the input buffer
void flush_buffer(){
  int nextchar;
  do {
    nextchar = getchar();
  }while (nextchar != '\n' && nextchar != EOF);
}

int main(){
  //Numbers generator intialization based on the current time
  time_t t;
  srand((unsigned) time(&t));

  char k[128];
  char C[128];
  char M[128];

  int choice;
  int text_length;

  printf("\n");
  printf("\n");

  //function used to sospend the program for a while
  sleep(2);

  printf("                              ---------------\n");
  printf("                              |R4C ALGORITHM|\n");
  printf("                              ---------------\n");

  sleep(2);

  printf("\nPlease, insert the plaintext: ");
  //function used to enter an input in the program with max_lenght 128
  fgets(M,128,stdin);
  sleep(2);
  printf("\nThe text inserted is: %s", M);
  text_length = strlen(M) - 1;
  printf("Text is long %d characters\n", text_length);
  sleep(2);

  //do while used for the menu of choosing
  do{
    printf("\nNow, make your choice:\n");
    sleep(2);
    printf("[1] Insert the key manually\n");
    printf("[2] Generate the key automatically\n");
    printf("[3] Exit\n");
    printf("\nWaiting for choice... ");
    scanf("%d", &choice);
    if(choice == 3){
      break;
    }
    //function called here to flush the input buffer and make it empty
    flush_buffer();
  }while(choice != 1 && choice != 2);

  sleep(2);

  //if for the manual inserting of key with all the checks
  if(choice == 1){
    do{
      printf("\nPlease, insert the key: ");
      fgets(k,128,stdin);
      if(strlen(k) < strlen(M)){
        printf("\nKey must be longer or equals then plaintext\n");
        sleep(2);
        //if the key is shorter then plaintext the continue command restart the do while loop
        continue;
      }
      printf("\nThe key inserted is: %s\n", k);
      sleep(2);
    }while(strlen(k) < strlen(M));

    //for used to make the XOR operation between all the characters of the arrays
    for(int i = 0; i < strlen(k) - 1; i++)
      C[i] = (char)(M[i] ^ k[i]);
    printf("Ciphertext(Plaintext XOR Key):\n");
    for(int i = 0; i < strlen(k) - 1; i++){
      //%X hexadecimal print
      printf("%X ", C[i]);
    }


    sleep(2);

    //for used to make the inverse XOR operation
    for(int i = 0; i < strlen(k); i++){
      M[i] = (char)(C[i] ^ k[i]);
    }
      printf("\n");
    printf("\nPlaintext(inverse operation):\n");
    for(int i = 0; i < strlen(k); i++){
      printf("%c", M[i]);
    }

  }
  sleep(2);
  printf("\n");

  //similar to the if with the manual insert, but here the key is generated automatically with random numbers
  if(choice == 2){
    printf("Generated key: ");
    for(int i = 0; i < strlen(M) - 1; i++){
      k[i] = rand() % (128 - 32) + 32;
      printf("%c", k[i]);
    }

    printf("\n");

    for(int i = 0; i < strlen(k); i++){
      C[i] = (char)(M[i] ^ k[i]);
    }
    printf("\nCiphertext(Plaintext XOR Key):");
    for(int i = 0; i < strlen(k); i++){
      printf("%X ", C[i]);
    }

    sleep(2);

    for(int i = 0; i < strlen(k); i++){
      M[i] = (char)(C[i] ^ k[i]);
    }
    printf("\n");
    printf("\nPlaintext(inverse operation):");
    for(int i = 0; i < strlen(k); i++){
      printf("%c", M[i]);
    }
  }
  sleep(2);
  printf("\n");

  return 0;
}
