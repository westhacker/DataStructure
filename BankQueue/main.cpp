#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "bank.h"

void main()
{
	bank banks;
	
	printf("平均等待时间：%d",banks.averagetime());

	getch();

	return;

}