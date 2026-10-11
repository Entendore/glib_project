#pragma once
#include "Common.h"
#include <inplace_vector>
#include <functional>
#include <string_view>

namespace glib {

struct AttachmentInfo { Format format; bool clearEnable; float clearColor[4]; };

class RenderGraph {
public:
    struct RenderingInfo {
        std::inplace_vector<AttachmentInfo, 8> colors;
        const AttachmentInfo* depth = nullptr;
    };

    virtual void addPass(
        std::string_view name,
        RenderingInfo info,
        std::move_only_function<void(ICommandEncoder&)> execute
    ) = 0;

    virtual void execute(Queue queue) = 0;
};

} // namespace glib
