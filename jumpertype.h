#ifndef JUMPERTYPE_H
#define JUMPERTYPE_H

#include <QMap>
#include <QString>

enum class JumperType {
    NONE,
    DEFAULT,
    FAST,
    BIG
};

const QMap<JumperType, QString> JUMPER_TYPE_TO_STRING({
    std::make_pair(JumperType::NONE, "NONE"),
    std::make_pair(JumperType::DEFAULT, "DEFAULT"),
    std::make_pair(JumperType::FAST, "FAST"),
    std::make_pair(JumperType::BIG, "BIG"),
});
const QMap<QString, JumperType> STRING_TO_JUMPER_TYPE({
    std::make_pair("NONE", JumperType::NONE),
    std::make_pair("DEFAULT", JumperType::DEFAULT),
    std::make_pair("FAST", JumperType::FAST),
    std::make_pair("BIG", JumperType::BIG)
});

#endif // JUMPERTYPE_H
