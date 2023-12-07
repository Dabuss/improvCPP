#include "improvenginelib/ImpulsionGenerator.h"

#include <filesystem>

#include "improvenginelib/TextualResourcesFileParser.h"
#include "improvenginelib/RandomVectorSampler.h"

ImpulsionGenerator::ImpulsionGenerator(std::vector<std::shared_ptr<IImprovEngineGenerator>> improvEngineGenerators, std::shared_ptr<Displayer> displayer)
    : m_improvEngineGenerators{improvEngineGenerators}
    , m_displayer{displayer}
{}

void ImpulsionGenerator::generateRandomImpulsion(std::vector<std::type_index> engineTypes) const
{
    RandomVectorSampler<std::shared_ptr<IImprovEngineGenerator>> randomSampler{};
    std::shared_ptr<IImprovEngineGenerator> improEngineGenerator = randomSampler.sample(m_improvEngineGenerators);

    std::shared_ptr<IContent> content = improEngineGenerator->generateImprovEngineContent();

    m_displayer->displayContent(content);
}

std::map<std::type_index, std::string> ImpulsionGenerator::getEngineTypesToEngineNames() const
{
    std::map<std::type_index, std::string> engineTypesToEngineNames;
    for (auto const & improvEngineGenerator : m_improvEngineGenerators)
        engineTypesToEngineNames[typeid(*improvEngineGenerator)] = improvEngineGenerator->getResourcesIdentifier();

    return engineTypesToEngineNames;
}