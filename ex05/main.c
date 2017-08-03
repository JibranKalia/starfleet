#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();
	int		ret;


	/*-------------------
	launch your test here
	--------------------*/
	for (int i = 0; i < 500; i++)
	{
		ret = rand() % 100;
		tankPush(tank, ret);
	}
	visual(tank);
	for (int i = 0; i < 100; i++)
	{
		tankPop(tank);
	}
	printf("AFTER POP\n");
	visual(tank);
	return (0);
}



// Function used for the test
// Don't go further :)
