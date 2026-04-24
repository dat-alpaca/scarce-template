#include <scarce.h>
#include "map.h"

static engine* _e = 0;

void on_load(memory_pool* pool, engine* engine)
{
    _e = engine;

    // Prepare file descriptors:
    file_descriptor* fileDescriptors = (file_descriptor*)(&pool[SCA_FILE_DESCRIPTORS_ADDR]);
    for(u8 i = 0; i < SCA_FILE_DESCRIPTORS_SIZE / sizeof(file_descriptor); ++i)
        *(fileDescriptors + i) = invalid_file_descriptor;
}  

bool on_update(memory_pool* pool)
{

}  

void on_unload(memory_pool* pool)
{
}  

SECTION_ENTRY const exports _ = {
    .on_load   = on_load,
    .on_update = on_update,
    .on_unload = on_unload
};