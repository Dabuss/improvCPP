#pragma once

class ITextualResourcesFileParser
{
public:
    virtual ~ITextualResourcesFileParser() = default;

    virtual std::map<std::string, std::vector<std::string>> getTextualResources() const = 0;
    virtual std::vector<std::string> getItem(std::string const & itemName) const = 0;
};