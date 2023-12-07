#pragma once

#include <memory>
#include <typeindex>
#include <vector>

#include <QCheckBox>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "improvenginelib/ImpulsionGenerator.h"

class UIController
{
public:
    UIController();

    std::shared_ptr<QLabel> getTextDisplayerOutputLabel() const;

    void setImpulsionGenerator(std::shared_ptr<ImpulsionGenerator> impulsionGenerator);

private:
    QWidget m_mainWindow;
    QVBoxLayout m_mainLayout;
    QHBoxLayout m_topLayout;
    QVBoxLayout m_checkboxLayout;
    QStackedWidget m_bottomLayout;
    QFrame m_line;
    std::map<std::shared_ptr<QCheckBox>, std::type_index> m_checkboxesToEngineType;

    std::shared_ptr<QPushButton> m_button;
    std::shared_ptr<QLabel> m_textOutputLabel;

    std::shared_ptr<ImpulsionGenerator> m_impulsionGenerator;
};