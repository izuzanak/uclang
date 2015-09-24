
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

class CGXDLMSBase : public CGXDLMSServerBase,IGXMediaListener,IGXNetListener
{
  public:
  CGXNet m_Media;

  // - constructor -
  CGXDLMSBase(bool UseLogicalNameReferencing = true,
              GXDLMS_INTERFACETYPE IntefaceType = GXDLMS_INTERFACETYPE_GENERAL,
              unsigned short MaxReceivePDUSize = 0xFFFF) :
              CGXDLMSServerBase(UseLogicalNameReferencing,
              IntefaceType,0xFFFF)
  {
  }

  // - destructor -
  virtual ~CGXDLMSBase(void)
  {
    m_Media.Close();
  }

  int Init(int port);
  int OnRead(CGXDLMSObject* pItem,int index,CGXDLMSVariant& value,DLMS_DATA_TYPE& type);
  int OnWrite(CGXDLMSObject* pItem,int index,int selector,CGXDLMSVariant& value);
  int OnAction(CGXDLMSObject* pItem,int index,CGXDLMSVariant& data);
  int OnInvalidConnection();

  // - called when client has been disconnected -
  void OnClientConnected(IGXMedia* pSender,CConnectionEventArgs& e)
  {
    fprintf(stderr,"Client Connected : %s\r\n",e.GetInfo().c_str());
  }

  // - called when client has been disconnected -
  void OnClientDisconnected(IGXMedia* pSender,CConnectionEventArgs& e)
  {
    fprintf(stderr,"Client Disonnected : %s\r\n",e.GetInfo().c_str());
  }

  // - called on error -
  void OnError(IGXMedia* pSender,basic_string<char>& ex)
  {
    fprintf(stderr,"Error has occurred : %s\r\n",ex.c_str());
  }

  // - called when media component receives data -
  void OnReceived(IGXMedia* pSender,CReceiveEventArgs& e)
  {
    unsigned char* pReply = NULL;
    int size = 0;
    fprintf(stderr,"<- %s\r\n",GXHelpers::bytesToHex(&e.getData()[0],e.getData().size()).c_str());

    HandleRequest(e.getData(),pReply,size);

    // - reply is null if we do not want to send any data to the client -
    if (size != 0)
    {
      fprintf(stderr,"-> %s\r\n",GXHelpers::bytesToHex(pReply,size).c_str());
      m_Media.Send(pReply,size,e.getSenderInfo());
    }
  }

  // - called when media state changes -
  void OnMediaStateChange(IGXMedia* pSender,CMediaStateEventArgs& e)
  {
    fprintf(stderr,"CGXDLMSBase::OnMediaStateChange\n");
  }

  // - called when the Media is sending or receiving data -
  void OnTrace(IGXMedia* pSender,CTraceEventArgs& e)
  {
    fprintf(stderr,"%s\r\n",e.ToString().c_str());
  }

  // - called when property is changed on a component -
  void OnPropertyChanged(IGXMedia* pSender,CPropertyChangedEventArgs& e)
  {
    fprintf(stderr,"CGXDLMSBase::OnPropertyChanged\n");
  }
};

#endif

