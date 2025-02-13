/**********************************************************************
Weathergrib: meteorological GRIB file viewer
Copyright (C) 2008-2012 - Jacques Zaninetti - http://www.zygrib.org

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
***********************************************************************/

#ifndef LONGTASKPROGRESS_H
#define LONGTASKPROGRESS_H

#include <QProgressDialog>
#include "LongTaskMessage.h"

//-----------------------------------------
class LongTaskProgress : public QObject
{
Q_OBJECT

	public:
			
		LongTaskProgress (QWidget *parent=NULL);
		~LongTaskProgress ();

		void setWindowTitle (const QString& title);
		void setVisible (bool vis);
		QProgressDialog *progress;

		bool continueDownload;

public slots:
    	void setValue(int value);
    	void setMessage(LongTaskMessage::LongTaskMessageType msgtype);

    	void downloadCanceled();

signals:
    	void newMessage(LongTaskMessage::LongTaskMessageType msgtype);
    	void valueChanged(int newValue);
    	void canceled();
};

#endif
