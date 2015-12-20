/**
 * example code to complete my answer to my question on StackOverflow: see
 *  http://stackoverflow.com/questions/19232882/nice-text-formatting-in-qtextedit-like-qtcreator-does
 * author: CapelliC @2015
 * license: MIT
 */

#ifndef FOLDINGQTEXTEDIT_H
#define FOLDINGQTEXTEDIT_H

#include <QTextEdit>
#include "framedTextAttr.h"
#include "foldedTextAttr.h"

/**
 * @brief The foldingQTextEdit class
 */
class foldingQTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    foldingQTextEdit();

private:
    framedTextAttr* framed_handler;
    foldedTextAttr* folded_handler;

public slots:
    void fold();
    void unfold();
    void frame();
    void unframe();
};

#endif // FOLDINGQTEXTEDIT_H
