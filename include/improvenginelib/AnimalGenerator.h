#pragma once

#include <memory>

#include "improvenginelib/IImprovEngineGenerator.h"
#include "improvenginelib/IContent.h"

class AnimalGenerator : public IImprovEngineGenerator
{
public:
    ~AnimalGenerator(){};

    std::shared_ptr<IContent> generateImprovEngineContent() override;
};