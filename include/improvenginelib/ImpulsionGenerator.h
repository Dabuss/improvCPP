#pragma once

#include <memory>

#include <QLabel>
#include <QPushButton>

#include "improvenginelib/Displayer.h"
#include "improvenginelib/IImprovEngineGenerator.h"
#include "improvenginelib/TextualResourcesFileParser.h"

class ImpulsionGenerator {
public:
    ImpulsionGenerator(std::vector<std::shared_ptr<IImprovEngineGenerator>> improvEngineGenerators, std::shared_ptr<Displayer> displayer);

    void generateRandomImpulsion(std::vector<IImprovEngineGenerator::EngineType> improvEngineTypes) const;

    std::vector<IImprovEngineGenerator::EngineType> getEngineTypes() const;

private:
    std::vector<std::shared_ptr<IImprovEngineGenerator>> m_improvEngineGenerators;
    std::shared_ptr<Displayer> m_displayer;
};