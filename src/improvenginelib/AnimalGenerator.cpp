#include "improvenginelib/AnimalGenerator.h"

#include <json/json.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "improvenginelib/TextContent.h"


AnimalGenerator::AnimalGenerator(std::vector<std::string> const& animals)
    : m_animals { animals }
    , m_rdev {}
    , m_rgen { m_rdev() }
    , m_iDist { 0, static_cast<int>(m_animals.size() - 1) }
{
    if (m_animals.empty())
        throw std::invalid_argument("No animal available.");
}

std::shared_ptr<IContent>
AnimalGenerator::generateImprovEngineContent()
{
    return std::make_shared<TextContent>(m_animals[m_iDist(m_rgen)]);
}

IImprovEngineGenerator::EngineType AnimalGenerator::getEngineType()
{
    return IImprovEngineGenerator::EngineType::animals;
}