/**
 * example code to complete my answer to my question on StackOverflow: see
 *  http://stackoverflow.com/questions/19232882/nice-text-formatting-in-qtextedit-like-qtcreator-does
 * author: CapelliC @2015
 * license: MIT
 */

#ifndef FRAMEDTEXTATTR_H
#define FRAMEDTEXTATTR_H

#include <QObject>
#include <QPainter>
#include <QTextDocument>
#include <QTextObjectInterface>

class framedTextAttr : public QObject, public QTextObjectInterface
{
    Q_OBJECT
    Q_INTERFACES(QTextObjectInterface)

public:
    explicit framedTextAttr(QObject *parent = 0);

    static int type() { return QTextFormat::UserObject+1; }
    static int prop() { return 1; }

    QSizeF intrinsicSize(QTextDocument *doc, int posInDocument, const QTextFormat &format);
    void drawObject(QPainter *painter, const QRectF &rect, QTextDocument *doc, int posInDocument, const QTextFormat &format);

    void frame(QTextCursor c);
    bool unframe(QTextCursor c);
};

#endif // FRAMEDTEXTATTR_H
