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

// place data in the service sections
const char service_1_data[] __attribute__((section("service_1"))) = "Service 1 data";
const char service_2_data[] __attribute__((section("service_2"))) = "Service 2 data";