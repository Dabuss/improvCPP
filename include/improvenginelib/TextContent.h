#pragma once

#include <string>
#include "improvenginelib/IContent.h"

class TextContent : public IContent
{
public:
    ~TextContent() = default;
    TextContent(std::string const &text) : m_text{text} {};
    
    IContent::ContentType getContentType() override
    {
        return IContent::ContentType::text;
    }

    std::string m_text;
};