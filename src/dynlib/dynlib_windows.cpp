#include <BaseComInternal/dynlib.h>
#include <BaseComInternal/flowctrl.h>

#include <cstdlib>

typedef struct _dynlib_context
{
    HMODULE handle;
} dynlib_context;

HRESULT dynlib_create(const char *name, dynlib_t *dynlib_handle)
{
    HRESULT hr = S_OK;
    dynlib_context* pContext = nullptr;

    RET_IF(E_INVALIDARG, name == NULL);
    RET_IF(E_POINTER, dynlib_handle == NULL);

    *dynlib_handle = nullptr;
    pContext = reinterpret_cast<dynlib_context *>(malloc(sizeof(dynlib_context)));
    if (pContext != NULL) {
        pContext->handle = LoadLibraryExA(name, NULL,
            LOAD_LIBRARY_SEARCH_DEFAULT_DIRS | LOAD_LIBRARY_SEARCH_USER_DIRS);
        if (pContext->handle != NULL){
            *dynlib_handle = reinterpret_cast<dynlib_t>(pContext);
        }
        else{
            free(pContext);
            hr = E_FAIL;
        }
    }
    else{
        hr = E_FAIL;
    }

    return hr;
}

HRESULT dynlib_find_symbol(dynlib_t dynlib_handle, const char *symbol, void **address)
{
    HRESULT hr = S_OK;
    dynlib_context *pContext = nullptr;
    void *ptr = NULL;

    RET_IF(E_INVALIDARG, dynlib_handle == NULL);
    RET_IF(E_INVALIDARG, symbol == NULL);
    RET_IF(E_POINTER, address == NULL);

    pContext = reinterpret_cast<dynlib_context *>(dynlib_handle);
    ptr = (void *)GetProcAddress(pContext->handle, symbol);
    if (ptr != nullptr){
        *address = ptr;
    }
    else{
        hr = E_FAIL;
    }

    return hr;
}

void dynlib_destroy(dynlib_t dynlib_handle)
{
    dynlib_context* pContext = reinterpret_cast<dynlib_context *>(dynlib_handle);
    if (pContext != nullptr)
    {
        FreeLibrary(pContext->handle);
        free(pContext);
    }
}
