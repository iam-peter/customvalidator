#include "specialvalidator.h"

#include <QRegularExpression>

SpecialValidator::SpecialValidator(QObject *parent)
    : QValidator{parent}
{}

QValidator::State SpecialValidator::validate(QString &input, int &pos) const
{
    if (input.isEmpty())
        return QValidator::Acceptable;

    static QRegularExpression expression("^\\d{0,4}$");
    QRegularExpressionMatch expressionMatch = expression.match(input);

    if (expressionMatch.hasMatch()) {
        if (expressionMatch.captured(0).size() == 4)
            return QValidator::Acceptable;

        return QValidator::Intermediate;
    }

    static QRegularExpression advancedExpression("^(\\d{4})-(\\d{0,4})$");
    QRegularExpressionMatch advancedExpressionMatch = advancedExpression.match(input);

    if (advancedExpressionMatch.hasMatch()) {
        QString lhs = advancedExpressionMatch.captured(1);
        const QString rhs = advancedExpressionMatch.captured(2);

        if (rhs.isEmpty())
            return QValidator::Intermediate;

        if (rhs.size() == 4)
            return lhs.toInt() < rhs.toInt() ? QValidator::Acceptable : QValidator::Invalid;

        lhs.truncate(rhs.size());

        return lhs.toInt() <= rhs.toInt() ? QValidator::Intermediate : QValidator::Invalid;
    }

    return QValidator::Invalid;
}
