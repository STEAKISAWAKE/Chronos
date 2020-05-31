#ifndef __CHRONOS_RENDER_DESCRIPTORS_H__
#define __CHRONOS_RENDER_DESCRIPTORS_H__

#include <string>
#include <unordered_map>

class RenderDevice;
class Pipeline;

struct DescriptorType
{
    enum class Enum
    {
        Unknown, // Null Error
        Int,
        Float,
        Vec2,
        Vec3,
        Vec4,
        Mat3,
        Mat4
    };
};

struct Descriptor
{
    DescriptorType::Enum descriptorType;
    void* data;
};

class Descriptors
{

public:
    Descriptors();
    Descriptors(RenderDevice* renderDevice, std::unordered_map<std::string, Descriptor> descriptorSets, Pipeline* pipeline);
    ~Descriptors();

public:
    virtual void Bind();
    virtual void UnBind();

    virtual DescriptorType::Enum GetDescriptorType(std::string descriptor);
    virtual void UpdateDescriptor(std::string descriptor, void* newData);

public:
    std::unordered_map<std::string, Descriptor> descriptors;
    Pipeline* pipeline;

};

#endif // __CHRONOS_RENDER_DESCRIPTORS_H__