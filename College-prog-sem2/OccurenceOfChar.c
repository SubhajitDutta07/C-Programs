#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
    char ch;
    char str[100];
    int count=0;
    printf("Enter the string: ");
    gets(str);
    printf("enter the character: ");
    scanf("%c",&ch);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i]==ch)
        {
            count++;   
        }
        
    }
    printf(" The occurence of %c is %d  ", ch,count);
    return;
}