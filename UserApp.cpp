#include "glib/Factory.h"
#include "glib/Reflection.h"
#include <glm/glm.hpp>
#include <optional>
#include <ranges>
#include <print>

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 uv;
};

int main() {
    glib::DeviceDesc desc{};
    desc.backend = glib::Backend::Vulkan;
    
    auto deviceResult = glib::CreateDevice(desc);
    if (!deviceResult) {
        std::println(stderr, "Failed to create device: {}", deviceResult.error().message);
        return -1;
    }
    
    glib::IDevice* dev = deviceResult.value().get();
    constexpr auto vertexLayout = glib::reflectVertexLayout<Vertex>();

    std::println("Successfully generated glib project!");
    std::println("Vertex Layout reflected {} attributes.", vertexLayout.size());

    return 0;
}
