#include "improvenginelib/ImpulsionGenerator.h"

#include <filesystem>

#include "improvenginelib/RandomVectorSampler.h"
#include "improvenginelib/TextualResourcesFileParser.h"

namespace
{
    /**
     * @brief Helper function to get the type_index from a shared pointer to a base class.
     * @tparam T Type of the base class.
     * @param ptr Shared pointer to the base class.
     * @return Type index of the base class.
     */
    template <typename T>
    std::type_index getTypeIndexFromSharedPointerOfBaseClass(std::shared_ptr<T> ptr)
    {
#pragma warning(push)
#pragma warning(disable : <warning-number>)

        return typeid(*ptr);

#pragma warning(pop)
    }

    /**
     * @brief Helper function to check if a shared pointer holds a specific type.
     * @tparam T Type of the base class.
     * @param ptr Shared pointer to the base class.
     * @param type Type index to check against.
     * @return True if the shared pointer holds the specified type, false otherwise.
     */
    template <typename T>
    bool isPointerHoldingThisType(std::shared_ptr<T> ptr, std::type_index type)
    {
        std::type_index ptrType = getTypeIndexFromSharedPointerOfBaseClass(ptr);
        return type == ptrType;
    }
}

/**
 * @brief Constructor for ImpulsionGenerator.
 * @param improvEngineGenerators Vector of shared pointers to IImprovEngineGenerator instances.
 * @param displayer Shared pointer to the Displayer instance.
 */
ImpulsionGenerator::ImpulsionGenerator(
    std::vector<std::shared_ptr<IImprovEngineGenerator>> improvEngineGenerators,
    std::shared_ptr<Displayer> displayer)
    : m_improvEngineGenerators{ improvEngineGenerators }
    , m_displayer{ displayer }
{}

/**
 * @brief Generates a random impulsion using selected Improv Engine types.
 * @param engineTypes Vector of type_index representing checkbox-selected Improv Engine types.
 */
void ImpulsionGenerator::generateRandomImpulsion(std::vector<std::type_index> engineTypes) const
{
    // Create a random sampler for selecting from the vector of Improv Engine generators
    RandomVectorSampler<std::shared_ptr<IImprovEngineGenerator>> randomSampler{};

    // Container to store the selected Improv Engine generators
    std::vector<std::shared_ptr<IImprovEngineGenerator>> selectedImprovEngines;
    selectedImprovEngines.reserve(m_improvEngineGenerators.size());

    // Iterate over the specified engine types
    for (std::type_index const& engineType : engineTypes)
    {
        // Find the Improv Engine generator that matches the specified type
        auto it = std::find_if(m_improvEngineGenerators.begin(), m_improvEngineGenerators.end(),
            [engineType](std::shared_ptr<IImprovEngineGenerator> const& improvEngineGenerator)
            {
                // Check if the generator's type matches the specified type
                return isPointerHoldingThisType(improvEngineGenerator, engineType);
            });

        // If a matching generator is found, add it to the selectedImprovEngines vector
        if (it != m_improvEngineGenerators.end())
            selectedImprovEngines.push_back(*it);
    }

    // Use the random sampler to select one Improv Engine generator randomly from the selected ones
    std::shared_ptr<IImprovEngineGenerator> improEngineGenerator
        = randomSampler.sample(selectedImprovEngines);

    // Generate content using the selected Improv Engine generator
    std::shared_ptr<IContent> content = improEngineGenerator->generateImprovEngineContent();

    // Display the generated content using the Displayer
    m_displayer->displayContent(content);
}


/**
 * @brief Gets a map of Improv Engine types to their corresponding names.
 * @return Map of type_index to string representing Improv Engine types and names.
 */
std::map<std::type_index, std::string> ImpulsionGenerator::getEngineTypesToEngineNames() const
{
    std::map<std::type_index, std::string> engineTypesToEngineNames;
    for (auto const& improvEngineGenerator : m_improvEngineGenerators)
    {
        std::type_index type = getTypeIndexFromSharedPointerOfBaseClass(improvEngineGenerator);
        engineTypesToEngineNames[type] = improvEngineGenerator->getResourcesIdentifier();
    }

    return engineTypesToEngineNames;
}
