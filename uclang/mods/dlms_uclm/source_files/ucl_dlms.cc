
@begin
include "ucl_dlms.h"
@end

#include "GuruxDLMS/GXDateTime.h"
#include "GuruxDLMS/Objects/GXDLMSData.h"
#include "GuruxDLMS/Objects/GXDLMSRegister.h"
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

int CGXDLMSBase::Init(int port)
{/*{{{*/

  // FIXME TODO process parameters
  std::string manufacturer_id = "ELM";
  std::string serial_number = "123456";

  // - setup media properties -
  m_Media.SetProtocol(GX_NW_TCPIP);
  m_Media.SetPort(port);
  m_Media.SetTrace(GX_TRACE_LEVEL_VERBOSE);
  m_Media.IsServer(true);
  m_Media.AddListener(this);

  // - open media -
  int ret;
  if ((ret = m_Media.Open()) != 0)
  {
    fprintf(stderr,"Media open failed %d",ret);
    return ret;
  }

  // - create identification string -
  std::string id_comp_str(16,'0');
  id_comp_str.replace(0,3,manufacturer_id);
  id_comp_str.replace(id_comp_str.length() - serial_number.length(),serial_number.length(),serial_number);

  CGXDLMSVariant id_complete(id_comp_str.c_str());
  id_complete.ChangeType(DLMS_DATA_TYPE_OCTET_STRING);
  GetItems().push_back(new CGXDLMSData("0.0.42.0.0.255",id_complete));

  // - register electricity id 1 -
  CGXDLMSData *item_el_id1 = new CGXDLMSData("1.1.0.0.0.255",id_comp_str.c_str());
  item_el_id1->GetAttributes().push_back(CGXDLMSAttribute(2,DLMS_DATA_TYPE_STRING));
  GetItems().push_back(item_el_id1);

  // - register electricity id 2 -
  CGXDLMSVariant id_serial(serial_number.c_str());
  id_serial.ChangeType(DLMS_DATA_TYPE_UINT32);

  CGXDLMSData *item_el_id2 = new CGXDLMSData("1.1.0.0.1.255",id_serial);
  item_el_id2->GetAttributes().push_back(CGXDLMSAttribute(2,DLMS_DATA_TYPE_UINT32));
  GetItems().push_back(item_el_id2);

  // - pointer to register item -
  CGXDLMSRegister *item_reg;

  // - add register VALUE_ACTIVE_ENERGY_POSITIVE -
  item_reg = new CGXDLMSRegister("1.0.1.8.0.255",1.0,45,0.0);
  item_reg->SetAccess(2,ACCESSMODE_READ);
  GetItems().push_back(item_reg);

  // - add register VALUE_ACTIVE_ENERGY_NEGATIVE -
  item_reg = new CGXDLMSRegister("1.0.2.8.0.255",1.0,45,0.0);
  item_reg->SetAccess(2,ACCESSMODE_READ);
  GetItems().push_back(item_reg);

  // - add default clock: 0.0.1.0.0.255 -
  CGXDLMSClock* pClock = new CGXDLMSClock();
  GetItems().push_back(pClock);

  // - initialize server after all objects were added -
  ret = CGXDLMSServerBase::Initialize();
  if (ret != ERROR_CODES_OK)
  {
    return ret;
  }

  return ERROR_CODES_OK;
}/*}}}*/

int CGXDLMSBase::OnRead(CGXDLMSObject* pItem,int index,CGXDLMSVariant& value,DLMS_DATA_TYPE& type)
{/*{{{*/
  fprintf(stderr,"CGXDLMSBase::OnRead\n");

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
  std::string item_name = pItem->GetName().ToString();

  // FIXME debug output
  fprintf(stderr,"READ PAIR: %d - %s\n",value.vt,item_name.c_str());

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
    case DLMS_DATA_TYPE_FLOAT64:
      if (item_name == "1.0.1.8.0.255")
      {
        value = 100.0;
        return ERROR_CODES_OK;
      }
      else if (item_name == "1.0.2.8.0.255")
      {
        value = 100.0;
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
  fprintf(stderr,"CGXDLMSBase::OnWrite\n");

  return ERROR_CODES_FALSE;
}/*}}}*/

int CGXDLMSBase::OnAction(CGXDLMSObject* pItem,int index,CGXDLMSVariant& data)
{/*{{{*/
  fprintf(stderr,"CGXDLMSBase::OnAction\n");

  return ERROR_CODES_FALSE;
}/*}}}*/

int CGXDLMSBase::OnInvalidConnection()
{/*{{{*/
  fprintf(stderr,"CGXDLMSBase::OnInvalidConnection\n");

  return ERROR_CODES_OK;
}/*}}}*/

