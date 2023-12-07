#pragma once

#include <memory>
#include <random>
#include <string>
#include <vector>

#include "improvenginelib/IContent.h"
#include "improvenginelib/IImprovEngineGenerator.h"
#include "improvenginelib/RandomVectorSampler.h"
#include "improvenginelib/ITextualResourcesFileParser.h"

class AnimalGenerator : public IImprovEngineGenerator {
public:
    ~AnimalGenerator() {};

    AnimalGenerator(std::shared_ptr<ITextualResourcesFileParser> textualResourcesFileParser, std::shared_ptr<RandomVectorSampler<std::string>> randomAnimalSampler);

    std::shared_ptr<IContent> generateImprovEngineContent() const override;

    IImprovEngineGenerator::EngineType getEngineType() const override;

    std::string getResourcesIdentifier() const override;

private:
    std::string m_resourceIdentifier = "Animals";
    std::vector<std::string> m_animals;
    std::shared_ptr<RandomVectorSampler<std::string>> m_randomAnimalSampler;
};