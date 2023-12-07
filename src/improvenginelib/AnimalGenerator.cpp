#include "improvenginelib/AnimalGenerator.h"

#include <algorithm>
#include <filesystem>
#include <fstream>

#include <json/json.h>

#include "improvenginelib/TextContent.h"

AnimalGenerator::AnimalGenerator(std::vector<std::string> const& animals)
    : m_animals { animals }
    , m_randomAnimalSampler{}
{
    if (m_animals.empty())
        throw std::invalid_argument("No animal available.");
}

std::shared_ptr<IContent>
AnimalGenerator::generateImprovEngineContent()
{
    return std::make_shared<TextContent>(m_randomAnimalSampler.sample(m_animals));
}

IImprovEngineGenerator::EngineType AnimalGenerator::getEngineType()
{
    return IImprovEngineGenerator::EngineType::animals;
}