#include "improvenginelib/TextualResourcesFileParser.h"

#include <fstream>

namespace {

Json::Value retrieveResourceFileRoot(std::filesystem::path const& pathToExecutableDirectory)
{
    std::filesystem::path pathToResourcesFile = pathToExecutableDirectory / ".." / "resources" / "resources.json";
    std::string ermsg = "File " + pathToResourcesFile.string() + " doesn't exist.";
    if (!std::filesystem::exists(pathToResourcesFile)) {
        throw std::invalid_argument(ermsg);
    }

    std::ifstream file(pathToResourcesFile);
    if (!file.is_open()) {
        throw std::invalid_argument(ermsg);
    }

    Json::Value root;
    file >> root;
    return root;
}

} // namespace .

TextualResourcesFileParser::TextualResourcesFileParser(std::filesystem::path const& pathToProjectRoot)
    : m_root { retrieveResourceFileRoot(pathToProjectRoot) }
{
}

std::vector<std::string> TextualResourcesFileParser::getItem(std::string const& itemName)
{
    Json::Value itemArray = m_root[itemName];

    std::vector<std::string> items;
    items.reserve(itemArray.size());
    std::transform(itemArray.begin(), itemArray.end(),
        std::back_inserter(items),
        [](auto const& item) { return item.asString(); });

    return items;
}