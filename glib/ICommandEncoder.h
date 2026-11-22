#pragma once
#include "Common.h"

namespace glib {

class ICommandEncoder {
public:
    virtual ~ICommandEncoder() = default;

    template <typename Self>
    auto&& bindPipeline(this Self&& self, Pipeline p) {
        self.bindPipelineImpl(p);
        return std::forward<Self>(self);
    }

    template <typename Self>
    auto&& bindVertexBuffer(this Self&& self, uint32_t binding, Buffer buf) {
        self.bindVertexBufferImpl(binding, buf);
        return std::forward<Self>(self);
    }

    template <typename Self>
    auto&& draw(this Self&& self, uint32_t vertexCount) {
        self.drawImpl(vertexCount);
        return std::forward<Self>(self);
    }

private:
    virtual void bindPipelineImpl(Pipeline) = 0;
    virtual void bindVertexBufferImpl(uint32_t, Buffer) = 0;
    virtual void drawImpl(uint32_t) = 0;
};

} // namespace glib
