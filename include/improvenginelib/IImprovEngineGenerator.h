#pragma once

#include <map>
#include <memory>

#include "IContent.h"

class IImprovEngineGenerator
{
public:
    virtual ~IImprovEngineGenerator() = default;
    virtual std::shared_ptr<IContent> generateImprovEngineContent() const = 0;
    virtual std::string getResourcesIdentifier() const = 0;
};