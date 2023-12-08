#include "improvenginelib/engines/BodyPartGenerator.h"

#include <algorithm>
#include <fstream>

#include "improvenginelib/TextContent.h"

BodyPartGenerator::BodyPartGenerator(
    std::shared_ptr<ITextualResourcesFileParser> textualResourcesFileParser,
    std::shared_ptr<RandomVectorSampler<std::string>> randVectorSampler)
    : m_bodyParts { textualResourcesFileParser->getItem(getResourcesIdentifier()) }
    , m_randomBodyPartSampler { randVectorSampler }
{
    if (m_bodyParts.empty())
        throw std::invalid_argument("No body part available.");
}

std::shared_ptr<IContent> BodyPartGenerator::generateImprovEngineContent() const
{
    return std::make_shared<TextContent>(m_randomBodyPartSampler->sample(m_bodyParts));
}

std::string BodyPartGenerator::getResourcesIdentifier() const { return m_resourceIdentifier; }