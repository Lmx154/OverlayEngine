#include <openxr/openxr.h>
#include <iostream>
#include <cstring>

int main() {
    // Prepare instance creation info
    XrInstanceCreateInfo createInfo = {};
    createInfo.type = XR_TYPE_INSTANCE_CREATE_INFO;
    std::strcpy(createInfo.applicationInfo.applicationName, "OverlayEngine");
    createInfo.applicationInfo.applicationVersion = 1;
    std::strcpy(createInfo.applicationInfo.engineName, "CustomEngine");
    createInfo.applicationInfo.engineVersion = 1;
    createInfo.applicationInfo.apiVersion = XR_CURRENT_API_VERSION;

    // Create instance
    XrInstance instance;
    XrResult result = xrCreateInstance(&createInfo, &instance);

    // Debug output
    if (result == XR_SUCCESS) {
        std::cout << "OpenXR instance created successfully!" << std::endl;
    } else {
        std::cerr << "Failed to create OpenXR instance. Error code: " << result << std::endl;
    }

    if (result == XR_ERROR_RUNTIME_FAILURE) {
        std::cerr << "OpenXR runtime might not be configured correctly." << std::endl;
    }

    if (instance) {
        xrDestroyInstance(instance);
    }

    return 0;
}
