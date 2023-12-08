#pragma once

#include <memory>
#include <typeindex>

#include <QLabel>
#include <QPushButton>

#include "improvenginelib/Displayer.h"
#include "improvenginelib/IImprovEngineGenerator.h"
#include "improvenginelib/TextualResourcesFileParser.h"

/**
 * @brief The ImpulsionGenerator class generates impulsion using Improv Engine generators.
 */
class ImpulsionGenerator {
public:
    /**
     * @brief Constructor for ImpulsionGenerator.
     * @param improvEngineGenerators Vector of shared pointers to IImprovEngineGenerator instances.
     * @param displayer Shared pointer to the Displayer instance.
     */
    ImpulsionGenerator(std::vector<std::shared_ptr<IImprovEngineGenerator>> improvEngineGenerators,
                       std::shared_ptr<Displayer> displayer);

    /**
     * @brief Generates a random impulsion using selected Improv Engine types.
     * @param improvEngineTypes Vector of type_index representing selected Improv Engine types.
     */
    void generateRandomImpulsion(std::vector<std::type_index> improvEngineTypes) const;

    /**
     * @brief Gets a map of Improv Engine types to their corresponding names.
     * @return Map of type_index to string representing Improv Engine types and names.
     */
    std::map<std::type_index, std::string> getEngineTypesToEngineNames() const;

private:
    std::vector<std::shared_ptr<IImprovEngineGenerator>> m_improvEngineGenerators; ///< Vector of Improv Engine generators.
    std::shared_ptr<Displayer> m_displayer; ///< Shared pointer to the Displayer instance.
};
