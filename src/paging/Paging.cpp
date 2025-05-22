#include "paging/Paging.h"
#include <iostream>
#include <filesystem>

typedef PagingAlgorithm* (*AlgorithmConstructor)();
typedef void (*AlgorithmDestructor)(PagingAlgorithm*);

#ifdef _WIN32
#include <windows.h>
PagingAlgorithm* loadDLL(std::string dllPath) {
    HINSTANCE dllInstance = LoadLibrary(dllPath.c_str());
    if (!dllInstance) {
        std::cerr << "Failed to load dll: " << dllPath << std::endl;
        return nullptr;
    }

    auto createAlgorithm = (AlgorithmConstructor)GetProcAddress(dllInstance, "createAlgorithm");

    PagingAlgorithm* pagingAlgorithm = createAlgorithm();
    return pagingAlgorithm;
}
#endif

PagingAlgorithm* Paging::instantiatePagingAlgorithm(std::string dllPath) {
    if (!std::filesystem::exists(dllPath)) {
        std::cerr << "File at " << dllPath << " not found" << std::endl;
        return nullptr;
    }

    return loadDLL(dllPath);
}
