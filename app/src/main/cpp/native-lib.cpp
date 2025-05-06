#include <vulkan/vulkan.h>
#include <android/native_window.h>
#include <android/log.h>
#include <stdio.h>

// Debugging macro
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-lib", __VA_ARGS__))

// Vulkan Instance, Device, etc.
VkInstance instance;
VkDevice device;
VkSwapchainKHR swapchain;
VkRenderPass renderPass;
VkPipeline graphicsPipeline;
VkCommandPool commandPool;
VkQueue graphicsQueue;
VkQueue presentQueue;
VkPhysicalDevice physicalDevice;
VkSurfaceKHR surface;
VkDescriptorPool descriptorPool;

// Swapchain creation
void createSwapchain() {
    // Specify swapchain creation info...
}

// Vulkan device and surface creation
void initVulkan(ANativeWindow* window) {
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "RPCSX Emulator";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "RPCSX";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_3;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // Load extensions and create the Vulkan instance
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = nullptr;
    glfwExtensions = (const char**)glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledExtensionCount = glfwExtensionCount;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        LOGI("Vulkan instance creation failed!");
        return;
    }

    // Create surface for Vulkan
    VkAndroidSurfaceCreateInfoKHR surfaceCreateInfo = {};
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    surfaceCreateInfo.window = window;
    if (vkCreateAndroidSurfaceKHR(instance, &surfaceCreateInfo, nullptr, &surface) != VK_SUCCESS) {
        LOGI("Surface creation failed!");
        return;
    }

    // Select physical device (GPU)
    uint32_t deviceCount = 0;
    vkEnumerate

}
