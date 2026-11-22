#pragma once
#include "Common.h"
#include <meta>
#include <vector>

namespace glib {

struct VertexAttrib { uint32_t location, binding, offset; Format format; };

template <typename T>
consteval std::vector<VertexAttrib> reflectVertexLayout() {
    std::vector<VertexAttrib> attrs;
    constexpr auto type = ^^T;
    uint32_t offset = 0;
    template for (constexpr auto member : nonstatic_data_members_of(type)) {
        VertexAttrib attr{};
        attr.location = attrs.size();
        attr.binding = 0;
        attr.offset = offset;
        if constexpr (typeid_of(member) == ^^glm::vec3) {
            attr.format = Format::RGB32_Float;
            offset += sizeof(glm::vec3);
        } else if constexpr (typeid_of(member) == ^^glm::vec2) {
            attr.format = Format::RG32_Float;
            offset += sizeof(glm::vec2);
        }
        attrs.push_back(attr);
    }
    return attrs;
}

} // namespace glib
