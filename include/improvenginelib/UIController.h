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

/**
 * @brief The UIController class manages the user interface for the Improv Engine application.
 */
class UIController
{
public:
    /**
     * @brief Default constructor for the UIController class.
     */
    UIController();

    /**
     * @brief Getter for the text output label.
     * @return Shared pointer to the QLabel used for displaying text output.
     */
    std::shared_ptr<QLabel> getTextDisplayerOutputLabel() const;

    /**
     * @brief Setter for the impulsion generator.
     * @param impulsionGenerator Shared pointer to the ImpulsionGenerator instance.
     */
    void setImpulsionGenerator(std::shared_ptr<ImpulsionGenerator> impulsionGenerator);

private:
    QWidget m_mainWindow; ///< Main window widget.
    QVBoxLayout m_mainLayout; ///< Main vertical layout.
    QHBoxLayout m_topLayout; ///< Top horizontal layout.
    QVBoxLayout m_checkboxLayout; ///< Vertical layout for checkboxes.
    QStackedWidget m_bottomLayout; ///< Stacked widget for the bottom layout.
    QFrame m_line; ///< Horizontal line frame.
    std::map<std::shared_ptr<QCheckBox>, std::type_index> m_checkboxesToEngineType; ///< Map associating checkboxes with engine types.

    std::shared_ptr<QPushButton> m_button; ///< Button for generating Improv Engine.
    std::shared_ptr<QLabel> m_textOutputLabel; ///< Label for displaying text output.

    std::shared_ptr<ImpulsionGenerator> m_impulsionGenerator; ///< Impulsion generator instance.
};
