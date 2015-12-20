/**
 * example code to complete my answer to my question on StackOverflow: see
 *  http://stackoverflow.com/questions/19232882/nice-text-formatting-in-qtextedit-like-qtcreator-does
 * author: CapelliC @2015
 * license: MIT
 */

#ifndef FOLDEDTEXTATTR_H
#define FOLDEDTEXTATTR_H

#include <QObject>
#include <QPainter>
#include <QTextDocument>
#include <QTextObjectInterface>

class foldedTextAttr : public QObject, public QTextObjectInterface
{
    Q_OBJECT
    Q_INTERFACES(QTextObjectInterface)

public:
    explicit foldedTextAttr(QObject *parent = 0);

    static int type() { return QTextFormat::UserObject+2; }
    static int prop() { return 2; }

    QSizeF intrinsicSize(QTextDocument *doc, int posInDocument, const QTextFormat &format);
    void drawObject(QPainter *painter, const QRectF &rect, QTextDocument *doc, int posInDocument, const QTextFormat &format);

    void fold(QTextCursor c);
    bool unfold(QTextCursor c);
};

#endif // FOLDEDTEXTATTR_H
