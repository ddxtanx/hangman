#include <stdio.h>
#include <stdlib.h>
int main(void){
printf("Installing hangman onto system\n");
printf("Creating hangman binary\n");
system("clang hangman.c -o hangman -lcurl");
printf("Creating absolute file locaiton\n");
system("cp ./hangman ~/");
printf("Adding command to bash_profile\n");
system("echo 'hangman(){ ~/hangman } echo \"use hangman to play hangman\"'>> ~/.bash_profile");
printf("Finished!\n");
printf("Input hangman into your console to play!\n");
}
