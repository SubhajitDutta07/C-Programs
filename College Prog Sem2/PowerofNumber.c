#include<stdio.h>
#include<math.h>
void main()
{

    int base,pow;
    printf("Enter the number : ");
    scanf("%d",&base);
    printf(" Enter the base: ");
    scanf("%d",&pow);
    int a=power(base,pow);
    printf(" The power is: %d \n", a);
}

int power(int base,int pow)
{   
    if(pow==0)
        return 1;
    return (base*power(base,pow-1));

}