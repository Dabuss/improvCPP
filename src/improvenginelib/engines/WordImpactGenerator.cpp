#include "improvenginelib/engines/WordImpactGenerator.h"

#include <algorithm>
#include <fstream>

#include "improvenginelib/TextContent.h"

WordImpactGenerator::WordImpactGenerator(
    std::shared_ptr<ITextualResourcesFileParser> textualResourcesFileParser,
    std::shared_ptr<RandomVectorSampler<std::string>> randVectorSampler)
    : m_words { textualResourcesFileParser->getItem(getResourcesIdentifier()) }
    , m_randomWordSampler { randVectorSampler }
{
    if (m_words.empty())
        throw std::invalid_argument("No word available.");
}

std::shared_ptr<IContent> WordImpactGenerator::generateImprovEngineContent() const
{
    return std::make_shared<TextContent>(m_randomWordSampler->sample(m_words));
}

std::string WordImpactGenerator::getResourcesIdentifier() const { return m_resourceIdentifier; }