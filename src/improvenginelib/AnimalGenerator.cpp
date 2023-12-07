#include "improvenginelib/AnimalGenerator.h"

#include <algorithm>
#include <filesystem>
#include <fstream>

#include <json/json.h>

#include "improvenginelib/TextContent.h"

AnimalGenerator::AnimalGenerator(std::shared_ptr<ITextualResourcesFileParser> textualResourcesFileParser, std::shared_ptr<RandomVectorSampler<std::string>> randVectorSampler)
    : m_animals {textualResourcesFileParser->getItem(getResourcesIdentifier())}
    , m_randomAnimalSampler{randVectorSampler}
{
    if (m_animals.empty())
        throw std::invalid_argument("No animal available.");
}

std::shared_ptr<IContent>
AnimalGenerator::generateImprovEngineContent() const
{
    return std::make_shared<TextContent>(m_randomAnimalSampler->sample(m_animals));
}

IImprovEngineGenerator::EngineType AnimalGenerator::getEngineType() const
{
    return IImprovEngineGenerator::EngineType::animals;
}

std::string AnimalGenerator::getResourcesIdentifier() const
{
    return m_resourceIdentifier;
}