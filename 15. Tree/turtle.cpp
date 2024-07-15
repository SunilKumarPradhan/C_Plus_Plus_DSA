#include <Windows.h>
#include <string>

// Function to update the window title with current time
void UpdateTime(HWND hwnd) {
    // Get current time
    SYSTEMTIME time;
    GetLocalTime(&time);

    // Format time into a string
    std::string timeStr = std::to_string(time.wHour) + ":" +
                          (time.wMinute < 10 ? "0" : "") + std::to_string(time.wMinute) + ":" +
                          (time.wSecond < 10 ? "0" : "") + std::to_string(time.wSecond);

    // Update window title with current time
    SetWindowTextA(hwnd, timeStr.c_str());
}

// Window procedure function
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            // Set timer to update time every second
            SetTimer(hwnd, 1, 1000, nullptr);
            break;
        case WM_TIMER:
            // Update time on timer tick
            UpdateTime(hwnd);
            break;
        case WM_DESTROY:
            // Clean up and exit
            KillTimer(hwnd, 1);
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// Entry point of the application
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Register window class
    const char* CLASS_NAME = "SimpleClockWindow";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    // Create window
    HWND hwnd = CreateWindowEx(0, CLASS_NAME, "Simple Clock", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 300, 100,
                               nullptr, nullptr, hInstance, nullptr);
    if (hwnd == nullptr) {
        return 0;
    }

    // Show window
    ShowWindow(hwnd, nCmdShow);

    // Message loop
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
