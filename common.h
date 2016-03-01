/*!
 * \file common.h
 * \date 2015/10/30 10:54
 *
 * \author Wu Yusheng (Michael.Woo)
 * Contact: wuys_bj@163.com
 *
 * \brief 通用配置参数
 *
 *		  系统用到的全局变量
 *
 * \note
*/
#ifndef __WS_COMMON_H__
#define __WS_COMMON_H__


//地图控件最小尺寸
#define WINDOW_MIN_WIDHT			800
#define WINDOW_MIN_HEIGHT			500

//数据库文件
#define DB_FILE_PATH				"D:/Projects/sysconfig/db/test.mdb"


#define POINT_TABLE_NAME			"TblPoint"
#define PORT_TABLE_NAME				"TblPort"
#define DEVICE_TABLE_NAME			"TblDevice"
#define UC_TABLE_NAME				"TblUC"
#define PROJECT_TABLE_NAME			"TblProject"
#define MD_TABLE_NAME				"TblMDPoint"
#define PROTOCOL_TABLE_NAME			"TblProtocol"

#define TEMPLATE_PROJECT			"template/projx"

#define DEVICE_DDL					"CREATE TABLE TblDevice (DevID int primary key, PortID int, Address int, LbOption int, DevType varchar,DevDsp varchar)"
#define DIAODU_DDL					"CREATE TABLE TblDiaoDuPoint (PtID int primary key, DevID int, PtType varchar, FUN int, INF int, Ratio int, Revise int, YXReverse int, PtAttr int)"
#define MODBUS_DDL					"CREATE TABLE TblMDPoint (ID int primary key, DevID int, FunCode int, StartRegister int, RegisterLen int, RegisterType int, ResponsesTime int, ValueType int, BlockType int, DeviceSeries int, PollTime int, CreateSoe int)"
#define POINT_DDL					"CREATE TABLE TblPoint (PtID int primary key, DevID int, PtType varchar, FUN int, INF int, Ratio int, Revise int, Append int, YXRelateID int, YXReverse int, YKOutType int, PtDsp varchar)"
#define PORT_DDL					"CREATE TABLE TblPort (PortID int primary key, UCID int, ProtocolID int, PortNO varchar, PortParameter varchar, PortType int, SockPort int, ResponseTime int, AssPortID int, MasterPort int, RepeatSendNum int, DataFllow int, IsUse int)"
#define PROJECT_DDL					"CREATE TABLE TblProject (ID int primary key, ProjectName varchar, OfflineTime int, CheckTime int, LbTime int, IP1 varchar, IP2 varchar)"
#define PROTOCOL_DDL				"CREATE TABLE TblProtocol (ProtocolID int primary key, ProtocolCode varchar, ProtocolNum int, RelateID int)"
#define UC_DDL						"CREATE TABLE TblUC (UCID int primary key, UCName varchar, IP varchar, UCSeries varchar)"

#endif // __WS_COMMON_H__