/**
 * example code to complete my answer to my question on StackOverflow: see
 *  http://stackoverflow.com/questions/19232882/nice-text-formatting-in-qtextedit-like-qtcreator-does
 * author: CapelliC @2015
 * license: MIT
 */

#include "foldingQTextEdit.h"

foldingQTextEdit::foldingQTextEdit()
    : framed_handler(new framedTextAttr(this))
    , folded_handler(new foldedTextAttr(this))
{
    document()->documentLayout()->registerHandler(framed_handler->type(), framed_handler);
    document()->documentLayout()->registerHandler(folded_handler->type(), folded_handler);
    setLineWrapMode(NoWrap);
}

void foldingQTextEdit::fold() {
    folded_handler->fold(textCursor());
}
void foldingQTextEdit::unfold() {
    folded_handler->unfold(textCursor());
}

void foldingQTextEdit::frame() {
    framed_handler->frame(textCursor());
}
void foldingQTextEdit::unframe() {
    framed_handler->unframe(textCursor());
}
