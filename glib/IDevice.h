#pragma once
#include "Common.h"
#include <rcu>
#include <optional>
#include <span>

namespace glib {

enum class Feature { RayTracing, MeshShaders, VariableRateShading };
struct RayTracingProperties { uint32_t maxRecursionDepth; uint64_t shaderGroupHandleSize; };

class IDevice {
public:
    virtual ~IDevice() = default;

    virtual void updateBuffer(
        Buffer buf, 
        uint64_t offset, 
        std::span<const std::byte> data
    ) [[pre: buf.id != 0]] = 0;

    virtual std::optional<RayTracingProperties> queryFeature(Feature f) const = 0;

    virtual void retire(Buffer handle) = 0;
    virtual void retire(Texture handle) = 0;
};

} // namespace glib
