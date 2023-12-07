#pragma once

#include <memory>

#include <QLabel>

#include "IContent.h"

class IContentDisplayer
{
public:
    virtual ~IContentDisplayer() = default;
    virtual void displayContent(std::shared_ptr<IContent> content) = 0;
};