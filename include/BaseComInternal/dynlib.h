#ifndef __BC_DYNLIB_H__
#define __BC_DYNLIB_H__

#include <BaseCom/BaseComDefs.h>

#ifdef __cplusplus
extern "C"
{
#endif

BC_DECLARE_HANDLE(dynlib_t);

HRESULT dynlib_create(const char *name, dynlib_t *dynlib_handle);
HRESULT dynlib_find_symbol(dynlib_t dynlib_handle, const char *symbol, void **address);
void dynlib_destroy(dynlib_t dynlib_handle);

#ifdef __cplusplus
}
#endif

#endif