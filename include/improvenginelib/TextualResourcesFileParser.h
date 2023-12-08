#pragma once

#include <filesystem>
#include <vector>

#include <json/json.h>

#include "improvenginelib/ITextualResourcesFileParser.h"

/**
 * @brief The TextualResourcesFileParser class is responsible for parsing a textual resource file.
 */
class TextualResourcesFileParser : public ITextualResourcesFileParser
{
public:
    /**
     * @brief Constructor for TextualResourcesFileParser.
     * @param pathToProjectRoot Path to the root directory of the project.
     */
    TextualResourcesFileParser(std::filesystem::path const& pathToProjectRoot);

    /**
     * @brief Destructor for TextualResourcesFileParser.
     */
    ~TextualResourcesFileParser() = default;

    /**
     * @brief Getter for textual resources.
     * @return Map of item names to vectors of associated strings.
     */
    std::map<std::string, std::vector<std::string>> getTextualResources() const override;

    /**
     * @brief Getter for a specific item from the resource file.
     * @param itemName Name of the item to retrieve.
     * @return Vector of strings associated with the specified item name.
     * @throws std::invalid_argument if the item name is not present in the resource file.
     */
    std::vector<std::string> getItem(std::string const & itemName) const override;

private:
    std::map<std::string, std::vector<std::string>> m_textualResources; ///< Map of textual resources.
};
