#include "improvenginelib/ImpulsionGenerator.h"

#include <filesystem>

#include "improvenginelib/TextualResourcesFileParser.h"
#include "improvenginelib/RandomVectorSampler.h"

ImpulsionGenerator::ImpulsionGenerator(std::vector<std::shared_ptr<IImprovEngineGenerator>> improvEngineGenerators, std::shared_ptr<Displayer> displayer)
    : m_improvEngineGenerators{improvEngineGenerators}
    , m_displayer{displayer}
{}

void ImpulsionGenerator::generateRandomImpulsion(std::vector<IImprovEngineGenerator::EngineType> engineTypes) const
{
    RandomVectorSampler<std::shared_ptr<IImprovEngineGenerator>> randomSampler{};
    std::shared_ptr<IImprovEngineGenerator> improEngineGenerator = randomSampler.sample(m_improvEngineGenerators);

    std::shared_ptr<IContent> content = improEngineGenerator->generateImprovEngineContent();

    m_displayer->displayContent(content);
}

std::map<IImprovEngineGenerator::EngineType, std::string> ImpulsionGenerator::getEngineTypesToEngineNames() const
{
    std::map<IImprovEngineGenerator::EngineType, std::string> engineTypesToEngineNames;
    for (auto const & improvEngineGenerator : m_improvEngineGenerators)
        engineTypesToEngineNames[improvEngineGenerator->getEngineType()] = improvEngineGenerator->getResourcesIdentifier();

    return engineTypesToEngineNames;
}