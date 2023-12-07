#include "improvenginelib/TextDisplayer.h"
#include <iostream>

TextDisplayer::TextDisplayer(std::shared_ptr<QLabel> label)
    : m_label{label}
{}

void TextDisplayer::displayContent(std::shared_ptr<IContent> content)
{
    m_label->setText(QString::fromStdString(std::dynamic_pointer_cast<TextContent>(content).get()->m_text));
}