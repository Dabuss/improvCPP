#include "improvenginelib/UIController.h"

#include <iostream>

UIController::UIController()
    : m_mainWindow {}
    , m_mainLayout {}
    , m_topLayout {}
    , m_checkboxLayout {}
    , m_bottomLayout {}
    , m_line {}
    , m_button { std::make_shared<QPushButton>("Generate Improv Engine") }
    , m_textOutputLabel { std::make_shared<QLabel>("...") }
    , m_impulsionGenerator {}
{
    m_mainWindow.setWindowTitle("Qt Hello World");

    // Set a minimum width for the main window
    m_mainWindow.setMinimumWidth(400);

    m_topLayout.addWidget(m_button.get());

    m_line.setFrameShape(QFrame::HLine);
    m_line.setFrameShadow(QFrame::Sunken);

    m_topLayout.addLayout(&m_checkboxLayout);

    m_bottomLayout.addWidget(m_textOutputLabel.get());
    m_bottomLayout.setMinimumHeight(200);

    m_mainLayout.addLayout(&m_topLayout);
    m_mainLayout.addWidget(&m_line);
    m_mainLayout.addWidget(&m_bottomLayout);

    m_mainWindow.setLayout(&m_mainLayout);

    m_mainWindow.show();
}

std::shared_ptr<QLabel> UIController::getTextDisplayerOutputLabel() const
{
    return m_textOutputLabel;
}

void UIController::setImpulsionGenerator(std::shared_ptr<ImpulsionGenerator> impulsionGenerator)
{
    m_impulsionGenerator = impulsionGenerator;

    std::map<std::type_index, std::string> engineTypesToEngineNames
        = impulsionGenerator->getEngineTypesToEngineNames();

    for (auto const& engineTypeToEngineName : engineTypesToEngineNames)
    {
        std::shared_ptr<QCheckBox> checkbox
            = std::make_shared<QCheckBox>(QString::fromStdString(engineTypeToEngineName.second));

        m_checkboxesToEngineType.insert(std::make_pair(checkbox, engineTypeToEngineName.first));

        m_checkboxLayout.addWidget(checkbox.get());
    }

    // bind RandomImprovEngineGenetor callback to the button
    QObject::connect(m_button.get(), &QPushButton::clicked,
        [this]()
        {
            std::vector<std::type_index> typesToUse;
            for (auto const& checkBoxToEngineType : m_checkboxesToEngineType)
            {
                if (checkBoxToEngineType.first->isChecked())
                    typesToUse.push_back(checkBoxToEngineType.second);
            }

            if (typesToUse.empty())
            {
                this->m_textOutputLabel->setText(
                    "Toggle au moins une catégorie pour générer une impulsion.");
                return;
            }
            m_impulsionGenerator->generateRandomImpulsion(typesToUse);
        });
}
