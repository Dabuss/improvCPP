#pragma once

#include <memory>
#include <random>
#include <string>
#include <vector>

#include "improvenginelib/IContent.h"
#include "improvenginelib/IImprovEngineGenerator.h"
#include "improvenginelib/RandomVectorSampler.h"

class AnimalGenerator : public IImprovEngineGenerator {
public:
    ~AnimalGenerator() {};

    AnimalGenerator(std::vector<std::string> const &animals);

    std::shared_ptr<IContent> generateImprovEngineContent() override;

    IImprovEngineGenerator::EngineType getEngineType() override;

private:
    std::vector<std::string> m_animals;
    RandomVectorSampler<std::string> m_randomAnimalSampler;
};