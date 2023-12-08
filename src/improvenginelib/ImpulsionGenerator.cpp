#include "improvenginelib/ImpulsionGenerator.h"

#include <filesystem>

#include "improvenginelib/RandomVectorSampler.h"
#include "improvenginelib/TextualResourcesFileParser.h"

namespace
{

template <typename T>
std::type_index getTypeIndexFromSharedPointerOfBaseClass(std::shared_ptr<T> ptr)
{
#pragma warning(push)
#pragma warning(disable : <warning - number>)

    return typeid(*ptr);

#pragma warning(pop)
}

template <typename T> bool isPointerHoldingThisType(std::shared_ptr<T> ptr, std::type_index type)
{
    std::type_index ptrType = getTypeIndexFromSharedPointerOfBaseClass(ptr);
    return type == ptrType;
}

}

ImpulsionGenerator::ImpulsionGenerator(
    std::vector<std::shared_ptr<IImprovEngineGenerator>> improvEngineGenerators,
    std::shared_ptr<Displayer> displayer)
    : m_improvEngineGenerators { improvEngineGenerators }
    , m_displayer { displayer }
{
}

void ImpulsionGenerator::generateRandomImpulsion(std::vector<std::type_index> engineTypes) const
{
    RandomVectorSampler<std::shared_ptr<IImprovEngineGenerator>> randomSampler {};

    std::vector<std::shared_ptr<IImprovEngineGenerator>> selectedImprovEngines;
    selectedImprovEngines.reserve(m_improvEngineGenerators.size());
    for (std::type_index const& engineType : engineTypes)
    {
        auto it = std::find_if(m_improvEngineGenerators.begin(), m_improvEngineGenerators.end(),
            [engineType](std::shared_ptr<IImprovEngineGenerator> const& improvEngineGenerator)
            {
                return isPointerHoldingThisType(improvEngineGenerator, engineType);
            });

        if (it != m_improvEngineGenerators.end())
            selectedImprovEngines.push_back(*it);
    }

    std::shared_ptr<IImprovEngineGenerator> improEngineGenerator
        = randomSampler.sample(selectedImprovEngines);

    std::shared_ptr<IContent> content = improEngineGenerator->generateImprovEngineContent();

    m_displayer->displayContent(content);
}

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
