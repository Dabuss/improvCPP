#include <QApplication>

#include "improvenginelib/AnimalGenerator.h"
#include "improvenginelib/BodyPartGenerator.h"
#include "improvenginelib/Displayer.h"
#include "improvenginelib/ImpulsionGenerator.h"
#include "improvenginelib/RandomVectorSampler.h"
#include "improvenginelib/TextDisplayer.h"
#include "improvenginelib/TextualResourcesFileParser.h"
#include "improvenginelib/UIController.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // UIController
    std::shared_ptr<UIController> uiController = std::make_shared<UIController>();

    // Resources parser
    std::shared_ptr<TextualResourcesFileParser> textResources
        = std::make_shared<TextualResourcesFileParser>(std::filesystem::current_path());

    // Content Generators
    std::shared_ptr<RandomVectorSampler<std::string>> randomVectorSampler
        = std::make_shared<RandomVectorSampler<std::string>>();
    std::shared_ptr<AnimalGenerator> animalGenerator
        = std::make_shared<AnimalGenerator>(textResources, randomVectorSampler);
    std::shared_ptr<BodyPartGenerator> bodyPartGenerator
        = std::make_shared<BodyPartGenerator>(textResources, randomVectorSampler);

    std::vector<std::shared_ptr<IImprovEngineGenerator>> improvEngineGenerators {};
    improvEngineGenerators.push_back(animalGenerator);
    improvEngineGenerators.push_back(bodyPartGenerator);

    // Content Displayers
    std::shared_ptr<TextDisplayer> textDisplayer
        = std::make_shared<TextDisplayer>(uiController->getTextDisplayerOutputLabel());

    // displayer
    std::shared_ptr<Displayer> displayer = std::make_shared<Displayer>(textDisplayer);

    // RandomImprovEngineGenerator
    std::shared_ptr<ImpulsionGenerator> impulsionGenerator
        = std::make_shared<ImpulsionGenerator>(improvEngineGenerators, displayer);

    uiController->setImpulsionGenerator(impulsionGenerator);

    // Run the application
    return app.exec();
}