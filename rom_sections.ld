MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    registered_services_area : SUBALIGN(4)
    {
        _registered_services_area_start = .;
        KEEP(*(SORT_BY_NAME(.registered_services.static.*)));
        _registered_services_area_end = .;
    } >RAM AT> FLASH
    . = ALIGN(4);

    /* subsections */
    .service_1 :
{
  __.service_1_start = .;
  KEEP(*(.service_1*))
  __.service_1_end = .;
} > FLASH
.service_2 :
{
  __.service_2_start = .;
  KEEP(*(.service_2*))
  __.service_2_end = .;
} > FLASH

}
