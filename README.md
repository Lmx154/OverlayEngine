
# **OpenXR Overlay Engine**

This project is a modular **overlay engine** designed for augmented reality (AR) on devices like the **Meta Quest 3**. It leverages the **OpenXR standard** to overlay dynamic functionality modules over AR passthrough.

---

## **Features**
- Initializes an OpenXR instance.
- Provides a framework for overlaying modular AR functionalities.
- Focuses on AR passthrough with OpenXR runtime compatibility.
- Lightweight and extensible for custom overlays.

---

## **Project Structure**

```plaintext
OpenXR-Overlay-Engine/
├── libs/                          # Third-party libraries
│   └── OpenXR-SDK/                # OpenXR headers and loader library
│       ├── include/               # OpenXR headers (e.g., openxr.h)
│       └── lib/                   # OpenXR loader library
├── src/                           # Source code
│   └── main.cpp                   # Application entry point
├── CMakeLists.txt                 # Build configuration
├── build/                         # Build artifacts (ignored in version control)
└── README.md                      # Project documentation
```

---

## **Prerequisites**
- **OpenXR Runtime**: Ensure a compatible runtime (e.g., Oculus or SteamVR) is installed.
- **CMake**: To configure and build the project.
- **Meta Quest 3** (or compatible XR device) with Developer Mode enabled.
- **Android Studio** (for Android builds, optional).

---

## **Build Instructions**

### **1. Clone the Repository**
```bash
git clone https://github.com/yourusername/OpenXR-Overlay-Engine.git
cd OpenXR-Overlay-Engine
```

### **2. Set Up OpenXR SDK**
- Copy OpenXR headers into `libs/OpenXR-SDK/include/`.
- Copy the OpenXR loader library into `libs/OpenXR-SDK/lib/`.

### **3. Build the Project**
Using **CMake**:
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

---

## **Run the Project**
- On desktop, run the built executable:
   ```bash
   ./Release/OpenXROverlay.exe
   ```
- For **Quest 3**, deploy via Android Studio using ADB.

---

## **License**
This project is licensed under the **MIT License**.
