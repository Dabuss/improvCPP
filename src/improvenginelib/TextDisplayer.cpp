#include "improvenginelib/TextDisplayer.h"
#include <iostream>


void TextDisplayer::displayContent(std::shared_ptr<IContent> content, QLabel& label)
{
    label.setText(QString::fromStdString(std::dynamic_pointer_cast<TextContent>(content).get()->m_text));
    std::cout << std::dynamic_pointer_cast<TextContent>(content).get()->m_text << std::endl;
}