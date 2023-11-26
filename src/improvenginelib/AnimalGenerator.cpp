#include "improvenginelib/AnimalGenerator.h"
#include "improvenginelib/TextContent.h"

std::shared_ptr<IContent> AnimalGenerator::generateImprovEngineContent()
{
    return std::make_shared<TextContent>("Cactus");
}