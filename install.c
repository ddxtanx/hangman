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
system("killall Terminal");
system("open -a 'Terminal'");
}
