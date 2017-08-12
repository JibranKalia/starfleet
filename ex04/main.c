#include "header.h"

int main(void)
{
	t_queue *cars = queueInit();
	printf("Is Empty = %d\n", isEmpty(cars));
	printAll(cars);
	enqueue(cars, "Ferrari");
	enqueue(cars, "BMW");
	enqueue(cars, "Honda");
	dequeue(cars);
	enqueue(cars, "Tesla");
	printAll(cars);
	printf("Is Empty = %d\n", isEmpty(cars));
	printf("Peek = %s\n", peek(cars));

	/*-------------------
	launch your test here
	--------------------*/

	return (0);
}



// Function used for the test
// Don't go further :)

