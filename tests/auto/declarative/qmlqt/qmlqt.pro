load(qttest_p4)
contains(QT_CONFIG,declarative): QT += declarative
SOURCES += tst_qmlqt.cpp
macx:CONFIG -= app_bundle

DEFINES += SRCDIR=\\\"$$PWD\\\"

# QMAKE_CXXFLAGS = -fprofile-arcs -ftest-coverage
# LIBS += -lgcov