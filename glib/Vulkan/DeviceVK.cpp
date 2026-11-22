#include "DeviceVK.h"
#include <debugging>
#include <memory>

namespace glib::vk {

DeviceVK::DeviceVK(const DeviceDesc& desc) {
    // Vulkan initialization logic goes here
}

DeviceVK::~DeviceVK() {
    // vkDestroyDevice(device, nullptr);
}

void DeviceVK::updateBuffer(Buffer buf, uint64_t offset, std::span<const std::byte> data) {
    // Map and copy data using VMA
}

void DeviceVK::retire(Buffer handle) {
    // std::rcu deferred destruction logic
}

std::optional<RayTracingProperties> DeviceVK::queryFeature(Feature f) const {
    if (f == Feature::RayTracing) {
        return RayTracingProperties{ .maxRecursionDepth = 32, .shaderGroupHandleSize = 32 };
    }
    return std::nullopt;
}

} // namespace glib::vk
