#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <regex.h>
#include <curl/multi.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  size_t written = fwrite(ptr, size, nmemb, stream);
  return written;
}
char* concat(char *s1, char *s2)
{
  char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
  //in real code you would check for errors in malloc here
  strcpy(result, s1);
  strcat(result, s2);
  return result;
  free(result);
}
int random_number(int min_num, int max_num)
{
  int result=0,low_num=0,hi_num=0;
  if(min_num<max_num)
  {
    low_num=min_num;
    hi_num=max_num+1; // this is done to include max_num in output.
  }else{
    low_num=max_num+1;// this is done to include max_num in output.
    hi_num=min_num;
  }
  srand(time(NULL));
  result = (rand()%(hi_num-low_num))+low_num;
  return result;
}
int main(void){
  system("python wordcreate.py");
  int wrong = 0;
  int doagain=1;
  do{
    int won = 0;
    char let;
    FILE *fp = fopen("word.txt", "r");
    int sz;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);
    char word[sz+1];
    fgets(word, sz+1, fp);
    fclose(fp);
    int lives = 11;
    int bools[strlen(word)];
    int index = 0;
    for(int x = 0; x<strlen(word); x++){
      bools[x] = 0;
    }
    do{
      printf("\t\t Lives: %i \n \n \t \t", lives);
      for(int x = 0; x<strlen(word); x++){
        if(bools[x]==1){
          printf(" %c", word[x]);
        } else{
          printf(" _");
        }
      }printf("\n");
        char c[1];
      do{
          printf("Please enter a letter\n");
          scanf("%s", c);
      }while((strcmp(c, "")==0)||strlen(c)>1);
      for(int x = 0; x<strlen(word); x++){
        let = word[x];
        if(let==*c){
          bools[x]=1;
        }
      }
      for(int x = 0; x<strlen(word); x++){
        let = word[x];
        if(let==*c){
          wrong = 0;
          break;
        } else{
          wrong = 1;
        }
      }
      if (wrong==1){
        lives--;
      }
      for(int x = 0; x<strlen(word); x++){
        if(bools[x]==0){
          won = 0;
          break;
        } else{
          won = 1;
        }
      }
    } while(won!=1 && lives>0);
    if(won==1){
      printf("Congrats you won! The word was: %s\n", word);
    } else{
      printf("Aww good try, the word was %s, wanna play again?\n", word);
    }
    printf("Would you like to know the definition of %s?(Y for yes, N for no)\n", word);
      char ans[1];
      scanf("%s", ans);
    if(strcmp(ans, "y")==0||strcmp(ans, "Y")==0){
        CURL *curl;
        FILE *fp;
        CURLcode curl_res;
        char *url = concat(concat("www.dictionary.com/browse/", word), "?s=t");
        char outfilename[FILENAME_MAX] = "def.html";
        curl = curl_easy_init();
        if (curl) {
            fp = fopen(outfilename,"wb");
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_res = curl_easy_perform(curl);
            /* always cleanup */
            curl_easy_cleanup(curl);
            fclose(fp);
        }
        else
        {
            printf("cURL error.\n");
        }
        
        fp = fopen(outfilename, "r");
        char buffer[10000];
        if(fp!=NULL){
            fread(buffer, 10000, 1, fp);
        } else{
            printf("Woops\n");
        }
        fclose(fp);
      system("open 'def.html'");
    }

    printf("Would you like to play again? (Y for yes, N for no)\n");
      char ans2[1];
      scanf("%s", ans2);
    if(strcmp(ans2, "y")==0||strcmp(ans2, "Y")==0){
      doagain = 1;
      system("python wordcreate.py");
    } else{
      doagain=0;
    }
  } while(doagain==1);
  return 0;
}
