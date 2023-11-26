#pragma once

#include <memory>

#include "IContentDisplayer.h"
#include "TextContent.h"

class TextDisplayer : public IContentDisplayer
{
public:
    ~TextDisplayer(){};
    TextDisplayer() {}

    void displayContent(std::shared_ptr<IContent> content, QLabel& label) override;
};