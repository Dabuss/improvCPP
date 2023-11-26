#include "improvenginelib/Displayer.h"
#include "improvenginelib/TextContent.h"

Displayer::Displayer(std::shared_ptr<TextDisplayer> textDisplayer) : m_textDisplayer{textDisplayer}
{}

void Displayer::displayContent(std::shared_ptr<IContent> content, QLabel& label)
{
    m_textDisplayer->displayContent(std::dynamic_pointer_cast<TextContent>(content), label);
}