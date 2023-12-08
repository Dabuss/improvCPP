/**
 * @file UIController.cpp
 * @brief Implementation of the UIController class for handling the user interface.
 */

#include "improvenginelib/UIController.h"

#include <iostream>

/**
 * @brief Default constructor for the UIController class.
 */
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
    // Set up the main window
    m_mainWindow.setWindowTitle("Qt Hello World");
    m_mainWindow.setMinimumWidth(400);

    // Add widgets to layouts
    m_topLayout.addWidget(m_button.get());
    m_topLayout.addLayout(&m_checkboxLayout);
    m_bottomLayout.addWidget(m_textOutputLabel.get());
    m_bottomLayout.setMinimumHeight(200);

    // Arrange layouts
    m_mainLayout.addLayout(&m_topLayout);
    m_mainLayout.addWidget(&m_line);
    m_mainLayout.addWidget(&m_bottomLayout);

    // Set the main layout for the main window
    m_mainWindow.setLayout(&m_mainLayout);

    // Display the main window
    m_mainWindow.show();
}

/**
 * @brief Getter for the text output label.
 * @return Shared pointer to the QLabel used for displaying text output.
 */
std::shared_ptr<QLabel> UIController::getTextDisplayerOutputLabel() const
{
    return m_textOutputLabel;
}

/**
 * @brief Setter for the impulsion generator.
 * @param impulsionGenerator Shared pointer to the ImpulsionGenerator instance.
 */
void UIController::setImpulsionGenerator(std::shared_ptr<ImpulsionGenerator> impulsionGenerator)
{
    m_impulsionGenerator = impulsionGenerator;

    // Retrieve engine types and names from the impulsion generator
    std::map<std::type_index, std::string> engineTypesToEngineNames
        = impulsionGenerator->getEngineTypesToEngineNames();

    // Create checkboxes dynamically based on engine types
    for (auto const& engineTypeToEngineName : engineTypesToEngineNames)
    {
        std::shared_ptr<QCheckBox> checkbox
            = std::make_shared<QCheckBox>(QString::fromStdString(engineTypeToEngineName.second));

        // Associate checkbox with the type_index of the Engine in a map
        m_checkboxesToEngineType.insert(std::make_pair(checkbox, engineTypeToEngineName.first));

        // Add the checkbox to the layout
        m_checkboxLayout.addWidget(checkbox.get());
    }

    // Bind ImpulsionGenerator callback to the button clicked callback
    QObject::connect(m_button.get(), &QPushButton::clicked,
        [this]()
        {
            // Retrieve which checkboxes are checked and their associated engine type_index
            std::vector<std::type_index> typesToUse;
            for (auto const& checkBoxToEngineType : m_checkboxesToEngineType)
            {
                if (checkBoxToEngineType.first->isChecked())
                    typesToUse.push_back(checkBoxToEngineType.second);
            }

            // Handle the case where no checkbox is checked
            if (typesToUse.empty())
            {
                this->m_textOutputLabel->setText(
                    "Toggle au moins une catégories pour générer une impulsion.");
                return;
            }

            // Generate a random impulsion based on the selected engine types
            m_impulsionGenerator->generateRandomImpulsion(typesToUse);
        });
}
