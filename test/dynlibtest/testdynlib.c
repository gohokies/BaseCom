// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "testdll_export.h"

#include <stdio.h>

TESTDLL_EXPORT void say_hello(void);

TESTDLL_EXPORT void say_hello(void)
{
    printf("Hello!\n");
}
