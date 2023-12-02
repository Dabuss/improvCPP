#pragma once

#include <memory>
#include <random>
#include <string>
#include <vector>

#include "improvenginelib/IContent.h"
#include "improvenginelib/IImprovEngineGenerator.h"

class AnimalGenerator : public IImprovEngineGenerator {
public:
    ~AnimalGenerator() {};

    AnimalGenerator();

    std::shared_ptr<IContent> generateImprovEngineContent() override;

private:
    std::string m_pathToAnimalsFile = "resources/animals.json";
    std::vector<std::string> m_animals;
    std::random_device m_rdev;
    std::mt19937 m_rgen;
    std::uniform_int_distribution<int> m_iDist;
};