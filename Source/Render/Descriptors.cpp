#include "Descriptors.h"

Descriptors::Descriptors()
{

}

Descriptors::Descriptors(RenderDevice* renderDevice, std::unordered_map<std::string, Descriptor> descriptorSets, Pipeline* shader)
{

}

Descriptors::~Descriptors()
{

}

DescriptorType::Enum Descriptors::GetDescriptorType(std::string descriptor)
{
    return descriptors[descriptor].descriptorType;
}

void Descriptors::UpdateDescriptor(std::string descriptor, void* data)
{

}

void Descriptors::Bind()
{

}

void Descriptors::UnBind()
{

}