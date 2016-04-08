#ifndef CAN_CONTROLLER_H
#define CAN_CONTROLLER_H

#include <mcp_can.h>

const int MCP_INT = 2;
const int MCP_CS = 53;

typedef struct Frame {
  unsigned int id;
  unsigned char body[8];
} Frame;

class Can_Controller {
  public:
    static Can_Controller& getInstance();
    void begin();
    bool msgAvailable();
    Frame read();
    void write(Frame frame);
  private:
    //MCP_CAN has no default constructor
    MCP_CAN delegate = MCP_CAN(MCP_CS);
    Can_Controller();
    static Can_Controller *instance;
    bool begun;
    String canResponseToString(uint8_t result);
};

// Singleton accessor declaration
Can_Controller& CAN();

#endif //CAN_CONTROLLER_H
