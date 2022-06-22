#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int title(char name[100])
{
    printf("Enter your name: ");
    scanf("%s",name);
    return 0;
}
int snakeWaterGun(char you, char comp){
    // returns 1 if you win, -1 if you lose and 0 if draw
    // Condition for draw
    // Cases covered:
    // ss
    // gg
    // ww
    if(you == comp){
        return 0;
    }

    // Non-draw conditions
    // Cases covered:
    // sg
    // gs
    // sw 
    // ws
    // gw
    // wg
    

    if(you=='s' && comp=='g'){
        return -1;
    }
    else if(you=='g' && comp=='s'){
        return 1;
    }

    if(you=='s' && comp=='w'){
        return 1;
    }
    else if(you=='w' && comp=='s'){
        return -1;
    }

    if(you=='g' && comp=='w'){
        return -1;
    }
    else if(you=='w' && comp=='g'){
        return 1;
    }

}
int main(){
    char you, comp, q;
    char name[100];
    int i,x=3,cun=0,blun=0;
    printf("===============================================================================\n");
    printf("                  Welcome to the game of life and death\n");
    printf("===============================================================================\n");
    printf("           The DEVIL challenges you to a game of snake, water and gun\n");
    printf("===============================================================================\n");    
    title(name);
    
    for(i=0;i<x;i++)
    {
        printf("\nEnter 's' for snake, 'w' for water and 'g' for gun\n");
        scanf(" %c", &you); //taking the input from the user
        srand(time(0));
        int number = rand()%100 + 1; //generating a random move for the cumputer
    
        if(number<33){
            comp = 's';
        }
        else if(number>33 && number<66){
            comp='w';
        }
        else{
            comp='g';
        }
        int result = snakeWaterGun(you, comp);
        if(result ==0){
            printf("Game draw!\n");
        }
        else if(result==1){
            cun++;
            printf("You win this round!\n\n");
        }
        else{
            blun++;
            printf("The DEVIL wins this round!\n\n");
        }
        printf("You chose %c and DEVIL chose %c, and the score is %d-%d \n", you, comp,cun,blun);
    }
    if(cun>blun)
    {
        printf("\nYou won this 3 match series and conquered the DEVIL.\n");
        FILE *ptr;
        ptr = fopen("game.txt","a");
        time_t t; 
        time(&t);
        fprintf(ptr,"This match was played on %s\n",ctime(&t));
        fprintf(ptr,"%s VS Devil\n",name);
        fprintf(ptr,"Winner - %s\n\n",name);
        fprintf(ptr,"----------------------------------------------------------------------------------\n\n");
        fclose(ptr);
        FILE *ptr1;
        ptr1 = fopen("winner.txt","a");
        fprintf(ptr1,"%s\n",name);
        fclose(ptr1);


    }
    else if(blun>cun)
    {
        printf("\nYou loose this 3 match series and the DEVIL is now your master.\n");
        FILE *ptr;
        ptr = fopen("game.txt","a");
        time_t t; 
        time(&t);
        fprintf(ptr,"This match was played on %s\n",ctime(&t));
        fprintf(ptr,"%s VS Devil\n",name);
        fprintf(ptr,"Winner - Devil\n\n");
        fprintf(ptr,"----------------------------------------------------------------------------------\n\n");
        fclose(ptr);
        FILE *ptr2;
        ptr2 = fopen("loser.txt","a");
        fprintf(ptr2,"%s\n",name);
        fclose(ptr2);
    }
    else if(blun=cun)
    {
        printf("\nthis 3 match series resulted in a draw\n");
        FILE *ptr;
        ptr = fopen("game.txt","a");
        time_t t; 
        time(&t);
        fprintf(ptr,"This match was played on %s\n",ctime(&t));
        fprintf(ptr,"%s VS Devil\n",name);
        fprintf(ptr,"This game resulted in a draw\n\n");
        fprintf(ptr,"----------------------------------------------------------------------------------\n\n");
        fclose(ptr);
        FILE *ptr3;
        ptr3 = fopen("draw.txt","a");
        fprintf(ptr3,"%s\n",name);
        fclose(ptr3);
    }
    printf("===============================================================================\n");
    printf("MENU\n");
    printf("1. People who conquered the DEVIL\n");
    printf("2. People who lost to the devil\n");
    printf("3. People who drew with the DEVIL\n");
    printf("4. Previous game history\n");
    printf("5. Nothing\n");
    printf("===============================================================================\n\n");
    printf("Select what you want to do: ");
    scanf(" %c",&q);
    if(q=='1')
    {
        FILE *ptr1;
        char h;
        ptr1=fopen("winner.txt","r");
        while((h=fgetc(ptr1))!=EOF) {
            printf("%c",h);
        }
        fclose(ptr1);
        printf("\nThanks for tuning in\n");     
    }
    else if(q=='4')
    {
        FILE *ptr;
        char p;
        ptr=fopen("game.txt","r");
        while((p=fgetc(ptr))!=EOF) {
            printf("%c",p);
        }
        fclose(ptr);
        printf("\nThanks for tuning in\n");
    }
    else if(q=='2')
    {
        FILE *ptr2;
        char r;
        ptr2=fopen("loser.txt","r");
        while((r=fgetc(ptr2))!=EOF) {
            printf("%c",r);
        }
        fclose(ptr2);
        printf("\nThanks for tuning in\n");
    }
    else if(q=='3')
    {
        FILE *ptr3;
        char s;
        ptr3=fopen("draw.txt","r");
        while((s=fgetc(ptr3))!=EOF) {
            printf("%c",s);
        }
        fclose(ptr3);
        printf("\nThanks for tuning in\n");
    }
    else if(q=='5')
    {
        printf("\nThanks for tuning in\n");
    }
    return 0;
}