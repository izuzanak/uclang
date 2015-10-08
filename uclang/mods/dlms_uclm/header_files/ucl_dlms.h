
#ifndef __UCL_DLMS_H
#define __UCL_DLMS_H

@begin
include "script_parser.h"
@end

#include <poll.h>
#include <string>
#include <vector>
using namespace std;

#include "GXNet.h"
#include "GuruxCommon/GXMediaListener.h"
#include "GuruxDLMS/GXDLMSServerBase.h"

#include "GuruxDLMS/Objects/GXDLMSRegister.h"

class CGXDLMSBase : public CGXDLMSServerBase,IGXMediaListener,IGXNetListener
{/*{{{*/
  public:
  CGXNet m_Media;

  // - constructor -
  CGXDLMSBase(bool UseLogicalNameReferencing = true,
              GXDLMS_INTERFACETYPE IntefaceType = GXDLMS_INTERFACETYPE_GENERAL,
              unsigned short MaxReceivePDUSize = 0xFFFF) :
              CGXDLMSServerBase(UseLogicalNameReferencing,
              IntefaceType,0xFFFF)
  {/*{{{*/
  }/*}}}*/

  // - destructor -
  virtual ~CGXDLMSBase(void)
  {/*{{{*/
    m_Media.Close();
  }/*}}}*/

  int PrepareInit(string a_man_id,string a_serial,int a_port);
  int Init();
  int OnRead(CGXDLMSObject* pItem,int index,CGXDLMSVariant& value,DLMS_DATA_TYPE& type);
  int OnWrite(CGXDLMSObject* pItem,int index,int selector,CGXDLMSVariant& value);
  int OnAction(CGXDLMSObject* pItem,int index,CGXDLMSVariant& data);
  int OnInvalidConnection();

  // - called when client has been disconnected -
  void OnClientConnected(IGXMedia* pSender,CConnectionEventArgs& e)
  {/*{{{*/
  }/*}}}*/

  // - called when client has been disconnected -
  void OnClientDisconnected(IGXMedia* pSender,CConnectionEventArgs& e)
  {/*{{{*/
  }/*}}}*/

  // - called on error -
  void OnError(IGXMedia* pSender,basic_string<char>& ex)
  {/*{{{*/
  }/*}}}*/

  // - called when media component receives data -
  void OnReceived(IGXMedia* pSender,CReceiveEventArgs& e)
  {/*{{{*/
    unsigned char* pReply = NULL;
    int size = 0;

    HandleRequest(e.getData(),pReply,size);

    // - reply is null if we do not want to send any data to the client -
    if (size != 0)
    {
      m_Media.Send(pReply,size,e.getSenderInfo());
    }
  }/*}}}*/

  // - called when media state changes -
  void OnMediaStateChange(IGXMedia* pSender,CMediaStateEventArgs& e)
  {/*{{{*/
  }/*}}}*/

  // - called when the Media is sending or receiving data -
  void OnTrace(IGXMedia* pSender,CTraceEventArgs& e)
  {/*{{{*/
  }/*}}}*/

  // - called when property is changed on a component -
  void OnPropertyChanged(IGXMedia* pSender,CPropertyChangedEventArgs& e)
  {/*{{{*/
  }/*}}}*/
};/*}}}*/

/*
 * definition of structure dlms_object_s
 */

struct dlms_object_s
{
  location_s *dlmss_ptr;
  unsigned index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure dlms_object_s
 */

inline void dlms_object_s::init()
{/*{{{*/
  dlmss_ptr = NULL;
}/*}}}*/

inline void dlms_object_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (dlmss_ptr != NULL)
  {
    it.release_location_ptr(dlmss_ptr);
  }

  init();
}/*}}}*/

#endif

