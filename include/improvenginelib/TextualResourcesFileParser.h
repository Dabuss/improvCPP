#pragma once

#include <filesystem>
#include <vector>

#include <json/json.h>

class TextualResourcesFileParser
{
public:
    TextualResourcesFileParser(std::filesystem::path const& pathToProjectRoot);

    std::vector<std::string> getItem(std::string const& itemName) const;

    std::map<std::string, std::vector<std::string>> getTextualResources() const;

private:
    std::map<std::string, std::vector<std::string>> m_textualResources;
};