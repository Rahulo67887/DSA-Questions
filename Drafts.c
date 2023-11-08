#include <stdio.h>

#include <stdlib.h>

int main() {
double num, digit, reverse=0; 
printf("enter number you want reverse: "); scanf("%1f", &num);
while (num>0) {
digit= num%10;
reverse=reverse*10+digit; 
num+num/10;
}

printf("%lf", reverse);
return 0;
}