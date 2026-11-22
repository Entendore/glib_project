#pragma once
#include "../IDevice.h"
#include "../Common.h"
#include <vulkan/vulkan.h>

namespace glib::vk {

class DeviceVK : public IDevice {
    VkDevice device = VK_NULL_HANDLE;
public:
    DeviceVK(const DeviceDesc& desc);
    ~DeviceVK() override;

    void updateBuffer(Buffer buf, uint64_t offset, std::span<const std::byte> data) override;
    void retire(Buffer handle) override;
    std::optional<RayTracingProperties> queryFeature(Feature f) const override;
};

} // namespace glib::vk
