#pragma once
#include <cstdint>
#include <expected>
#include <optional>
#include <inplace_vector>
#include <utility>
#include <stacktrace>
#include <ranges>
#include <generator>

namespace glib {

struct Error {
    enum class Code { OutOfMemory, InvalidHandle, FormatUnsupported, ShaderCompilationFailed } code;
    std::string message;
    std::stacktrace stacktrace = std::stacktrace::current();
};
template<typename T>
using Expected = std::expected<T, Error>;

struct Buffer { uint64_t id = 0; };
struct Texture { uint64_t id = 0; };
struct Pipeline { uint64_t id = 0; };
struct BindlessID { uint32_t index = 0xFFFF'FFFF; };

enum class Format { R32_Float, RG32_Float, RGB32_Float, RGBA32_Float, RGBA8_UNorm, BGRA8_UNorm, D32_Float };

constexpr uint32_t toVK(Format f) {
    return inspect(f) {
        Format::R32_Float    => 100;
        Format::RG32_Float   => 103;
        Format::RGBA32_Float => 109;
        Format::RGBA8_UNorm  => 37;
        Format::D32_Float    => 126;
    };
}

enum class BufferUsage : uint32_t { None = 0, Vertex = 1, Index = 2, Uniform = 4 };
constexpr BufferUsage operator|(BufferUsage a, BufferUsage b) {
    return static_cast<BufferUsage>(std::to_underlying(a) | std::to_underlying(b));
}

} // namespace glib
