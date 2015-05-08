#include <stdio.h>
#include "hako.h"


int main()
{
	printf("Hello, world!\n");


	/* trying the API */
	Hako::App myApp;

	myApp.Init();

	myApp.MainLoop();


	return 0;
}
