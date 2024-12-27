if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(DYNLIB_SRCS dynlib_windows.cpp)
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(DYNLIB_SRCS dynlib_unix.cpp)
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(DYNLIB_SRCS dynlib_unix.cpp)
else()
    message(FATAL_ERROR "Unknown system: ${CMAKE_SYSTEM_NAME}")
endif()

add_library(BaseComDynlib STATIC ${DYNLIB_SRCS})

target_include_directories(BaseComDynlib PUBLIC ${BC_INCLUDE_DIR})

if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(BaseComDynlib PUBLIC dl)
endif()
