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

std::vector<IImprovEngineGenerator::EngineType> ImpulsionGenerator::getEngineTypes() const
{
    std::vector<IImprovEngineGenerator::EngineType> engineTypes;
    engineTypes.reserve(m_improvEngineGenerators.size());

    std::transform(m_improvEngineGenerators.begin(), m_improvEngineGenerators.end(), std::back_inserter(engineTypes), [](std::shared_ptr<IImprovEngineGenerator> const & improvEngineGenerator)
    {
        return improvEngineGenerator->getEngineType();
    });

    return engineTypes;
}