#include "ReconBase.h"

class ReconScout : public ReconBase{
public:
    ReconScout(int slice, std::string& path) : ReconBase(slice, path) {}

protected:
    void SetGeomtryInfo() override {
        std::cout << "Step 4 (overrided): Set Geomtry for Scout Recon" << std::endl;
    }
};