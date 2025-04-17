#ifndef __REGISTER_SERVICE_H__
#define __REGISTER_SERVICE_H__

struct service_t {
    const char *name;
    void (*service)(void);
};

#define REGISTER_SERVICE(_name, _service) \
    const struct service_t _name __attribute__((section(".registered_services.static." #_name))) = { \
        .name = #_name, \
        .service = _service \
    }

#endif // __REGISTER_SERVICE_H__