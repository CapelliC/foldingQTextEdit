/**
 * example code to complete my answer to my question on StackOverflow: see
 *  http://stackoverflow.com/questions/19232882/nice-text-formatting-in-qtextedit-like-qtcreator-does
 * author: CapelliC @2015
 * license: MIT
 */

#include "framedTextAttr.h"
#include <QDebug>

framedTextAttr::framedTextAttr(QObject *parent) : QObject(parent) {
}

QSizeF framedTextAttr::intrinsicSize(QTextDocument *doc, int posInDocument, const QTextFormat &format) {
    Q_UNUSED(doc)
    Q_UNUSED(posInDocument)
    Q_ASSERT(format.type() == format.CharFormat);

    return QSizeF(0, 0);
}

void framedTextAttr::drawObject(QPainter *painter, const QRectF &rect, QTextDocument *doc, int posInDocument, const QTextFormat &format) {
    Q_UNUSED(doc)
    Q_UNUSED(posInDocument)
    Q_ASSERT(format.type() == format.CharFormat);
    const QTextCharFormat &tf = reinterpret_cast<const QTextCharFormat&>(format);

    QFont fn = tf.font();
    QFontMetrics fm(fn);

    QString s = format.property(prop()).toString();
    QSizeF sz = fm.boundingRect(s).size();

    QRectF Rect(rect.topLeft(), sz);
    Rect.moveTop(rect.top() - sz.height());
    Rect.adjust(0, 3, 0, 3);

    painter->drawRoundedRect(Rect, 4, 4);
}

void framedTextAttr::frame(QTextCursor c) {
    QTextCharFormat f;
    f.setObjectType(type());

    f.setProperty(prop(), c.selectedText());

    //c.clearSelection();
    if (c.selectionEnd() > c.selectionStart()) {
        c.setPosition(c.selectionStart());
    } else {
        c.setPosition(c.selectionEnd());
    }

    c.insertText(QString(QChar::ObjectReplacementCharacter), f);
}

bool framedTextAttr::unframe(QTextCursor c) {
    auto f = c.charFormat();
    if (f.type() == type()) {
        c.deleteChar();
        return true;
    }
    return false;
}
