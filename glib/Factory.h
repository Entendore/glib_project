#pragma once
#include "Common.h"
#include "IDevice.h"
#include <expected>
#include <memory>

namespace glib {

enum class Backend { OpenGL, OpenGLES, Vulkan };

struct DeviceDesc {
    Backend backend;
    bool enableValidation = true;
    void* windowHandle = nullptr; 
    void* displayHandle = nullptr;
};

std::expected<std::unique_ptr<IDevice>, Error> CreateDevice(const DeviceDesc& desc);

} // namespace glib
