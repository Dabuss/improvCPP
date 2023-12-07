#pragma once

#include <filesystem>
#include <vector>

#include <json/json.h>

#include "improvenginelib/ITextualResourcesFileParser.h"

class TextualResourcesFileParser : public ITextualResourcesFileParser
{
public:
    TextualResourcesFileParser(std::filesystem::path const& pathToProjectRoot);
    ~TextualResourcesFileParser() = default;

    std::map<std::string, std::vector<std::string>> getTextualResources() const override;
    std::vector<std::string> getItem(std::string const & itemName) const override;

private:
    std::map<std::string, std::vector<std::string>> m_textualResources;
};