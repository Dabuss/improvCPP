#pragma once

#include <map>
#include <memory>

#include "IContent.h"

class IImprovEngineGenerator
{
public:
    enum class EngineType
    {
        animals,
        bodyPart
    };

    static std::string EngineNameFromType(EngineType const& engineType)
    {
        switch (engineType)
        {
        case EngineType::bodyPart:
            return "Parties du corps";
        default:
        case EngineType::animals:
            return "Animals";
        }
    }

    virtual ~IImprovEngineGenerator() = default;
    virtual std::shared_ptr<IContent> generateImprovEngineContent() = 0;
    virtual EngineType getEngineType() = 0;
};