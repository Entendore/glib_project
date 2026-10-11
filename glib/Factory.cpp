#include "Factory.h"
// Backend implementations would be included here in a real build
// #include "Vulkan/DeviceVK.h"
// #include "OpenGL/DeviceGL.h"
// #include "OpenGLES/DeviceGLES.h"

namespace glib {

std::expected<std::unique_ptr<IDevice>, Error> CreateDevice(const DeviceDesc& desc) {
    // In a real project, this would instantiate the selected backend.
    // For this conceptual stub, we return an error.
    return std::unexpected(Error{.code = Error::Code::BackendFailure, .message = "No backends compiled."});
}

} // namespace glib
