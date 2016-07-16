#include <stdio.h>
#include <stdlib.h>
int main(void){
printf("Installing hangman onto system\n");
printf("Creating hangman binary\n");
system("clang hangmanv1.c -o hangman -lcurl");
printf("Creating absolute file locaiton\n");
system("cp ./hangman ~/");
printf("Adding command to bash_profile\n");
system("echo 'hangman(){ \n \t~/hangman \n}' >> ~/.bash_profile");
system("echo 'echo \" hangman to play hangman \"' >> ~/.bash_profile");
printf("Finished!\n");
printf("Now just close and re-open your console and then input hangman into your console to play!\n");
}
