#include <stdio.h>
#include <stdlib.h>
#include"tool.h"
int main(void)
{
     while(1){
    p=0;syn=0;
    printf("\nplease input a string (end with '#'): \n");
    do
    {
        scanf("%c",&ch);
        if(ch=='\n') continue;
        prog[p++]=ch;
    }while(ch!='#');
    p=0;
    ck_aly=0;
    success=1;
    scaner();

    statement();
    p=0;
    printf("·ûºÅ\t\t  Öµ\n");
    do{
            ck_aly=1;
            scaner();
            switch(syn)
            {
                case 11:
                    printf("( %-10d%5d )\n",sum,syn);
                break;

                case -1:
                    printf("you have input a wrong string\n");
                    return 0;
                break;

                default:
                printf("( %-10s%5d )\n",token,syn);
                break;
            }

        }while(syn!=0);

        }

    /*p=0;
    do{
            ck_aly=1;
            scaner();
            switch(syn)
            {
                case 11:
                    printf("( %-10d%5d )\n",sum,syn);
                break;

                case -1:
                    printf("you have input a wrong string\n");
                    //getch();
                    return 0;
                break;

                default:
                printf("( %-10s%5d )\n",token,syn);
                break;
            }
        }while(syn!=0);*/
    return 0;
}
