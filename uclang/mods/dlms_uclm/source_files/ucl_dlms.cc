
@begin
include "ucl_dlms.h"
@end

#include "GuruxDLMS/GXDateTime.h"
#include "GuruxDLMS/Objects/GXDLMSData.h"
#include "GuruxDLMS/Objects/GXDLMSClock.h"
#include "GuruxDLMS/Objects/GXDLMSTcpUdpSetup.h"
#include "GuruxDLMS/Objects/GXDLMSProfileGeneric.h"
#include "GuruxDLMS/Objects/GXDLMSAutoConnect.h"
#include "GuruxDLMS/Objects/GXDLMSIECOpticalPortSetup.h"
#include "GuruxDLMS/Objects/GXDLMSActivityCalendar.h"
#include "GuruxDLMS/Objects/GXDLMSDemandRegister.h"
#include "GuruxDLMS/Objects/GXDLMSRegisterMonitor.h"
#include "GuruxDLMS/Objects/GXDLMSActionSchedule.h"
#include "GuruxDLMS/Objects/GXDLMSSapAssignment.h"
#include "GuruxDLMS/Objects/GXDLMSAutoAnswer.h"
#include "GuruxDLMS/Objects/GXDLMSModemConfiguration.h"
#include "GuruxDLMS/Objects/GXDLMSMacAddressSetup.h"
#include "GuruxDLMS/Objects/GXDLMSModemInitialisation.h"
#include "GuruxDLMS/Objects/GXDLMSActionSet.h"

int CGXDLMSBase::PrepareInit(string a_man_id,string a_serial,int a_port)
{/*{{{*/

  // - setup media properties -
  m_Media.SetProtocol(GX_NW_TCPIP);
  m_Media.SetPort(a_port);
  m_Media.SetTrace(GX_TRACE_LEVEL_VERBOSE);
  m_Media.IsServer(true);
  m_Media.AddListener(this);

  // - open media -
  int ret;
  if ((ret = m_Media.Open()) != 0)
  {
    return ret;
  }

  // - create identification string -
  string id_comp_str(16,'0');
  id_comp_str.replace(0,3,a_man_id);
  id_comp_str.replace(id_comp_str.length() - a_serial.length(),a_serial.length(),a_serial);

  CGXDLMSVariant id_complete(id_comp_str.c_str());
  id_complete.ChangeType(DLMS_DATA_TYPE_OCTET_STRING);
  GetItems().push_back(new CGXDLMSData("0.0.42.0.0.255",id_complete));

  // - add electricity id 1 -
  CGXDLMSData *item_el_id1 = new CGXDLMSData("1.1.0.0.0.255",id_comp_str.c_str());
  item_el_id1->GetAttributes().push_back(CGXDLMSAttribute(2,DLMS_DATA_TYPE_STRING));
  GetItems().push_back(item_el_id1);

  // - add electricity id 2 -
  CGXDLMSVariant id_serial(a_serial.c_str());
  id_serial.ChangeType(DLMS_DATA_TYPE_UINT32);

  CGXDLMSData *item_el_id2 = new CGXDLMSData("1.1.0.0.1.255",id_serial);
  item_el_id2->GetAttributes().push_back(CGXDLMSAttribute(2,DLMS_DATA_TYPE_UINT32));
  GetItems().push_back(item_el_id2);

  // - add clock: 0.0.1.0.0.255 -
  CGXDLMSClock* pClock = new CGXDLMSClock();
  GetItems().push_back(pClock);

  return ERROR_CODES_OK;
}/*}}}*/

int CGXDLMSBase::Init()
{/*{{{*/

  // - initialize server after all objects were added -
  int ret = CGXDLMSServerBase::Initialize();
  if (ret != ERROR_CODES_OK)
  {
    return ret;
  }

  return ERROR_CODES_OK;
}/*}}}*/

int CGXDLMSBase::OnRead(CGXDLMSObject* pItem,int index,CGXDLMSVariant& value,DLMS_DATA_TYPE& type)
{/*{{{*/

  // - framework handle logical name -
  if (index == 1)
  {
    return ERROR_CODES_FALSE;
  }

  // - framework handle association objects -
  if (pItem->GetObjectType() == OBJECT_TYPE_ASSOCIATION_LOGICAL_NAME ||
      pItem->GetObjectType() == OBJECT_TYPE_ASSOCIATION_SHORT_NAME)
  {
    return ERROR_CODES_FALSE;
  }

  // - framework handle profile generic -
  if (pItem->GetObjectType() == OBJECT_TYPE_PROFILE_GENERIC)
  {
    return ERROR_CODES_FALSE;
  }

  CGXDLMSVariant null;
  int ret = ((IGXDLMSBase*)pItem)->GetValue(index,0,null,value);
  if (ret != ERROR_CODES_OK)
  {
    return ret;
  }

  // - retrieve item name -
  string item_name;
  pItem->GetLogicalName(item_name);

  // FIXME debug output
  //fprintf(stderr,"READ PAIR: %d - %s\n",value.vt,item_name.c_str());

  // - set value according to item name -
  switch (value.vt)
  {
    case DLMS_DATA_TYPE_DATETIME:
      if (item_name == "0.0.1.0.0.255")
      {
        value = CGXDateTime::Now();
        return ERROR_CODES_OK;
      }
      break;
    default:
      break;
  }

  // - use curent value -
  return ERROR_CODES_FALSE;
}/*}}}*/

int CGXDLMSBase::OnWrite(CGXDLMSObject* pItem,int index,int selector,CGXDLMSVariant& value)
{/*{{{*/
  return ERROR_CODES_FALSE;
}/*}}}*/

int CGXDLMSBase::OnAction(CGXDLMSObject* pItem,int index,CGXDLMSVariant& data)
{/*{{{*/
  return ERROR_CODES_FALSE;
}/*}}}*/

int CGXDLMSBase::OnInvalidConnection()
{/*{{{*/
  return ERROR_CODES_OK;
}/*}}}*/

