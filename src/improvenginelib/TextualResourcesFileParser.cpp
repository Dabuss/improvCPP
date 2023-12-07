#include "improvenginelib/TextualResourcesFileParser.h"

#include <fstream>
#include <map>

namespace
{

Json::Value retrieveResourceFileRoot(std::filesystem::path const& pathToExecutableDirectory)
{
    std::filesystem::path pathToResourcesFile
        = pathToExecutableDirectory / ".." / "resources" / "resources.json";
    std::string ermsg = "File " + pathToResourcesFile.string() + " doesn't exist.";
    if (!std::filesystem::exists(pathToResourcesFile))
    {
        throw std::invalid_argument(ermsg);
    }

    std::ifstream file(pathToResourcesFile);
    if (!file.is_open())
    {
        throw std::invalid_argument(ermsg);
    }

    Json::Value root;
    file >> root;
    return root;
}

} // namespace .

TextualResourcesFileParser::TextualResourcesFileParser(
    std::filesystem::path const& pathToProjectRoot)
{
    Json::Value root = retrieveResourceFileRoot(pathToProjectRoot);
    auto memberNames = root.getMemberNames();

    for (auto const& memberName : memberNames)
    {
        auto const& memberValue = root[memberName];
        std::vector<std::string> items;
        items.reserve(memberValue.size());
        std::transform(memberValue.begin(), memberValue.end(), std::back_inserter(items),
            [](auto const& item) { return item.asString(); });

        m_textualResources[memberName.c_str()] = items;
    }
}

std::map<std::string, std::vector<std::string>>
TextualResourcesFileParser::getTextualResources() const
{
    return m_textualResources;
}

std::vector<std::string> TextualResourcesFileParser::getItem(std::string const& itemName) const
{
    if (m_textualResources.count(itemName) == 0)
        throw std::invalid_argument(
            "The item name doesn't relate to a valid name within the resource file.");

    return m_textualResources.at(itemName);
}