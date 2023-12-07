#include "improvenginelib/Displayer.h"

#include "improvenginelib/TextContent.h"

Displayer::Displayer(std::shared_ptr<TextDisplayer> textDisplayer)
    : m_textDisplayer { textDisplayer }
{}

void Displayer::displayContent(std::shared_ptr<IContent> content)
{
    std::shared_ptr<IContentDisplayer> contentDisplayer;
    switch (content->getContentType())
    {
        case IContent::ContentType::text:
        default:
        {
            contentDisplayer = m_textDisplayer;
        }
    }

    contentDisplayer->displayContent(content);
}