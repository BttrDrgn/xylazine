#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void load(const char* bin_name);
void replace_func(uint32_t address, uint32_t function);

#ifdef __cplusplus
}
#endif