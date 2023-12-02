#include "improvenginelib/AnimalGenerator.h"

#include <json/json.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "improvenginelib/TextContent.h"

namespace {

std::vector<std::string>
getVectorOfAnimalsFromFilePath(std::string const& pathToAnimalsFile)
{
    std::string ermsg = "File " + pathToAnimalsFile + " doesn't exist.";
    if (!std::filesystem::exists(pathToAnimalsFile)) {
        throw std::invalid_argument(ermsg);
    }

    std::ifstream file(pathToAnimalsFile);
    if (!file.is_open()) {
        throw std::invalid_argument(ermsg);
    }

    Json::Value root;
    file >> root;
    Json::Value animalsArray = root["animals"];

    std::vector<std::string> animals;
    animals.reserve(animalsArray.size());
    std::transform(animalsArray.begin(), animalsArray.end(),
        std::back_inserter(animals),
        [](auto const& animal) { return animal.asString(); });

    return animals;
}

} // namespace

AnimalGenerator::AnimalGenerator()
    : m_animals { getVectorOfAnimalsFromFilePath(m_pathToAnimalsFile) }
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