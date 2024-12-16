#include "openxr_program.h"
#include <iostream>
#include <cstring>

OpenXRProgram::OpenXRProgram() : xrInstance(XR_NULL_HANDLE) {}

OpenXRProgram::~OpenXRProgram() {
    Shutdown();
}

bool OpenXRProgram::CreateSession() {
    std::cout << "Initializing OpenXR..." << std::endl;
    if (!InitializeOpenXR()) {
        std::cerr << "Failed to initialize OpenXR instance." << std::endl;
        return false;
    }

    std::cout << "Hello World from OpenXR!" << std::endl;
    return true;
}

bool OpenXRProgram::InitializeOpenXR() {
    // Initialize OpenXR instance
    XrInstanceCreateInfo createInfo = {};
    createInfo.type = XR_TYPE_INSTANCE_CREATE_INFO;
    std::strcpy(createInfo.applicationInfo.applicationName, "HelloXR");
    createInfo.applicationInfo.applicationVersion = 1;
    createInfo.applicationInfo.apiVersion = XR_CURRENT_API_VERSION;

    XrResult result = xrCreateInstance(&createInfo, &xrInstance);
    if (result != XR_SUCCESS) {
        std::cerr << "xrCreateInstance failed. Error code: " << result << std::endl;
        return false;
    }

    std::cout << "OpenXR instance created successfully!" << std::endl;
    return true;
}

void OpenXRProgram::Shutdown() {
    if (xrInstance != XR_NULL_HANDLE) {
        xrDestroyInstance(xrInstance);
        xrInstance = XR_NULL_HANDLE;
    }
    std::cout << "OpenXR instance destroyed." << std::endl;
}
