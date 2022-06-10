#ifndef SPECIALVALIDATOR_H
#define SPECIALVALIDATOR_H

#include <QValidator>

class SpecialValidator : public QValidator
{
    Q_OBJECT
public:
    explicit SpecialValidator(QObject *parent = nullptr);

    QValidator::State validate(QString &data, int &pos) const;
};

#endif // SPECIALVALIDATOR_H
