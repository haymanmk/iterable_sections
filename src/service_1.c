#include <stdio.h>
#include "register_service.h"

void hello_world_service(void)
{
    // Your service implementation here
    // For example, printing "Hello, World!" to the console
    printf("Hello world from Service!\n");
}

void bye_world_service(void)
{
    // Your service implementation here
    // For example, printing "Bye, World!" to the console
    printf("Bye world from Service!\n");
}

REGISTER_SERVICE(hello_world, hello_world_service);
REGISTER_SERVICE(bye_world, bye_world_service);