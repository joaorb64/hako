#include <stdio.h>
#include "hako.h"


int main()
{
	printf("Hello, world!\n");


	/* trying the API */
	Hako::App myApp;

	myApp.init(nullptr);

	myApp.main_loop(nullptr);


	return 0;
}
