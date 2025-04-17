#include <stdio.h>
#include "register_service.h"

// get the registered services from flash
extern struct service_t _registered_services_area_start[];

int main(void)
{
    // printf("Hello, World!\n");
    _registered_services_area_start[0].service();
    return 0;
}