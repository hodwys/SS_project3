#include<stdio.h>
#include<math.h>
#include <string.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30
#define LINE_IN_TEXT 250


int get_line(char s[]){
    int count = 0;
    char c = '\0';
    for(int i =0; i<LINE; i++){

        if (scanf("%c", &(c)) == EOF)
            return 0;

        (s[i])=c;
        
        if(s[i] != '\n'){
            count++;
        }
        else{
            s[i] = '\0';
            break;
        }
    }
    
    return count; 
}

int get_word(char w[]){
    int count = 0;
    char c = '\0';
    for (int i = 0; i < WORD; i++) {

        scanf("%c", &(c));
        if(w[i] != '\r'){
             (w[i])=c;
             if ( (w[i]!='\n') && (w[i]!='\t') && (w[i]!=' ')) {
                count ++;
             }
            else{
                w[i] = '\0';
                count++;
                break;
        } 
        }
    }

    return count; 

}


int substring (char * str1, char * str2){

	int count = 0;

	for (int i = 0; i <=strlen(str1) - strlen(str2); i++){

    		for (int j = 0; j <= strlen(str2); j++){

       			if(*(str1 + i + j) == *(str2 + j)){
        			count++;       
      			} 
    		}
    		
        	if(count >= strlen(str2)){   
    			return 1;

		}else{
			count = 0;
		}
	}
	return 0;
    
}

int similar (char * s, char * t, int n){
    if(strlen(t)+n != strlen(s)){
        return 0;
    }
    int k = 0;
    int count = 0;
    for(int i = 0; i < strlen(s); i++){
        if(*(s+i) == *(t+k)){
            k++;
        }else{
            count++;
        }
    }
    if(count == n){
        return 1;
    }
    return 0;
}


void print_lines(char * str){

    char temp[LINE] = { 0 };
    get_line(temp);//save the second line that empty
    
   
   char s[LINE_IN_TEXT] = { 0 };
   int i = 0;
   int c = 1;

   while(i < LINE_IN_TEXT && c != 0){
    i++;
    c = get_line(s);
    if(substring(s,str)==1) {
            printf("%s\n",s);
            
        }
    
   }


}



void print_similar_words(char * str){

    char temp[LINE] = { 0 };
    get_line(temp);//save the second line that empty

   int text_len = LINE * LINE_IN_TEXT;
   char w[WORD] = { 0 };
   int i = 0;
   while(i<text_len){
    i++;
    get_word(w);
    if(similar(w,str,1) == 1 || similar(w,str,0) == 1){

        printf("%s\n",w);
   
    } 
     
}

}

int main(){

    
// // char s[LINE];
// // printf("%d",get_line(s));
// // char w[WORD];
// // printf("%d", get_word(w));
// // char str1[] = "aagabahj";
// // char str2[] = "abac";
// // printf("%d",substring(str1, str2));
// // char s[] = "cat";
// // char t[] = "a";
// // printf("%d", similar(s,t,2));

// //------------------------------------------------
    char word1[WORD] = { 0 };
    get_word(word1); //save first word
   // printf("the word is: %s\n",word1);
    char line1[LINE] = { 0 };
    get_line(line1); //save first line
    char ch = line1[strlen(line1)-1]; // a or b
   // printf("function: %c\n",ch);

    if(ch == 'a'){
        print_lines(word1);
    }
    if(ch == 'b'){
        print_similar_words(word1);
    }
}