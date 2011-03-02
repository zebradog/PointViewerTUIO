/*
 Point Viewer with TUIO output
 
 Copyright (c) 2011 ZD Studios Inc.
 
 Author: Matt Cook <matt@lookitscook.com>
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <PointDrawer.h>
#include <TuioServer.h>
#include <TuioCursor.h>
using namespace TUIO;

class PointDrawerTUIO : public XnVPointDrawer
{
public:
	PointDrawerTUIO(XnUInt32 nHistorySize, xn::DepthGenerator depthGenerator,const char *host="default", int port=0);
	~PointDrawerTUIO();
	
	TuioServer *tuioServer;
	TuioCursor *cursor;
	
	/**
	 * Handle a new message.
	 * Calls other callbacks for each point, then draw the depth map (if needed) and the points
	 */
	void Update(XnVMessage* pMessage);
	/**
	 * Handle creation of a new point, currently only supports single hand
	 */
	void OnPointCreate(const XnVHandPointContext* cxt);
	/**
	 * Handle new position of an existing point
	 */
	void OnPointUpdate(const XnVHandPointContext* cxt);
	/**
	 * Handle destruction of an existing point
	 */
	void OnPointDestroy(XnUInt32 nID);

private:
	TuioTime currentTime;
	int width, height;
};
