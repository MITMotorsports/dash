#ifndef RTD_HANDLER_H
#define RTD_HANDLER_H

#include "Handler.h"
#include "Can_Controller.h"

const int RTD_BUTTON = 6;

class Rtd_Handler : public Handler {
  public:
    void begin();
    void handleMessage(Frame& message);
};

#endif // RTD_HANDLER_H
