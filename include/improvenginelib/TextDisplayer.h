#pragma once

#include <memory>

#include "IContentDisplayer.h"
#include "TextContent.h"

class TextDisplayer : public IContentDisplayer
{
public:
    ~TextDisplayer(){};
    TextDisplayer(std::shared_ptr<QLabel> label);

    void displayContent(std::shared_ptr<IContent> content) override;

private:
    std::shared_ptr<QLabel> m_label;
};