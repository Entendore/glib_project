cmake_minimum_required(VERSION 3.20)
project(glib_project CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Note: Requires a cutting-edge compiler (GCC 14+, Clang 18+, MSVC 19.40+)
# for C++23/26 features like std::expected, std::stacktrace, and pattern matching.

add_executable(glib_app UserApp.cpp
    glib/Factory.cpp
    glib/Vulkan/DeviceVK.cpp
)

# In a real environment, you would link Vulkan and VMA here:
# find_package(Vulkan REQUIRED)
# target_link_libraries(glib_app PRIVATE Vulkan::Vulkan)
