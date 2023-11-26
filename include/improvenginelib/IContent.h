#pragma once

class IContent
{
public:
    enum class ContentType
    {
        text,
        picture,
        video
    };

    virtual ~IContent() = default;
    virtual IContent::ContentType getContentType() = 0;
};