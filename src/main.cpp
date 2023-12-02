#include <QApplication>
#include <QCheckBox>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <filesystem>

#include <iostream>
#include <typeinfo>

#include "improvenginelib/AnimalGenerator.h"
#include "improvenginelib/Displayer.h"
#include "improvenginelib/TextualResourcesFileParser.h"
#include "improvenginelib/TextDisplayer.h"

// Function to be called when the button is clicked
void generateDisplayImprovContraint(QLabel& label)
{
    std::filesystem::path pathToExecutableDirectory = std::filesystem::current_path();
    TextualResourcesFileParser resources { pathToExecutableDirectory };
    AnimalGenerator ag { resources.getItem("animals") };
    std::shared_ptr<IContent> content = ag.generateImprovEngineContent();

    std::shared_ptr<TextDisplayer> td = std::make_shared<TextDisplayer>();
    Displayer displayer { td };

    displayer.displayContent(content, label);
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Create the main window
    QWidget mainWindow;
    mainWindow.setWindowTitle("Qt Hello World");

    // Set a minimum width for the main window
    mainWindow.setMinimumWidth(400);

    // Create a vertical layout for the main window
    QVBoxLayout mainLayout(&mainWindow);

    // Create the top part layout (horizontal layout)
    QHBoxLayout topLayout {};

    // Create a vertical layout for the checkbox list
    QVBoxLayout checkboxLayout {};

    // Create some checkboxes (you can add more based on your needs)
    QCheckBox checkbox1("Option 1");
    QCheckBox checkbox2("Option 2");
    QCheckBox checkbox3("Option 3");

    // Add checkboxes to the layout
    checkboxLayout.addWidget(&checkbox1);
    checkboxLayout.addWidget(&checkbox2);
    checkboxLayout.addWidget(&checkbox3);

    // Add the checkbox layout to the top layout
    topLayout.addLayout(&checkboxLayout);

    // Create a button and add it to the top layout
    QPushButton button { "Generate Improv Engine" };
    topLayout.addWidget(&button);

    // Create a widget for text display
    QLabel textWidget("...");

    // Connect the button click signal to the generateDisplayImprovContraint function
    QObject::connect(&button, &QPushButton::clicked, [&textWidget]() { generateDisplayImprovContraint(textWidget); });

    // Create a stacked widget for the bottom part (to switch between different displays)
    QStackedWidget bottomStackedWidget {};
    bottomStackedWidget.setMinimumHeight(200);

    // Add the text widget to the stacked widget
    bottomStackedWidget.addWidget(&textWidget);

    // Create a horizontal line using QFrame
    QFrame line { &mainWindow };
    line.setFrameShape(QFrame::HLine);
    line.setFrameShadow(QFrame::Sunken);

    // Set the main layout for the main window
    mainLayout.addLayout(&topLayout);

    // Add the horizontal line to the main layout
    mainLayout.addWidget(&line);

    // Add the stacked widget to the main layout
    mainLayout.addWidget(&bottomStackedWidget);

    // Show the main window
    mainWindow.show();

    // Run the application
    return app.exec();
}