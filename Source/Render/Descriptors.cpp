#include "Descriptors.h"

Descriptors::Descriptors()
{

}

Descriptors::Descriptors(std::unordered_map<std::string, Descriptor> descriptorSets)
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