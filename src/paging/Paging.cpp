#include "paging/Paging.h"
#include <iostream>
#include <filesystem>

typedef PagingAlgorithm* (*AlgorithmConstructor)();
typedef void (*AlgorithmDestructor)(PagingAlgorithm*);

#ifdef _WIN32
#include <windows.h>
PagingAlgorithm* loadDLL(const std::string& dllPath) {
    HINSTANCE dllInstance = LoadLibrary(dllPath.c_str());
    if (!dllInstance) {
        std::cerr << "Failed to load dll: " << dllPath << std::endl;
        return nullptr;
    }

    auto createAlgorithm = (AlgorithmConstructor) GetProcAddress(dllInstance, "createAlgorithm");

    PagingAlgorithm* pagingAlgorithm = createAlgorithm();
    return pagingAlgorithm;
}
#elif __linux__
#include <dlfcn.h>
PagingAlgorithm* loadDLL(const std::string& dllPath) {
    void* dllHandle = dlopen(dllPath.c_str(), RTLD_LAZY);
    if (!dllHandle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        return nullptr;
    }

    dlerror();

    const auto createAlgorithm = (AlgorithmConstructor)(dlsym(dllHandle, "createAlgorithm"));

    if (char* dllErr = dlerror(); !dllErr) {
        std::cerr << "Cannot open library: " << dllErr << std::endl;
        return nullptr;
    }

    PagingAlgorithm* pagingAlgorithm = createAlgorithm();
    return pagingAlgorithm;
}
#endif

PagingAlgorithm* Paging::instantiatePagingAlgorithm(const std::string& dllPath) {
    if (!std::filesystem::exists(dllPath)) {
        std::cerr << "File at " << dllPath << " not found" << std::endl;
        return nullptr;
    }

    return loadDLL(dllPath);
}

void Paging::processReferenceString(Tiles &tiles, ReferenceStringReader &reader, PagingAlgorithm &pagingAlgorithm) {
    return;
}
