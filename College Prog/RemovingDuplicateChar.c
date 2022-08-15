#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
    char str[100];
    printf("Enter the string");
    gets(str);
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = i+1; j < strlen(str)!='\0'; j++)
        {
            if(str[j]==str[i])
            {
                for (int k = j; str[k]!='\0'; k++)
                {
                    str[k]=str[k+1];
                }
                
            }
        }
        
    }
    printf("Final string is: %s ", str);
    return;
}