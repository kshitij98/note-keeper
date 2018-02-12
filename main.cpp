#include "note.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication EditorApp(argc, argv);
    Note Editor;
    Editor.show();

    return EditorApp.exec();
}
