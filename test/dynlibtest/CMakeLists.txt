
# Create a dll
#
set(TEST_LIBRARY_NAME "testdll")
set(TEST_LIBRARY_VERSION 1)

add_library(${TEST_LIBRARY_NAME} SHARED testdynlib.c)

include(GenerateExportHeader)
generate_export_header(${TEST_LIBRARY_NAME})

target_include_directories(${TEST_LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# Create a test for the dll 
add_executable(dynlibtest dynlibtest.cpp)

target_include_directories(dynlibtest PUBLIC ${BC_INCLUDE_DIR})
target_link_libraries(dynlibtest PRIVATE BaseComDynlib GTest::gtest GTest::gtest_main)
target_compile_definitions(dynlibtest PRIVATE TEST_LIBRARY_NAME="$<TARGET_FILE_NAME:${TEST_LIBRARY_NAME}>")

if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    # Search the same directory as the exectuable for the shared object
    target_link_libraries(dynlibtest PRIVATE "-Wl,-rpath,'$$ORIGIN'")
endif()

add_test(dynlibtest dynlibtest)