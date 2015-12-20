/**
 * example code to complete my answer to my question on StackOverflow: see
 *  http://stackoverflow.com/questions/19232882/nice-text-formatting-in-qtextedit-like-qtcreator-does
 * author: CapelliC @2015
 * license: MIT
 */

#include "foldedTextAttr.h"
#include <QTextDocumentFragment>

foldedTextAttr::foldedTextAttr(QObject *parent) : QObject(parent) {
}

QSizeF foldedTextAttr::intrinsicSize(QTextDocument *doc, int posInDocument, const QTextFormat &format) {
    Q_UNUSED(doc)
    Q_UNUSED(posInDocument)
    Q_ASSERT(format.type() == format.CharFormat);
    const QTextCharFormat &tf = reinterpret_cast<const QTextCharFormat&>(format);

    QFont fn = tf.font();
    QFontMetrics fm(fn);

    QString s("...");
    QSizeF sz = fm.boundingRect(s).size();
    return sz;
}

void foldedTextAttr::drawObject(QPainter *painter, const QRectF &rect, QTextDocument *doc, int posInDocument, const QTextFormat &format) {

    Q_UNUSED(doc)
    Q_UNUSED(posInDocument)
    Q_ASSERT(format.type() == format.CharFormat);
    QString s("...");
    painter->drawText(rect, s);
    painter->drawRect(rect);
}

Q_DECLARE_METATYPE(QTextDocumentFragment)

void foldedTextAttr::fold(QTextCursor c) {
    QTextCharFormat f;
    f.setObjectType(type());
    QVariant v; v.setValue(c.selection());
    f.setProperty(prop(), v);
    c.insertText(QString(QChar::ObjectReplacementCharacter), f);
}
bool foldedTextAttr::unfold(QTextCursor c) {
    if (!c.hasSelection()) {
        QTextCharFormat f = c.charFormat();
        if (f.objectType() == type()) {
            c.movePosition(c.Left, c.KeepAnchor);
            QVariant v = f.property(prop());
            auto q = v.value<QTextDocumentFragment>();
            c.insertFragment(q);
            return true;
        }
    }
    return false;
}
