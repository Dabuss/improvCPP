#pragma once

#include <memory>
#include <random>
#include <string>
#include <vector>

#include "improvenginelib/IContent.h"
#include "improvenginelib/IImprovEngineGenerator.h"
#include "improvenginelib/ITextualResourcesFileParser.h"
#include "improvenginelib/RandomVectorSampler.h"

class BodyPartGenerator : public IImprovEngineGenerator
{
public:
    ~BodyPartGenerator() {};

    BodyPartGenerator(std::shared_ptr<ITextualResourcesFileParser> textualResourcesFileParser,
        std::shared_ptr<RandomVectorSampler<std::string>> randomAnimalSampler);

    std::shared_ptr<IContent> generateImprovEngineContent() const override;

    std::string getResourcesIdentifier() const override;

private:
    std::string m_resourceIdentifier = "Parties du corps";
    std::vector<std::string> m_bodyParts;
    std::shared_ptr<RandomVectorSampler<std::string>> m_randomBodyPartSampler;
};