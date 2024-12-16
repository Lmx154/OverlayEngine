#ifndef OPENXR_PROGRAM_H
#define OPENXR_PROGRAM_H

#include <openxr/openxr.h>
#include <string>

class OpenXRProgram {
public:
    OpenXRProgram();
    ~OpenXRProgram();

    bool CreateSession();  // Initialize OpenXR and say "Hello World"
    void Shutdown();       // Clean up resources

private:
    XrInstance xrInstance;
    bool InitializeOpenXR();
};

#endif // OPENXR_PROGRAM_H
