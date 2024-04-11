#ifndef PLATFORMTYPE_H
#define PLATFORMTYPE_H

#include <QMap>
#include <QString>

enum class PlatformType {
    NONE,
    DEFAULT,
    CANT_JUMP_FROM
};

const QMap<PlatformType, QString> PLATFORM_TYPE_TO_STRING({
    std::make_pair(PlatformType::NONE, "NONE"),
    std::make_pair(PlatformType::DEFAULT, "DEFAULT"),
    std::make_pair(PlatformType::CANT_JUMP_FROM, "CANT_JUMP_FROM")
});
const QMap<QString, PlatformType> STRING_TO_PLATFORM_TYPE({
    std::make_pair("NONE", PlatformType::NONE),
    std::make_pair("DEFAULT", PlatformType::DEFAULT),
    std::make_pair("CANT_JUMP_FROM", PlatformType::CANT_JUMP_FROM)
});


#endif // PLATFORMTYPE_H
