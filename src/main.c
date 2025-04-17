#include <stdio.h>
#include "register_service.h"

// get the registered services from flash
extern struct service_t _registered_services_area_start[];
extern struct service_t _registered_services_area_end[];

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
    return 0;
}