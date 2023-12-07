#include <QApplication>

#include "improvenginelib/AnimalGenerator.h"
#include "improvenginelib/Displayer.h"
#include "improvenginelib/ImpulsionGenerator.h"
#include "improvenginelib/TextDisplayer.h"
#include "improvenginelib/TextualResourcesFileParser.h"
#include "improvenginelib/UIController.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // UIController
    std::shared_ptr<UIController> uiController
        = std::make_shared<UIController>();

    // Resources parser
    TextualResourcesFileParser textResources {
        std::filesystem::current_path()
    };

    // Content Generators
    std::shared_ptr<AnimalGenerator> animalGenerator = std::make_shared<
        AnimalGenerator>(
        textResources
            .getTextualResources()[IImprovEngineGenerator::EngineNameFromType(
                IImprovEngineGenerator::EngineType::animals)]);

    std::vector<std::shared_ptr<IImprovEngineGenerator>>
        improvEngineGenerators {};
    improvEngineGenerators.push_back(animalGenerator);

    // Content Displayers
    std::shared_ptr<TextDisplayer> textDisplayer
        = std::make_shared<TextDisplayer>(
            uiController->getTextDisplayerOutputLabel());

    // displayer
    std::shared_ptr<Displayer> displayer
        = std::make_shared<Displayer>(textDisplayer);

    // RandomImprovEngineGenerator
    std::shared_ptr<ImpulsionGenerator> impulsionGenerator
        = std::make_shared<ImpulsionGenerator>(improvEngineGenerators, displayer);

    uiController->setImpulsionGenerator(impulsionGenerator);

    // Run the application
    return app.exec();
}