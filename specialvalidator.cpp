#include "specialvalidator.h"

#include <QRegularExpression>

SpecialValidator::SpecialValidator(QObject *parent)
    : QValidator{parent}
{}

QValidator::State SpecialValidator::validate(QString &input, int &pos) const
{
    if (input.isEmpty())
        return QValidator::Acceptable;

    static QRegularExpression acceptableExpression("^\\d{4}$");
    static QRegularExpression intermediateExpression("^\\d{0,4}$");

    if (acceptableExpression.match(input).hasMatch())
        return QValidator::Acceptable;

    if (intermediateExpression.match(input).hasMatch())
        return QValidator::Intermediate;

    static QRegularExpression acceptableAdvancedExpression("^(\\d{4})-(\\d{4})$");
    static QRegularExpression intermediateAdvancedteExpression("^(\\d{4})-(\\d{0,4})$");

    auto acceptableMatch = acceptableAdvancedExpression.match(input);

    if (acceptableMatch.hasMatch()) {
        int lhs = acceptableMatch.captured(1).toInt();
        int rhs = acceptableMatch.captured(2).toInt();

        if (lhs < rhs)
            return QValidator::Acceptable;
        else
            return QValidator::Invalid;
    }

    auto intermediateMatch = intermediateAdvancedteExpression.match(input);

    if (intermediateMatch.hasMatch()) {
        QString lhs = intermediateMatch.captured(1);
        QString rhs = intermediateMatch.captured(2);

        if (rhs.isEmpty())
            return QValidator::Intermediate;

        lhs.truncate(rhs.size());

        if (lhs.toInt() <= rhs.toInt())
            return QValidator::Intermediate;
        else
            return QValidator::Invalid;
    }

    return QValidator::Invalid;
}
