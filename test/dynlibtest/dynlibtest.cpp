#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <BaseComInternal/dynlib.h>

namespace DynlibTests
{
    TEST(dynlibtest, loadtestlib)
    {
        dynlib_t dynlib_handle = NULL;

        ASSERT_EQ(0, dynlib_create(TEST_LIBRARY_NAME, &dynlib_handle));

        void* address = NULL;
        ASSERT_EQ(0, dynlib_find_symbol(dynlib_handle, "say_hello", &address));
        ASSERT_NE(nullptr, address);

        dynlib_destroy(dynlib_handle);
    }
}
