#include "ReconBase.h"

class ReconHelical : public ReconBase{
public:
    ReconHelical(int slice, std::string& path) : ReconBase(slice, path) {}

protected:
    void SetGeomtryInfo() override {
        std::cout << "Step 4 (overrided): Set Geomtry for Helical Recon" << std::endl;
    }

    virtual void CreateAgent() override {
        std::cout << "Step 5 (overrided): Create Agent" << std::endl;
        std::cout << "\tCreate Prep Agent" << std::endl;
        std::cout << "\tCreate Fixframe Agent" << std::endl;
        std::cout << "\tCreate Rebin Agent" << std::endl;
        std::cout << "\tCreate BP Agent" << std::endl;
        std::cout << "\tCreate Bone Correction Agent" << std::endl;
    };
};