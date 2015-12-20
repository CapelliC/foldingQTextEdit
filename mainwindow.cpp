/**
 * example code to complete my answer to my question on StackOverflow: see
 *  http://stackoverflow.com/questions/19232882/nice-text-formatting-in-qtextedit-like-qtcreator-does
 * author: CapelliC @2015
 * license: MIT
 */

#include "mainwindow.h"
#include "file2string.h"
#include "foldingQTextEdit.h"

#include <QToolBar>
#include <QAction>

/**
 * @brief MainWindow::MainWindow
 *  sample setup for easy debug: open an editor on this same file
 *  assume running in Debug folder of 'Projects/build/Shadow build'
 * @param parent
 *  Qt standard boilerplate
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto w = new foldingQTextEdit;
    w->setPlainText(file2string("../foldingQTextEdit/mainwindow.cpp"));
    setCentralWidget(w);

    auto toolbar = addToolBar("test");
    connect(toolbar->addAction("fold"), &QAction::triggered, w, &foldingQTextEdit::fold);
    connect(toolbar->addAction("unfold"), &QAction::triggered, w, &foldingQTextEdit::unfold);
    connect(toolbar->addAction("frame"), &QAction::triggered, w, &foldingQTextEdit::frame);
    connect(toolbar->addAction("unframe"), &QAction::triggered, w, &foldingQTextEdit::unframe);
}
