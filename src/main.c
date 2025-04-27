#include <stdio.h>
#include "register_service.h"

// get the registered services from flash
extern struct service_t _registered_services_area_start[];
extern struct service_t _registered_services_area_end[];

// retrieve the registered services from flash
extern char __service_1_start[];
extern char __service_1_end[];
extern char __service_2_start[];
extern char __service_2_end[];


int main(void)
{
    // iterate over the registered services until the end
    // of the section
    for (struct service_t *service = _registered_services_area_start; 
         service < _registered_services_area_end;
         service++)
    {
        // call the service
        service->service();
    }

    // print the addresses of the registered services
    printf("Service 1 start: %p\n", __service_1_start);
    printf("Service 1 end: %p\n", __service_1_end);
    printf("Service 2 start: %p\n", __service_2_start);
    printf("Service 2 end: %p\n", __service_2_end);

    // print data in the service sections
    printf("Service 1 data: %s\n", __service_1_start);
    printf("Service 2 data: %s\n", __service_2_start);

    return 0;
}