#pragma once

#include <memory>
#include <typeinfo>

#include <QLabel>

#include "IContent.h"
#include "TextDisplayer.h"

class Displayer
{
public:
    Displayer(std::shared_ptr<TextDisplayer> textDisplayer);

    void displayContent(std::shared_ptr<IContent> content);

private:
    std::shared_ptr<TextDisplayer> m_textDisplayer;
};