#pragma once

#include <filesystem>
#include <vector>

#include <json/json.h>

class TextualResourcesFileParser {
public:
    TextualResourcesFileParser(std::filesystem::path const& pathToProjectRoot);

    std::vector<std::string> getItem(std::string const& itemName);

private:
    Json::Value m_root;
};