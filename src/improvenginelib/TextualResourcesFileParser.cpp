#include "improvenginelib/TextualResourcesFileParser.h"

#include <fstream>
#include <map>

namespace
{
    /**
     * @brief Retrieves the root of the resource file.
     * @param pathToExecutableDirectory Path to the directory containing the executable.
     * @return Json::Value representing the root of the resource file.
     * @throws std::invalid_argument if the resource file doesn't exist or cannot be opened.
     */
    Json::Value retrieveResourceFileRoot(std::filesystem::path const& pathToExecutableDirectory)
    {
        // Construct the path to the resources file
        std::filesystem::path pathToResourcesFile
            = pathToExecutableDirectory / ".." / "resources" / "resources.json";
        std::string ermsg = "File " + pathToResourcesFile.string() + " doesn't exist.";

        // Check if the file exists
        if (!std::filesystem::exists(pathToResourcesFile))
        {
            throw std::invalid_argument(ermsg);
        }

        // Open the file
        std::ifstream file(pathToResourcesFile);
        if (!file.is_open())
        {
            throw std::invalid_argument(ermsg);
        }

        // Parse the JSON content of the file
        Json::Value root;
        file >> root;
        return root;
    }
} // namespace .

/**
 * @brief Constructor for TextualResourcesFileParser.
 * @param pathToProjectRoot Path to the root directory of the project.
 */
TextualResourcesFileParser::TextualResourcesFileParser(
    std::filesystem::path const& pathToProjectRoot)
{
    // Retrieve the root of the resource file
    Json::Value root = retrieveResourceFileRoot(pathToProjectRoot);

    // Get the member names from the root
    auto memberNames = root.getMemberNames();

    // Iterate over each member in the root
    for (auto const& memberName : memberNames)
    {
        // Get the value associated with the member name
        auto const& memberValue = root[memberName];

        // Create a vector to store items from the member value
        std::vector<std::string> items;
        items.reserve(memberValue.size());

        // Transform JSON array to a vector of strings
        std::transform(memberValue.begin(), memberValue.end(), std::back_inserter(items),
            [](auto const& item) { return item.asString(); });

        // Store the vector of items in the map
        m_textualResources[memberName.c_str()] = items;
    }
}

/**
 * @brief Getter for textual resources.
 * @return Map of item names to vectors of associated strings.
 */
std::map<std::string, std::vector<std::string>>
TextualResourcesFileParser::getTextualResources() const
{
    return m_textualResources;
}

/**
 * @brief Getter for a specific item from the resource file.
 * @param itemName Name of the item to retrieve.
 * @return Vector of strings associated with the specified item name.
 * @throws std::invalid_argument if the item name is not present in the resource file.
 */
std::vector<std::string> TextualResourcesFileParser::getItem(std::string const& itemName) const
{
    // Check if the item name is present in the resource file
    if (m_textualResources.count(itemName) == 0)
        throw std::invalid_argument(
            "The item name doesn't relate to a valid name within the resource file.");

    // Return the vector of strings associated with the specified item name
    return m_textualResources.at(itemName);
}
