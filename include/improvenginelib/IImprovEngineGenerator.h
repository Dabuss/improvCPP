#pragma once

#include <memory>
#include "IContent.h"

class IImprovEngineGenerator
{
public:
    virtual ~IImprovEngineGenerator() = default;
    virtual std::shared_ptr<IContent> generateImprovEngineContent() = 0;
};