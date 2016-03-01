unix{
	CURRENT_PROJECT_PATH = $$system(pwd)
}
win32{
	CURRENT_PROJECT_PATH = .
}

CONFIG  	+= 	qt debug
QT 			+= 	core gui widgets sql
TEMPLATE 	= 	app
TARGET 		= 	ConfigExport

INCLUDEPATH += 	./include

DEPENDPATH  +=  ./lib

  
#####################################################################
#.h
HEADERS 	+=  mainwindow.h \
				treewidget.h \
				tablewidget.h \
				util.h \
				common.h \
				model.h \
				delegate.h \
				smarttreemodel.h \
				smartgridcolumn.h \
				exportdialog.h \
				databaseadapter.h
				

#.cpp
SOURCES 	+=  main.cpp \
				mainwindow.cpp \
				treewidget.cpp \
				tablewidget.cpp \
				util.cpp \
				model.cpp \
				delegate.cpp \
				smarttreemodel.cpp \
				smartgridcolumn.cpp \
				exportdialog.cpp \
				databaseadapter.cpp

#LIBS

#UI
FORMS  		+=  ui/mainwindow.ui \
				ui/tabledetailwidget.ui \
				ui/exportdialog.ui


#RESOURCES
RESOURCES   += 	resource/sysconfig.qrc
RC_FILE 	=   sysconfig.rc


