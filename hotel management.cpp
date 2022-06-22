#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insert();
void search();
void update();//declaration of function


struct member //structure
{
    int membershipid;
    char name[20];
char membershiptype[10];
    int membershipfees;
};
struct member m; //s is a variable of structure member
int main()
{
     int choice;
     system("color A");
     while(choice!=4)
     {
      printf("\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
      printf("\t'WELCOME TO GRAND HAYATT CLUB DATABASE'\n");
      printf("\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n");

             printf("\t\t****Available Options****\n\n");
             printf("\t\t1: INSERT MEMBER ID\n");
             printf("\t\t2: SEARCH MEMBER RECORD\n");
             printf("\t\t3: UPDATE MEMBER RECORD\n");
             printf("\t\t4: Exit\n\n");
             printf("\t\tEnter Your Choice : ");
             scanf("%d",&choice );
             switch(choice)
             {
                case 1:system("cls");
                       insert(); //calling the function  
                        break;
                case 2:system("cls");
                       search();
                       break;
                case 3:system("cls");
                       update();
                       break;
                case 4:exit(1);
                       
                default:printf("\n\t\t!!! You Entered The Wrong Choice !!!\n\n");
                   //it is a menu driven program
             }
             getchar(); //again go to the loop
     }
     return 0;
}
void insert()//declaration
{
    FILE *fp; 
    
     //(FILE) is a structure 
     //(*fp)is a file pointer it is used for buffer 
     //storage perform in membershiptypeondary memory,file creation happens in 2nd memomry but all func happens in main memory
     
    fp=fopen("mem.txt","a+"); 
    
    //to open file //mem is the file .txt is the extension
    //a,open file in append mode,if file doesn't exist it is created,if file exist then writing starts after that
    //a+,open for reading and writing

    printf("\n\n\t\t^^^^ENTER NEW MEMBER DATA^^^^");
    printf("\n\n\t\tENTER MEMBER ID : ");
    scanf("%d",&m.membershipid);
    fflush(stdin);

    //fflush is used to flush the previous memory then start writing coz there are buffer

    printf("\n\t\tENTER MEMBER NAME : ");
    gets(m.name);
    printf("\n\t\tENTER membershiptype : ");
    gets(m.membershiptype);
    printf("\n\t\tENTER membershipfees : ");
    scanf("%d",&m.membershipfees);
    fwrite(&m,sizeof(m),1,fp);

    //use to store data taken from user
    //fputc used to write only char,fputs use to write only string,fprintf use to write only text
    //fwrite use to write in binary mode

    {
        printf("\n\n\tMEMBER DATABASE RECORDED SUCCESSFULLY !!!\n");
    }
    fclose(fp);

    //close the file fp
    //as soon as the file closes by the help of buffer(fp) data write in the 2nd memory from the 1st memory

    printf("\n\t\tRecord Updated !!!\n\n");
}
void search()
{
    int ro,flag=0;

    //flag is taken coz as soon flag value is 0 we go under the loop and if it is 1 we go outside the loop
    //ro is taken for membershipid no.

    FILE *fp;
    fp=fopen("mem.txt","r");

    //(r),is use to open file in read mode
    if(fp==NULL)
    {
        printf("\n\t\tError : File Does Not Exist !!! ");
        return;
    }
    printf("\n\n\tENTER membershipid WHICH YOU WANT TO SEARCH : ");
    scanf("%d",&ro);
    while(fread(&m,sizeof(m),1,fp)>0&&flag==0)
    {
        if(m.membershipid==ro)
   
        //ro is the membershipid no. that user has entered

        {
            flag=1;
             printf("\n\n\tSearch Sucessfull And Member Records Is as follows");
             printf("\nmembershipid\t\tName of Member\t\tmembershiptype\t\tmembershipfees\n");
             printf("%d\t\t\t%s  \t\t  %s \t\t%d\n\n\n",m.membershipid,m.name,m.membershiptype,m.membershipfees);
        }
    }
        if(flag==0)
        {
            printf("\n\n\t\t!!! No Record Found !!!\n\n");
        }
fclose(fp);
}
void update()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("mem.txt","r+");

    //r+ is use to open file for reading and writing

    if(fp==NULL)
    {
        printf("\n\t\tError : File Does Not Exist");
        return;
    }
    printf("\n\n\tENTER membershipid OF THE MEMBER WHOSE RECORD YOU WANT TO UPDATE :");
    scanf("%d",&ro);
    printf("\n\n\t\t *** Previously Stored Record Of Given membershipid ***\n\n");
    while(fread(&m,sizeof(m),1,fp)>0 && flag==0)
    {
        if(m.membershipid==ro)
        {
            flag=1;
            printf("\nmembershipid \t\tName of Member\t\tmembershiptype\t\tmembershipfees\n");
             printf("%d\t\t\t%s  \t\t %s \t\t%d\n",m.membershipid,m.name,m.membershiptype,m.membershipfees);
            printf("\n\n\n\t\t*** Now Enter The New Record Of The Member ***\n\n");
            printf("\n\t\tUpdated membershipid .: ");
            scanf("%d",&m.membershipid);
            fflush(stdin);
            printf("\n\t\tUpdated Member Name: ");
            gets(m.name);
            printf("\n\t\tUpdated membershiptype: ");
            gets(m.membershiptype);
            printf("\n\t\tUpdated membershipfees: ");
            scanf("%d",&m.membershipfees);
            fseek(fp,-(long)sizeof(m),1);

            //fseek,it is a update function,minus is used to update file from beginning

            fwrite(&m,sizeof(m),1,fp);
            printf("\n\n\t\tRecord Updated\n\n\n");
        }
    }
    if(flag==0)
    {
        printf("\n\t\tError : Something Went Wrong !!!\n\n");
    }
fclose(fp);
}
